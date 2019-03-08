   #pragma once
#include <string>
using namespace std;


//edited 
//enum definition
enum piece_color { red, black, white, invalidColor, noColor, border };

//function definitons
piece_color whatColor(string color);
int lowerCaseMe(string & uppercaseString);
string noName(piece_color color);


//struct definition
struct game_piece {

	string name; 
	piece_color color;
	string display;
};