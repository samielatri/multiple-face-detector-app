/* circle.cpp */

#include "circle.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;


/*
 *	return radius from passed diameter.
 */
int getRadius(int diameter) {
	return diameter / 2 + diameter % 2;
}

/* 
 *	put characterstics of circle in circleCenter and circleRadius. 
 */
void getCircleCharacteristics(Rect** face, Point circleCenter, int* circleRadius) {
	Point topLeftPoint = (*face)->tl();
	Point bottomRightPoint = (*face)->br();
	circleCenter = Point(topLeftPoint.x + (*face)->height / 2, bottomRightPoint.y + (*face)->width / 2);
	int diameter = getDistanceBetweenTwoPoints(topLeftPoint, circleCenter);
	*circleRadius = getRadius(diameter);
}

/*
 *	draw circle for face in image.
 */
void drawCircle(Mat** image, Rect* face) {
	Point circleCenter;
	int circleRadius;
	getCircleCharacteristics(&face, circleCenter, &circleRadius);
	circle(**image, circleCenter, circleRadius, Scalar(CIRCLE_RGB_COLOR), CIRCLE_THICKNESS);
}

/*
 *	draw circles for all faces in image.
 */
size_t drawCircles(Mat* image, vector<Rect> faces) {
	size_t numberOfFaces = faces.size();
	for (size_t i = 0; i < numberOfFaces; i++) {
		drawCircle(&image, &(faces[i]));
	}
	return numberOfFaces;
}

/*
 *	return distance between two points passed in parameters
 */
int getDistanceBetweenTwoPoints(Point point1, Point point2) {
	return (int)sqrt((pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)));
}

/* end of circle.cpp */
