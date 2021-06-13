/* image.cpp */

#include "image.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;


/*	
 *	open image from the string path passed in parameter
 *	return Mat object representing the opened image
 */
Mat openImage(String imagePath) {
	return imread(imagePath);
}

/*	
 *	show image passed as a Mat object parameter
 *	return Mat object representing the opened image
 */
void showImage(Mat image) {
	resizeImage(image);
	imshow("image_display", image);
	waitKey(INFINITE_WAIT_TIME);
}

/*
 *	resize image passed by parameter.
 */
void resizeImage(Mat image) {
	resize(image, image, Size(), X_SCALING_FACTOR, Y_SCALING_FACTOR);
}

/*
 *	return true if image is valid, false if not. 
 */
bool isValidImage(Mat image) {
	return !(image.empty());
}

/* end of image.cpp */