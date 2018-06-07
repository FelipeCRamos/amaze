#include "ia.hpp"
#include "maze.hpp"
#include "snake.hpp"

// STL includes
#include <iostream>
#include <sstream>

bool RAND;	// definition for either randomic generation, or file receiving.

int main( int argc, char **argv ){
	std::string input_file;

	if( argc != 1 && argc != 3 ){
		std::cerr << "Given arguments are either too big or to small";
		std::cerr << "\nTry running again.\n";
		return -1;
	}

	if( argc == 3 ){
		std::istringstream ss( argv[1] );
		std::istringstream zs( argv[2] );
		std::string argument;
		ss >> argument;
    
		if( argument != "-f" ){
			std::cerr << "Command '" << argument << "' is undefined.\n";
			std::cerr << "You meant '-f'?\n";
			return -2;
		}

		zs >> input_file;
		RAND = false;
	}
	else {
		RAND = true;
	}

	std::cout << "\tDirections permited for snake: ";
	std::cout << "\e[32;2mUP RIGHT DOWN LEFT 'u' 'r' 'd' 'l'\e[0m";

	std::ifstream ifs;
	if( RAND ){
		Maze main_map( 20, 20 );
		main_map.populate();
		main_map.print();
	} else{
		ifs.open( input_file.c_str() );

		Maze main_map( ifs );
		main_map.populate( ifs );
		main_map.print();
	}

	if( !RAND ) ifs.close();
	return 0;	
}
