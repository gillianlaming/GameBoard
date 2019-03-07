#pragma once
#include "GamePieces.h"
#include "GameBoard.h"
#include <iomanip>
#include <ctype.h>
#include <vector>


class TicTacToeGame {
	friend ostream & operator<<(ostream & output, const TicTacToeGame & newGame);
private:
	int rows;
	int cols;
	vector<game_piece> game_board; 
	
public:
	TicTacToeGame();
	bool done();
	bool draw();
	int prompt(unsigned int& xCoord, unsigned int& yCoord); //use cin
	int turn();
	int turns = 0;
	int play();
	bool player = false; //true -> X, false -> O
	string move = "X";
	char playerX[100] = "Player X's moves: ";
	char playerO[100] = "Player O's moves: ";
};
//enum players {X="x", O="o"};
//vector<game_piece> game_board(25);
ostream & operator<<(ostream & output, const TicTacToeGame & newGame);

struct player {
	string display;
	string moves;
};

