#include "snake.hpp"

/** Initializes the snake with a empty position [x, y] */
Snake::Snake(){
/*{{{*/
	this->snake.push_front(std::pair<int, int> (0, 0));
}
/*}}}*/

Snake::Snake( int x, int y ){
/*{{{*/
	this->snake.push_front(std::pair<int, int> (x, y));
}
/*}}}*/

// Is this the check function for direction, or the function to move?
bool Snake::go( dir d ){
/*{{{*/
	while( true ) {
		std::cout << ">> ";
		if( d == dir::up ){
			std::cout << "UP!\n";
			break;
		} else if( d == dir::down ){
			std::cout << "DOWN!\n";
			break;
		} else if( d == dir::left ){
			std::cout << "LEFT!\n";
			break;
		} else if( d == dir::right ){
			std::cout << "RIGHT!\n";
			break;
		} else {
			std::cerr << "\e[31;4mDIRECTION UNDEFINED!\nPlease, choose ";
			std::cerr << "between valid directions.\n";
			continue;
		}
	}
	
	// std::cout << "The direction was: " << d << std::endl;
	return true;	// stub
}
/*}}}*/

bool grow( size_t len );
/*{{{*/
	
/*}}}*/
