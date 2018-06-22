#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cassert>
#include <thread>
#include <vector>

#include "maze.hpp"

void separator(){
	const char SEP_CHAR = '-';
	const size_t SEP_FILL = 80;
	std::cout <<
		"\e[2m" <<
		std::setfill(SEP_CHAR) <<
		std::setw(SEP_FILL) <<
		"\e[0m" <<
		"\n";
}

int main( int argc, char **argv ){
	double FPS = 1000*1/3;
	system("clear");
	std::cout << "Please, welcome to the Amaze Game!\n";
	std::cout << "Do you want to see the instructions(1)\n";
	std::cout << "or launch the game(2)? " << std::endl;
	std::cout << "Choice: ";
	int first_choice;
	std::cin >> first_choice;

	if( first_choice == 1 ){
		separator();
		std::cout << "INSTRUCTIONS:\n";
		separator();
		std::cout << "~ The snake is controlled by arrow keys or WASD scheme!\n";
		std::cout << "~ You cannot hit walls, only apples!\n";
		separator();
		std::cout << "\n\nGood Luck!\n";
		std::cout << "\n\nType any key to continue...\n";
		std::cin;
	}

	separator();
	std::cout << "Starting the game...\n";

	std::string filepath;
	/* read parameters from argc & argv */
	{
		if( argc > 1 ){
			if( argc == 3 ){
				std::string _flag( argv[1] );
				std::istringstream file( argv[2] );

				if( _flag != "-f" ){
					std::cerr << "Flag incorrect, please try another.\n";
					return 1;
				}

				file >> filepath;
			} else {
				std::cerr << "Arguments are incorrent (too big or too small)\n";
				std::cerr << "Please, try running again following the example:";
				std::cerr << "\n./amaze -f input_folder/input_file.dat\n";
				return 1;
			}
		}
	}

	std::ifstream initialConfig;
	initialConfig.open( filepath.c_str() );

	game::maze canvas( initialConfig );
	canvas.createSnake(game::pos(1,1));	// initial snake position (x, y)
	size_t loopCounter = 0;

	{
		// Initial declarations of the game
		bool gameRunning = true;

		// Discovers the right sequence of moves to perfom,
		// in order to find the apple.
		std::list<game::dir> directions;
		directions = canvas.find_route( game::pos(2,1), game::pos(5,2)/*snake_head, apple_pos */ );
		
		// While there still is directions to go and game is Runnig,
		// walk on that direction and remove it from list.
		while( !directions.empty() and gameRunning ){
			system("clear");
			gameRunning = canvas.walk( directions.front() );
			canvas.printMaze();
			directions.pop_front();
		}

/*		while( gameRunning and loopCounter++ < 1000 ){
			system("clear");
			gameRunning = canvas.walk(game::dir::right);
			canvas.printMaze();
			std::this_thread::sleep_for( std::chrono::milliseconds( int(FPS) ) );
		}
*/
	}

	std::cout << "Exiting the game...\n";
	return 0;
}
