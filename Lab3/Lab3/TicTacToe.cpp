
#include "stdafx.h"
#include "TicTacToe.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

TicTacToeGame::TicTacToeGame() {
	rows = 5;
	cols = 5;
	for (int i = 0; i < rows*cols; i++) {
		int n = game_board.size();
		game_piece empty;
		empty.display = " " ;

		if (!((rows < i) && (i < rows*(cols - 1)) && (0 < (i % rows)) && ((i%rows) <= (cols - 2)))) { //to avoid hardcoding, just hit the edges. hope the equation works
			empty.color = border;
		}
		else {
			empty.color = black;
		}
		game_board.push_back(empty);
	}
}

ostream & operator<<(ostream & output, const TicTacToeGame & newGame ) { //look thru board, for each piece add it's display to the output
	int size = newGame.game_board.size();
	for (int r = newGame.rows-1; r >= 0 ; r--) {
		output << r;
		for (int c = 0; c < newGame.cols; c++) {
			if (r == 0 && c >0) {
				output << c;
			}
			else {
				output << newGame.game_board[(newGame.cols*c) + r].display;
			}
		}
		output << endl;
	}
	return output;
}


bool TicTacToeGame:: done() { //fix this
	int options[8][3] = { {6,7,8},{11,12,13},{16,17,18},{6,11,16},{17,12,7},{18,13,8},{16,12,8},{18,12,6}};
	for (int i = 0; i < 8; i++) {
		if ((game_board[options[i][0]].display == "X") || (game_board[options[i][0]].display == "O")) {
			if (game_board[options[i][0]].display == game_board[options[i][1]].display && game_board[options[i][1]].display == game_board[options[i][2]].display) {
				return true;
			}
		}	
	}
	return false;
}

bool TicTacToeGame::draw() {
	int numMovesRemaining = 0; 
	if (done()) {
		return false;
	}
	for (unsigned int i = 0; i < game_board.size(); i++) {
		if (game_board[i].color != border && game_board[i].display == " ") {
			numMovesRemaining++;
		}
	}
	if (numMovesRemaining != 0) {
		return false;
	}
	else {
		return true;
	}
}

int TicTacToeGame::prompt(unsigned int& xCoord, unsigned int& yCoord) {
	bool runLoop = true;
	int count = 0; 
	while (runLoop) {
		if (count != 0) { //if second iteration through loop
			cout << "Invalid input. ";
		}
		cout << "Please enter valid coordinates(x,y), or type quit." << endl;
		string line;
		cin >> line;
		istringstream iss(line);
		char comma;
		string message;
		if (iss >> xCoord >> comma >> yCoord) { //if it can wrap to those var types
			if (comma == ',') { //check to make sure the char is a comma
				if (xCoord <= game_board.size()/5 && yCoord <= game_board.size()/5) { //need to make sure coords are on board
					runLoop = false;
					return success;
				}
			}
		}
		if (line.compare("quit") == 0) { //if the two strings are equal
			runLoop = false;
			return userQuit;
		}
		count++;
	}
	return success;
}
int TicTacToeGame::turn() {
	player = !player; //alternate turns 
	if (player) {
		move = "X";
	}
	else {
		move = "O";
	}
	cout << "Player " << move << "'s turn" << endl;
	unsigned int x;
	unsigned int y;
	bool runLoop = true;
	while (runLoop) {
		int result = prompt(x, y);
		if (result == success) {
			int n = game_board.size() / rows;
			int boardIndex = (n*x) + y;
			if (game_board[boardIndex].color != border){
				if(game_board[boardIndex].display == " "){ //now it is a valid move
					game_board[boardIndex].display = move; //move the piece to that square
					cout << endl;
					cout << *this << endl; //print out updated board
					cout << endl;
					if (player) {
						cout << playerX;
						getValidMoves(x, y);
						cout << endl;
					}
					else {
						cout << playerO;
						getValidMoves(x, y);
						cout << endl;
					}
					turns++;
					runLoop = false;
					return success;
				}
			}
		}
		else if (result == userQuit) { 
			runLoop = false;
			return userQuit;
		}
	}
	return success;
}

int TicTacToeGame::getValidMoves(int x, int y) {
	for (unsigned int i = 0; i < game_board.size(); i++) {
		if (game_board[i].display == move) {
			int yCoor = (i % 5); //hardcoded
			int xCoor = (i - yCoor) / 5;
			cout << xCoor << "," << yCoor << ';';
		}
	}
	cout << endl;
	return success;
}

int TicTacToeGame::play() {
	cout << *this << endl; //print out updated board
	
	//turn, then done, then draw
	bool isDone = done();
	bool isDraw = draw();
	while ((!isDone) && (!isDraw)) { 
		int result = turn();
		if (result == userQuit) {
			cout << "User quit. " << turns << " turns were played." << endl; //if user quits,  print how many turns were played, say user has quit, return unique non-zero error code
			return userQuit;
		}
		isDone = done();
		isDraw = draw();
	}
	if (isDone) { //if done returns true, print out the winner, return success
		cout << "Player " << move << " won." << endl;
		return success;
	}
	else if (isDraw) { 
		cout << "Draw: No more winning moves remain. " << turns << " turns were played." << endl; //if draw returns true, print how many turns were played, say no winning moves remain			
		return drawResult; //return unique non-zero error code
	}
	return success;
}