
#include "stdafx.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include "TicTacToe.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<game_piece> game_board(25); //temporary

int main(int argc, char * argv[])
{
	//first check to make sure correct number of arguments are being passed through
	if (argc != commandLineArguments) {
		return messageFunct(argv[programName]);
	}
	//if (argv[inputFile] != "TicTacToe") {
		//return fileFailure();
	//}

	TicTacToeGame newGame;

	return newGame.play();
}

int messageFunct(const char * programName) //takes a C style string or a reference to a const C++ style string as its only parameter
{
	cout << "usage: " << programName << " input_file.txt" << endl; //print usage message
	return commandLineFail; //return failure number
}

int fileFailure() {
	cout << "the file was not the correct file. Please include 'TicTacToe' file" << endl;
	return unableToOpenFileFailure; //unable to open file failure
}

