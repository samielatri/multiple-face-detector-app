/* model.h */

#ifndef _MODEL_H_
#define _MODEL_H_

#ifdef __unix__         
	#define FACE_DEFINITION "Resources/model/haarcascade_frontalface_default.xml"
#elif defined(_WIN32) || defined(WIN32) 
	#define FACE_DEFINITION "Resources\\model\\haarcascade_frontalface_default.xml"
#endif /* __unix__ */

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

/*
 *	initialize face classifier.
 *  return true if initialized, false if not.
 */
bool initializeFaceClassifier(CascadeClassifier* faceCascade);

/*
 *	detected faces and put them in faces.
 */
void detectFaces(Mat* image, vector<Rect> faces, CascadeClassifier faceCascade);

/*
 *	return number of faces.
 */
size_t getNumberOfFaces(vector<Rect> faces);

/*
 *  convert the copy of image to grayscale and return it.
 */
Mat getGrayScaleImage(Mat image);

#endif  /* _MODEL_H_ */

/* end of model.h */