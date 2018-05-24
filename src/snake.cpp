#include "snake.hpp"

/** Initializes the snake with a empty position [x, y] */
Snake::Snake(){
	this->snake.push_front(std::pair<int, int> (0, 0));
}

Snake::Snake( int x, int y ){
	this->snake.push_front(std::pair<int, int> (x, y));
}

bool Snake::go( dir d ){
	std::cout << ">> ";
	if( d == dir::up ){
		std::cout << "UP!\n";
	} else if( d == dir::down ){
		std::cout << "DOWN!\n";
	} else if( d == dir::left ){
		std::cout << "LEFT!\n";
	} else{
		std::cout << "RIGHT!\n";
	}
	// std::cout << "The direction was: " << d << std::endl;
	return true;	// stub
}

