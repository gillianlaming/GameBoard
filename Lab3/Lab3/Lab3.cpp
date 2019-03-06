
#include "stdafx.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include "TicTacToe.h"

using namespace std;

vector<game_piece> game_board(25); //temporary

int main()
{
	for ( int i = 0; i < game_board.size(); i++) {
		int n = game_board.size();
		game_piece empty;  
		empty.display = " ";

		if (!((n < i) && (i < n*(n-1)) && (0 < (i % n)) &&((i%n) <= (n - 2)))) { //to avoid hardcoding, just hit the edges. hope the equation works
			empty.color = border;
		}
		else {
			empty.color = black;
		}
		game_board.push_back(empty);
	}
	return 0;
}

