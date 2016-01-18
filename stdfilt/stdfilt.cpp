/*
	Name: Pavani Tripahi
	MATLAB Function: stdfilt

	input: 
		an image (Please enter the correct path in the code)
	
	output:
		an image showing the local standard deviation of each pixel
		integer to select no of arguments
		integers indicating neighbourhood etc.

	Example:
		case 1:
			Directly an output image will be shown
		case 2:
			Enter the dimensions of the neighbourhood
			Accordingly the output will appear on the screen
		case 3:
			Enter the dimensions and the kind of padding to be done
			Accordingly the output will appear on the screen
		
	References:
		OpenCV documentation for the function blur and normalize
*/

//stdafx.h header file is required to run code in VisualStudio 
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace std;
using namespace cv;

Mat mat2gray(const Mat& src)	//normalises the floating points
{
	Mat dst;
	normalize(src, dst, 0.0, 1.0, NORM_MINMAX);
	return dst;
}

int main()
{
	//image stores the input image.
	//Kindly change the path specified according to your needs
	Mat image = imread("G:\\PavaniNew\\IIIT DELHI\\5th Semester\\IA\\standard_test_images\\cameraman.tif", CV_LOAD_IMAGE_GRAYSCALE);
	
	//Result is the output image
	Mat Result;

	int ans;

	cout << "--MENU--" << endl;
	cout << "1. Press 1 to use standard function" << endl;
	cout << "2. Press 2 if you wish to specify the neighbourhood" << endl;
	cout << "3. Press 3 if you wish to specify neighbourhood and padding" << endl;
	cin >> ans;

	Mat image32f;
	image.convertTo(image32f, CV_32F);

	//We know that standard deviation = sqrt(E[X.^2] - (E[X]).^2)
	//One can think of blur function as the expected mean value of the neighbourhood specified.
	//The pixel values at each point of the image represents the random sampl value X.
	//Thus, one can calculate standard deviation as:
	// sigma = sqrt(blur(image.^2) - (blur(image)).^2)
	switch (ans)
	{
	case 1: {
		Mat blurr1, blurr2;
		blur(image32f, blurr1, Size(3, 3), Point(-1, -1), BORDER_CONSTANT);
		blur(image32f.mul(image32f), blurr2, Size(3, 3), Point(-1, -1), BORDER_CONSTANT);
	
		sqrt(blurr2 - blurr1.mul(blurr1), Result);
	}
	case 2: {
		//Size of the neighbourhood for calculating the local standard deviation is now user defined and is equal to MxN
		int m, n;
		cout << "Enter the no of rows in the neighbourhood: ";
		cin >> m;
		cout << "\nEnter the no of cols in the neighbourhood: ";
		cin >> n;

		Mat blurr1, blurr2;
		blur(image32f, blurr1, Size(m, n), Point(-1, -1), BORDER_CONSTANT);
		blur(image32f.mul(image32f), blurr2, Size(m, n), Point(-1, -1), BORDER_CONSTANT);

		sqrt(blurr2 - blurr1.mul(blurr1), Result);
	}
	case 3: {
		int m, n;
		char y;
		cout << "Enter the no of rows in the neighbourhood: ";
		cin >> m;
		cout << "\nEnter the no of cols in the neighbourhood: ";
		cin >> n;
		
		cout << "\nPress c for contant padding";
		cout << "\nPress r for symmetric padding";
		cout << "\nPress d for default padding";
		cin >> y;

		int borderType;

		if (y == 'c')
			borderType = BORDER_CONSTANT;
		else if (y == 'r')
			borderType = BORDER_REPLICATE;
		else
			borderType = BORDER_DEFAULT;

		Mat blurr1, blurr2;
		blur(image32f, blurr1, Size(m, n), Point(-1, -1), borderType);
		blur(image32f.mul(image32f), blurr2, Size(m, n), Point(-1, -1), borderType);

		sqrt(blurr2 - blurr1.mul(blurr1), Result);
	}
	}			 

	//Displays the result
	cvStartWindowThread();
	cvNamedWindow("Result");
	imshow("Result", mat2gray(Result));
	waitKey(0);
	cvDestroyAllWindows();

	return 0;
}

