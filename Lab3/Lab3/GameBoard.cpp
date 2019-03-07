#include "GameBoard.h"
#include "stdafx.h"
#include "GamePieces.h"
#include "Header.h"
#include "string"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int readBoard(ifstream & file, unsigned int & width, unsigned int & height)
{
	string newbie;

	if (file.is_open()) //open that file up
	{
		if (!getline(file, newbie)) {
			return cannotReadLine;
		}
		istringstream iss(newbie);
		if (!(iss >> width)) { //if cannot extract dimensions
							   //continue;
			return cannotExtractDemensions;
		}
		//cout << "first int " << width << endl;
		if (!(iss >> height)) { //if cannot extract dimensions

			return cannotExtractDemensions;
		}
		//cout << "second int " << height << endl;
		return success;
	}
	else {
		return unableToOpenFileFailure;
	}

}

int readPieces(ifstream & file, vector<game_piece> & pieces, unsigned int width, unsigned int height)
{
	string placeHolder;
	string pieceColor;
	string pieceName;
	string displayPiece;
	unsigned int col;
	unsigned int row;

	while (getline(file, placeHolder)) { //while it's not the end of the file

		istringstream iss(placeHolder); // wrap in iss
		if (!(iss >> pieceColor)) {// if cant read into piecename 
			continue; //skip line
		}
		if (!(iss >> pieceName)) { //if cannot read into piececolor 
			continue;
		}
		if (!(iss >> displayPiece)) { //if cannot read into displayPiece
			continue;
		}
		if (!(iss >> col)) { //if cannot read into col
			continue;
		}
		if (!(iss >> row)) { //if cannot read into row
			continue;
		}
		piece_color colorMe = whatColor(pieceColor); //(1) convert the first string into an enumeration value for the game piece color
		if (colorMe == invalidColor) {
			continue;
		}
		if ((row > height || col > width)) { //if the parameters for board size are out of bounds -- too big
			continue;
		}
		if ((row < 0 || col < 0)) { //if the parameters for board size are out of bounds -- too small
			continue;
		}

		int index = width*row + col; //calculate index based on equation given
		game_piece newPiece;//make the new gamepiece
		newPiece.color = colorMe; //set color to extracted color
		newPiece.display = displayPiece; // set display to extracted display
		newPiece.name = pieceName; //set name to extracted name
		pieces[index] = newPiece; // put into vector

	}

	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int width, unsigned int height)
{
	int theSize = board.size();
	if (theSize != width*height) { //if extracted size does not match size of board
		return wrongBoardDimensions;
	}

	for (unsigned int c = 0; c < height; c++) {
		for (unsigned int r = width - 1; r >= 0; r--) { //start at top lefthand corner and work across and then down

			if (r > height) { //since the int is unsigned, you need to check this case.
				break;
			}
			int index = width*(height - 1 - c) + (width - 1 - r); //you need to invert both the row and columns
			cout << board[index].display;
		}
		cout << "" << endl;
	}
	return success;
}

int printInfo(const vector<game_piece> & board, unsigned int width, unsigned int height) {//EXTRA CREDIT
																						  //on a separate line for each piece on the game board prints out the square, 
																						  //name, and color of that piece, followed by a colon, followed by a semicolon - 
																						  //separated list of pieces occupying squares adjacent to it
																						  //eg: 0,0 black stone: 1,1 white stone

	int theSize = board.size();
	if (theSize != width*height) { //if extracted size does not match size of board
		return wrongBoardDimensions;
	}
	//iterate through every element in the board
	for (unsigned int c = 0; c < height; c++) {
		for (unsigned int r = width - 1; r >= 0; r--) {

			if (r > height) { //since the int is unsigned, you need to check this case.
				break;
			}
			int index = width*(height - 1 - c) + (width - 1 - r); //calculate index

																  //find indexes of neighbors
			int rightNeighbor = index + 1;
			int leftNeighbor = index - 1;
			int belowNeighbor = index - width;
			int aboveNeighbor = index + width;
			int northWest = index - (width + 1); //diagonal
			int northEast = index - (width - 1);
			int southWest = index + (width - 1);
			int southEast = index + (width + 1);

			vector<game_piece> neighbors; //make vector of game pieces

										  //see if the neighbors exist
			if (rightNeighbor > 0 && rightNeighbor < theSize) {
				neighbors.push_back(board[rightNeighbor]); //push onto vector if it exists
			}
			if (leftNeighbor > 0 && leftNeighbor < theSize) {
				neighbors.push_back(board[leftNeighbor]); //push onto vector if it exists
			}
			if (belowNeighbor > 0 && belowNeighbor < theSize) {
				neighbors.push_back(board[belowNeighbor]); //push onto vector if it exists
			}
			if (aboveNeighbor > 0 && aboveNeighbor < theSize) {
				neighbors.push_back(board[aboveNeighbor]); //push onto vector if it exists
			}
			if (northWest > 0 && northWest < theSize) {
				neighbors.push_back(board[northWest]); //push onto vector if it exists
			}
			if (northEast > 0 && northEast < theSize) {
				neighbors.push_back(board[northEast]); //push onto vector if it exists
			}
			if (southWest > 0 && southWest < theSize) {
				neighbors.push_back(board[southWest]); //push onto vector if it exists
			}
			if (southEast > 0 && southEast < theSize) {
				neighbors.push_back(board[southEast]); //push onto vector if it exists
			}

			if (!(board[index].color == noColor)) {
				string color = noName(board[index].color); //need to convert piece_color type to a string
				cout << c << "," << r << " " << board[index].name << " " << color << ": "; //print off info of parent element


																						   //then, iterate through the vector and print off info for all neighboring elements
				for (unsigned int i = 0; i < neighbors.size(); ++i) {

					//check to see if piece is filled
					if (!(neighbors[i].color == noColor)) {
						string color = noName(neighbors[i].color); //need to convert piece_color type to a string
						cout << c << "," << r << " " << neighbors[i].name << " " << color << "; ";
					}

				}
				cout << endl;
			}


		}
	}
	return success;

}