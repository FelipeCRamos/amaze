#include "ia.hpp"
#include "maze.hpp"
#include "snake.hpp"

// STL includes
#include <iostream>

// Global definitions
#define RAND true  // true for randomic mazes; false for file definied mazes

int main( int argc, char **argv ){
	std::cout << "\tDirections permited for snake: ";
	std::cout << "\e[32;2mUP RIGHT DOWN LEFT 'u' 'r' 'd' 'l'\e[0m";

	if( RAND ){
		Maze main_map( 20, 20 );
		main_map.populate();
	} else{
		std::ifstream ifs;
		ifs.open( filename.c_str() );

		Maze main_map( ifs );
		main_map.populate( ifs );
	}

	main_map.print();
	if( !RAND ) ifs.close();
	return 0;	
}
