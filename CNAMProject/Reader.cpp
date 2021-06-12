#include <iostream>
#include <stdlib.h>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include "rectangle.h"
#include "model.h"
#include "image.h"
#include "prompt.h"

using namespace std;
using namespace cv;

/*	<summary>
		get path from user
		return string representing the path
	</summary>
 */
string getPathFromUser() {
	string path;
	cout << DEFAULT_PROMPT_MESSAGE;
	cin >> path;
	return path;
}

/*	<summary>
		open image from the string path passed in parameter
		return Mat object representing the opened image
	</summary>
 */
Mat openImage(String imagePath) {
	return imread(imagePath);
}

/*	<summary>
		show image passed as a Mat object parameter
		return Mat object representing the opened image
	</summary>
 */
void showImage(Mat image) {
	imshow("image_display", image);
	waitKey(INFINITE_WAIT_TIME);
}

/*	<summary>
		verify if image is valid or not
		return true if image is valid, false if not
	</summary>
 */
bool isValid(Mat image) {
	return image.empty();
}

/*	<summary>
		main entry of the program
	</summary>
 */
int main(void) {
	bool shutDownProgram = false;
	do {
		bool imageIsValid;
		do {
			string imagePath = getPathFromUser();
			Mat image = openImage(imagePath);

			imageIsValid = isValid(image);

			if (imageIsValid) {
				cout << "Image read successfully from the specified path : " << imagePath << endl;
			} else {
				cout << "Could not read the image from the specified path : " << imagePath << endl;
				cout << "try again !" << endl;
			}
		} while (!imageIsValid);

		cout << "Reading the image from the specified path : " << imagePath << endl;

		Mat imageResized;

		cout << "resizing the image ..."
		cout << "image original size : " << endl;
		cout << image.size() << endl;

		resize(
			image,
			imageResized,
			Size(),
			X_SCALING_FACTOR,
			Y_SCALING_FACTOR
		);

		cout << "image size after resize : " << endl;
		cout << image.size() << endl;

		cout << "processing for face detection..." << endl;

		CascadeClassifier faceCascade;
		faceCascade.load(FACE_DEFINITION);
		
		if (faceCascade.empty()) {
			cout << "xml file not loaded proprely" << endl;
			exit(EXIT_FAILURE);	// stdlib.h
		}

		vector<Rect> faces;
		faceCascade.detectMultiScale(imageResized, faces);

		int numberOfFaces = faces.size();

		cout << "number of faces detected : " << numberOfFaces << endl;

		cout << "processing for drawing rectangles on faces..." << endl;
		for (int i = 0; i < numberOfFaces; i++) {
			// define top left point coordinates of rectangle
			int topLeftPointX = faces[i].x;
			int topLeftPointY = faces[i].y;
			// define bottom right coordinates of rectangle (position relative to top left point coordinates)
			int bottomRightPointX = topLeftPointX + faces[i].height;
			int bottomRightPointY = topLeftPointY + faces[i].width;		
			// define top left point of rectangle
			Point topLeftPoint(topLeftPointX, topLeftPointY);	// faces[i].tl()
			// define bottom right point of rectangle
			Point bottomRightPoint(bottomRightPointX, bottomRightPointY);	// faces[i].br()
			rectangle(
				imageResized,
				topLeftPoint,
				bottomRightPoint,
				Scalar(RECTANGLE_RGB_COLOR),
				RECTANGLE_THICKNESS,
				RECTANGLE_LINE_TYPE,
				RECTANGLE_SHIFT
			);
		}

		cout << "showing image..." << endl;
		cout << "Press any key to close the image's window..." << endl;

		showImage("multiple face detector app", imageResized);

		cout << "image shown" << endl;

		cout << "outputing image to file..." << endl;

		iwrite(OUTPUT_FILE, imageResized);

		cout << "image outputed successfully !" << endl;

		char* quitKey = "q"; 
		cout << "Press q to exit the program or any key to process another image" << endl;
		cin >> userChoice;
		if(strcmp(userChoice, quitKey) == 0) {
			cout << "exiting program..." << endl;
			shutDownProgram = true;
		} else {
			cout << "let's go for another image face detection !" << endl;	
		}
	} while(!shutDownProgram);
	
	return EXIT_SUCCESS;	// stdlib.h
}
