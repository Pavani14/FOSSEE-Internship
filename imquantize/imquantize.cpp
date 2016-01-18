/*
	Name: Pavani Tripahi
	Function: stdfilt

	input: 
		an image (Please enter the correct path in the code)
		number of quantization levels
		various levels
	
	output:
		an image showing the local standard deviation of each pixel

	example:
		on console screen:
			Enter the no of quantization levels = 3
			level[0] = 12
			level[1] = 100
			level[2] = 200
		The result will be shown in the Result window.
	
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

Mat imquantize(Mat image, int levels[]);

int main()
{
	//image stores the input image.
	//Kindly change the path specified according to your needs
	Mat image = imread("G:\\PavaniNew\\IIIT DELHI\\5th Semester\\IA\\standard_test_images\\cameraman.tif", CV_LOAD_IMAGE_GRAYSCALE);

	//Result is the output image
	Mat Result = Mat::zeros(image.rows, image.cols, CV_8UC1);
	//levels indicate the thresholds to quantize the image
	int levels[100], n;

	cout << "\nHow many quantization levels do you wish to enter: ";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nlevel[" << i << "] :";
		cin >> levels[i];
	}

	Result = imquantize(image, levels);

	//Displays the result
	cvStartWindowThread();
	cvNamedWindow("Result");
	imshow("Result", Result);
	waitKey(0);
	cvDestroyAllWindows();

    return 0;
}

//This function converts the image into various levels according the number of levels/thresholds specified by the user
Mat imquantize(Mat image, int levels[])
{
	Mat Result = Mat::zeros(image.rows, image.cols, CV_8UC1);
	int n;
	n = sizeof(levels) / sizeof(levels[0]);

	for (int i = 0; i < image.rows; i++)
			for (int j = 0; j < image.cols; j++)
			{
				for (int k = 0; k < n; k++)
				{ 
					if (image.at<uchar>(i, j) <= levels[0])
						Result.at<uchar>(i, j) = 0;
					else if (image.at<uchar>(i, j) >= levels[n - 1])
						Result.at<uchar>(i, j) = 255;
					else
						if (image.at<uchar>(i, j) > levels[k] && image.at<uchar>(i, j) < levels[k + 1])
							Result.at<uchar>(i, j) = (k + 1) * 255 / sizeof(levels[0]);
				}
			}

	return Result;
}

