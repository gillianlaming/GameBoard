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

vector<game_piece> game_board;

ostream & operator<<(ostream & output, const TicTacToeGame & newGame ) {
	//look thru board, for each piece add it's display to the output
	for (int r = 0; r < 5; r++) { //not sure if 
		for (int c = 0; c < 5; c++) {
			output << newGame.game_board[(5*c)+r].display;
			
		}
		output << endl;
	}
	
	return output;
}

bool done() { //fix this
	int options[8][3] = { {6,7,8},{11,12,13},{16,17,18},{6,11,16},{17,12,7},{18,13,8},{16,12,8},{18,12,6}};
	for (int i = 0; i < 8; i++) {
		if (game_board[options[i][0]].display == game_board[options[i][1]].display && game_board[options[i][1]].display == game_board[options[i][2]].display) {
			return true;
		}
	}
	return false;
}

bool draw() {
	if (done()) {
		return false;
	}
	for (int i = 0; i < game_board.size(); i++) {
		if (game_board[i].color != border && game_board[i].display == " ")
	}
}