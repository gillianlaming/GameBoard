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
	
public:
	bool done();
	bool draw();
	int prompt(unsigned int& xCoord, unsigned int& yCoord); //use cin
	int turn();
	int play();
	bool player = true; //true -> X, false -> O
	string playerX;
	string playerO;
};
//enum players {X="x", O="o"};
//vector<game_piece> game_board(25);
ostream & operator<<(ostream & output, const TicTacToeGame & newGame);

struct player {
	string display;
	string moves;
};

