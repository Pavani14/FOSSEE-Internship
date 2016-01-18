Name: Pavani Tripathi
MATLAB function: stdfilt, imquantize
Files required: 
	1. stdfilt.cpp, imquatize.cpp
	2. openCV header files: highgui.hpp, core.hpp, imgproc.hpp
	3. C++ header files: iostream.h, conio.h, stdafx.h(to run it on VisualStudio 2015)

How to run the code on VisualStudio 2015:
	1. Create a new C++ project on VisualStudio 2015.
	2. To link openCV library do the following:
		* set Environment Variable 'OPENCV_DIR' as 'E:\Installed Soft\opencv\build\x64\vc12'
		* Add to System Path : '%OPENCV_DIR%\bin'
		* Project Properties -> C/C++ -> General -> Additional Include Directories : $(OPENCV_DIR)\..\..\include
		* Project Properties -> Linker -> General -> Addidtional Library Directories : $(OPENCV_DIR)\lib
		* Project Properties -> Linker -> Input -> Additional Dependencies :
			Add all the library files here.
	3. Open my stdfilt.cpp file in a text editor and copy the code in the space provided
	4. Change the path of the input image according to your choice (as indicated in the comments in the code)
	5. Run the code.
	6. Follow the instructions coming on the screen.


	
