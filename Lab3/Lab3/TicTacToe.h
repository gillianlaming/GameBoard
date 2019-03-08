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
	int prompt(unsigned int& xCoord, unsigned int& yCoord); 
	int turn();
	int turns = 0;    
	int play();
	int getValidMoves(int x, int y);
	bool player = false; //true -> X, false -> O
	string move = "X";
	char playerX[100] = "Player X's moves: ";
	char playerO[100] = "Player O's moves: ";
};
ostream & operator<<(ostream & output, const TicTacToeGame & newGame);


