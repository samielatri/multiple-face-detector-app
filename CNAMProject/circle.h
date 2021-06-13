/* circle.h */

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#define CIRCLE_THICKNESS 2
#define CIRCLE_RGB_COLOR 0, 255, 0

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;


/*
 *	return radius from passed diameter.
 */
int getRadius(int diameter);

/*
 *	put characterstics of circle in circleCenter and circleRadius.
 */
void getCircleCharacteristics(Rect** face, Point* circleCenter, int* circleRadius);

/*
 *	draw circle for face in image.
 */
void drawCircle(Mat** image, Rect* face);

/*
 *	draw circles for all faces in image.
 */
size_t drawCircles(Mat* image, vector<Rect> faces);

/*
 *	return distance between two points passed in parameters
 */
int getDistanceBetweenTwoPoints(Point point1, Point point2);

#endif  /* _CIRCLE_H_ */

/* end of circle.h */
