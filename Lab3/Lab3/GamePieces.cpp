#include "stdafx.h"
#include "Header.h"
#include "string"
#include "GamePieces.h"
using namespace std;


int lowerCaseMe(string & uppercaseString) {
	//modifies that string so that all of the alphabetic characters in it become lowercase
	for (char& c : uppercaseString) { //iterate char by char thru string
		if (isupper(c)) {

			char d = tolower(c); //convert the character to lowercase
			c = d; //replace the uppercase string w lowercase string
		}
	}
	return success;

}

string noName(piece_color color)
{
	int val = color;
	string enumColors[] = { "red", "black", "white", "invalidColor", "noColor" }; //all the enum vals
	return enumColors[val]; //return string at array element of the piece_color
}

piece_color whatColor(string color) 
{
	//this is so inefficient. is there a better way?
	if (color == "red") {
		return red;
	}
	if (color == "black") {
		return black;
	}
	if (color == "white") {
		return white;
	}
	if (color == " ") { //how to handle any string containing only whitespace?
		return noColor;
	}
	else {
		return invalidColor;
	}
}


