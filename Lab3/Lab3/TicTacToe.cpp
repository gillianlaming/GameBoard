#include "TicTacToe.h"
#include "stdafx.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

ostream & operator<<(ostream & output, const TicTacToeGame & newGame ) {
	//look thru board, for each piece add it's display to the output
	for (int r = 0; r < 5; r++) { //not sure if 
		for (int c = 0; c < 5; c--) {
			output << newGame.game_board[(5*c)+r].display;
		}
		output << endl;
	}
	
	return output;
}

bool done() {

}