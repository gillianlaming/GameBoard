#pragma once
#include "GameBoard.h"
#include "GamePieces.h"
#include <iomanip>
#include <ctype.h>
#include <vector>
#include "Header.h"


class TicTacToeGame {
	friend ostream & operator<<(ostream &, const TicTacToeGame &);
private:
	
	vector<game_piece> game_board; 
	//game_piece myPiece;//game piece either an X or O
	
	//initialize board so that outer squares always stay empty
	
public:
	bool done();
	bool draw();
	int prompt(unsigned int& xCoord, unsigned int& yCoord); //use cin
	int turn();
	int play();
};


ostream & operator<<(ostream & output, const TicTacToeGame & newGame);

