/* image.h */

#ifndef _IMAGE_H_
#define _IMAGE_H_

#define X_SCALING_FACTOR 0.5
#define Y_SCALING_FACTOR 0.5
#define INFINITE_WAIT_TIME 0

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

/*
 *	open image from the string path passed in parameter
 *	return Mat object representing the opened image
 */
Mat openImage(String imagePath);

/*
 *	show image passed as a Mat object parameter
 *	return Mat object representing the opened image
 */
void showImage(Mat image);

/*
 *	resize image passed by parameter.
 */
void resizeImage(Mat image);

/*
 *	return true if image is valid, false if not.
 */
bool isValidImage(Mat image);

#endif  /* _IMAGE_H_ */

/* end of image.h */
