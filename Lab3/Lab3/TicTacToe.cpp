
#include "stdafx.h"
#include "TicTacToe.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;



ostream & operator<<(ostream & output, const TicTacToeGame & newGame ) {
	//look thru board, for each piece add it's display to the output
	int size = newGame.game_board.size();

	for (int r = 0; r < size; r++) { //not sure if 
		for (int c = 0; c < size; c++) {
			output << newGame.game_board[(size*c)+r].display;
		}
		output << endl;
	}
	
	return output;
}

bool TicTacToeGame:: done() { //fix this
	int options[8][3] = { {6,7,8},{11,12,13},{16,17,18},{6,11,16},{17,12,7},{18,13,8},{16,12,8},{18,12,6}};
	for (int i = 0; i < 8; i++) {
		if (game_board[options[i][0]].display == game_board[options[i][1]].display && game_board[options[i][1]].display == game_board[options[i][2]].display) {
			return true;
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
				if (xCoord <= game_board.size() && yCoord <= game_board.size()) { //need to make sure coords are on board
					runLoop = false;
					return success;
				}
			}
		}
		else if (iss >> message) {
			if (message.compare("quit") == 0) { //if the two strings are equal
				runLoop = false;
				return userQuit;
			}
		}
		count++;
	}
}
int TicTacToeGame::turn() {
	if (player) {
		cout << "Player X" << endl; 
	}
	else {
		cout << "Player O"<< endl; 
	}
	unsigned int x;
	unsigned int y;
	bool runLoop = true;
	while (runLoop) {
		if (prompt(x, y) == success) {
			runLoop = false;
			//need to determine if move is valid
			//A move is valid if and only if it moves a piece to an empty square. 
			//Specifically, a valid move is within the 9 inner squares of the game board.
			int n = game_board.size();
			int boardIndex = (game_board.size()*y) + x;
			if (((n < boardIndex) && (boardIndex < n*(n - 1)) && (0 < (boardIndex % n)) && ((boardIndex%n) <= (n - 2)))) { //if in inner squares

			}
		}
		else if (prompt(x, y) == userQuit) {
			runLoop = false;
			return userQuit;
		}
	}
	player = !player; //alternate turns
}
int TicTacToeGame::play() {

}