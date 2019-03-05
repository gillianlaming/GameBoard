#pragma once
#include <string>
using namespace std;

//enum definition
enum piece_color { red, black, white, invalidColor, noColor };

//function definitons
piece_color whatColor(string color);
int lowerCaseMe(string & uppercaseString);
string noName(piece_color color);


//struct definition
struct game_piece {

	string name; //why doesn't it like this?
	piece_color color;
	string display;
};
