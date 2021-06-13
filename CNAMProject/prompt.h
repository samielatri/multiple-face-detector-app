/* prompt.h */

#ifndef _PROMPT_H_
#define _PROMPT_H_

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define DEFAULT_PROMPT_MESSAGE "Enter your file path: "
#define IMAGE_EXTENSION ".jpg"

/*
 *	get path from user
 *	return string representing the path
 */
string getImagePathFromUser();
/*
 * returns true if user wants to process another image, false if not.
*/
bool getRepeat();
/*
 * Checks if the filePath is a path to an image, a file that ends with .jpg.
 */
bool isPathImage(string filePath);
/*
 * Case Insensitive Implementation of endsWith().
 * It checks if the string 'mainStr' ends with given string 'toMatch'.
 * Returns true if it's the case, false if not.
 */
bool endsWithCaseInsensitive(string mainStr, string toMatch);

#endif  /* _PROMPT_H_ */

/* end of prompt.h */