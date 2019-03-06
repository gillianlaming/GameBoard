#pragma once
#include "GamePieces.h"
#include "GameBoard.h"
#include <iomanip>
#include <ctype.h>
#include <vector>




class TicTacToeGame {
	friend ostream & operator<<(ostream & output, const TicTacToeGame & newGame);
private:
	
	vector<game_piece> game_board; 
	//game_piece myPiece;//game piece either an X or O
	
	//initialize board so that outer squares always stay empty
	
public:
	//vector<game_piece> game_board;
	bool done();
	bool draw();
	int prompt(unsigned int& xCoord, unsigned int& yCoord); //use cin
	int turn();
	int play();
};

//vector<game_piece> game_board(25);
ostream & operator<<(ostream & output, const TicTacToeGame & newGame);

