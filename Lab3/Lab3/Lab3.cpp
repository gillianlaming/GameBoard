
#include "stdafx.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "TicTacToe.h"

int main()
{
	for (int i = 0; i < game_board.size(); i++) {
		int n = game_board.size();
		game_piece empty;  
		empty.display = " ";
		if (!((n < i < n*(n-1)) && (0 < (i % n) <= (n - 2)))) { //to avoid hardcoding, just hit the edges. hope the equation works
			empty.color = border;
		}
		game_board.push_back(empty);
	}
	return 0;
}

