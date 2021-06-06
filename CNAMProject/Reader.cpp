#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;




#define INFINITE_WAIT_TIME 0

#define DEFAULT_PROMPT_MESSAGE "Enter your file path: "


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
	string imagePath = getPathFromUser();
	Mat image = openImage(imagePath);

	if (isValid(image)) {
		cout << "Could not read the image from the specified path : " << imagePath << std::endl;
		return EXIT_FAILURE;
	}

	cout << "Reading the image from the specified path : " << imagePath << std::endl;

	showImage(image);

	return EXIT_SUCCESS;
}
