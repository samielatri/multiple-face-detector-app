/* main.cpp */

/* std C++ headers include */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

/* std C headers include */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* OpenCV headers include */
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

/* custom headers include */
#include "circle.h"
#include "model.h"
#include "image.h"
#include "prompt.h"
#include "image.h"

/* name spaces */
using namespace std;
using namespace cv;



/*
 *	main entry of the program
 */
int main(void) {
	CascadeClassifier faceCascade;

	if (!initializeFaceClassifier(&faceCascade)) {
		cout << "xml model file not loaded proprely" << endl;
		exit(EXIT_FAILURE);	// stdlib.h
	} else {
		cout << "Welcome to Face detection App" << endl;
	}

	do {
		bool imageIsValid;
		bool pathIsNotImage;

		Mat image;
		string imagePath;

		do {
			do {
				imagePath = getImagePathFromUser();
				pathIsNotImage = !isPathImage(imagePath);
				if (pathIsNotImage) {
					cout << "The specified path is not a .jpg file : " << imagePath << "\ntry again !" << endl;
				}
			} while (pathIsNotImage);

			image = openImage(imagePath);
			imageIsValid = isValidImage(image);

			if (imageIsValid) {
				cout << "Image read successfully from the specified path : " << imagePath << endl;
			} else {
				cout << "Could not read the image from the specified path : " << imagePath << endl;
			}
		} while (!imageIsValid);

		vector<Rect> faces;
		detectFaces(image, &faces, faceCascade);
		cout << "number of faces detected : " << drawCircles(&image, faces) << endl;
		showImage(&image);
	} while(getRepeat());

	cout << "exiting program..." << endl;

	return EXIT_SUCCESS;	// stdlib.h
}

/* end of main.cpp */
