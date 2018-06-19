#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cassert>
#include <thread>

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
	canvas.createSnake(game::pos(5,5));
	size_t loopCounter = 0;

	{
		// Initial declarations of the game
		bool gameRunning = true;
		
		while( gameRunning and loopCounter++ < 1000 ){
			system("clear");
			gameRunning = canvas.walk(game::dir::down);
			canvas.printMaze();
			std::this_thread::sleep_for( std::chrono::milliseconds( int(FPS) ) );
		}
	}

	std::cout << "Exiting the game...\n";
	return 0;
}
