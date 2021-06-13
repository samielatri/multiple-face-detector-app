/* prompt.cpp */

#include <iostream>
#include <string>
#include <algorithm>

#include "prompt.h"

using namespace std;

/*	
 *	get path from user
 *	return string representing the path
 */
string getImagePathFromUser() {
	string path;
	cout << "Enter your file path (file need to have .jpg extension) : " << endl;
	cin >> path;
	return path;
}

/*	
 * returns true if user wants to process another image, false if not.
*/
bool getRepeat() {
	string userChoice;
	do {
		cout << "Press 'q' to exit the program or 'r' to process another image" << endl;
		cin >> userChoice;
		if (userChoice == "q") {
			return false;
		}
		if (userChoice == "r") {
			cout << "let's go for another image face detection !" << endl;
			return true;
		}
		cout << "invalid entry please try again" << endl;
	} while (userChoice != "q" && userChoice != "r");
	return false;	// non reacheable code
}
/*
 * Checks if the filePath is a path to an image, a file that ends with .jpg.
 */
bool isPathImage(string filePath) {
	return endsWithCaseInsensitive(filePath, IMAGE_EXTENSION);
}

/*
 * Case Insensitive Implementation of endsWith().
 * It checks if the string 'mainStr' ends with given string 'toMatch'.
 * Returns true if it's the case, false if not.
 */
bool endsWithCaseInsensitive(string mainStr, string toMatch) {
	auto it = toMatch.begin();
	return mainStr.size() >= toMatch.size() &&
		all_of(next(mainStr.begin(), mainStr.size() - toMatch.size()), mainStr.end(), [&it](const char& c) {
		return tolower(c) == tolower(*(it++));
			});
}

/* end of  prompt.cpp */
