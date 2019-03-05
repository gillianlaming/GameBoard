#pragma once

class TicTacToeGame {
private:
	//new game board
	//game piece either an X or O
	//initialize board so that outer squares always stay empty
};

//declare and define an insertion operator (operator<<) that takes a reference to an ostream 
//and a reference to a const game class object as parameters, and returns the ostream reference 
//that was passed in (this allows the operator to be called repeatedly on the same ostream 
//object as in cout << tictactoe_game << endl;)