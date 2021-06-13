/* model.cpp */

#include "model.h"

using namespace std;
using namespace cv;

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/*
 *	initialize face classifier.
 *  return true if initialized, false if not.
 */
bool initializeFaceClassifier(CascadeClassifier* faceCascade) {
	(*faceCascade).load(FACE_DEFINITION);
	return !((*faceCascade).empty());
}

/*
 *	detected faces and put them in faces.
 */
void detectFaces(Mat* image, vector<Rect> faces, CascadeClassifier faceCascade) {
	Mat grayImage = getGrayScaleImage(*image);
	faceCascade.detectMultiScale(grayImage, faces);
}

/*
 *	return number of faces.
 */
size_t getNumberOfFaces(vector<Rect> faces) {
	return faces.size();
}

/*
 *  convert the copy of image to grayscale and return it.
 */
Mat getGrayScaleImage(Mat image) {
	Mat imageGray;
	cvtColor(image, imageGray, COLOR_BGR2GRAY);
	return imageGray;
}

/* end of model.cpp */
