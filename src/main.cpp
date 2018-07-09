#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cassert>
#include <thread>
#include <vector>
#include <map>

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

	std::string filepath;
	/* read parameters from argc & argv */
	{
		if( argc > 1 ){
			if( argc == 3 ){
				std::string _flag( argv[1] );
				std::istringstream file( argv[2] );

				if( _flag != "-f" ){
					std::cerr << "ERROR: Flag incorrect, please try another.\n";
					return 1;
				}

				file >> filepath;
			} else {
                std::cerr << "ERROR: "
                     << "Arguments are incorrent (too big or too small)\n"
                     << "Please, try running again following the example:\n"
                     << "\t./amaze -f input_folder/input_file.dat\n";
				return 1;
			}
		}
		else
		{
            std::cerr << "ERROR: "
                << "Invalid number of arguments!\n"
                << "Please, check the documentation!\n";
			return 1;
		}
	}

	const double FPS = 1000*1/3;

	system("clear");
	std::cout << "Welcome to the Amaze Game!\n";
	std::cout << "Do you want to see the instructions(1)\n";
	std::cout << "or launch the game(2)? " << std::endl;
	std::cout << "Choice: ";

	size_t first_choice;
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

		/* key press event */
		char _mbuf;
		for( int i = 0; i < 2; i++ )
			std::cin.get(_mbuf);
	}

	separator();
	std::cout << "Starting the game...\n";


	std::ifstream initialConfig;
	initialConfig.open( filepath.c_str() );

	bool snk_created = false;
	game::maze canvas( initialConfig, snk_created );

    /* condition to check if the snakes exist */
	if( !snk_created ){
        std::cerr << "ERROR: "
            << "A snake ("
			<< char(game::sym::snake_)
            << ") is missing on the parse file!\n";
		return 1;
	}

	// canvas.createSnake(game::pos(1,1));		// initial snake position (x, y)
	size_t loopCounter = 0;
	size_t AppleCounter = 0;
	// while( AppleCounter < 10 )
	// {
		// Initial declarations of the game
		bool gameRunning = true;

		canvas.randomApplePosition();

		// Discovers the right sequence of moves to perfom,
		// in order to find the apple.
		// std::list<game::dir> directions;
		// directions = canvas.find_route( canvas.snakeHead(),
										// canvas.applePos() );

		// std::cout << "Directions={ ";
		// for( auto i( directions.begin() ); i != directions.end(); i++ ){
			// std::cout << *i << "; ";
		// }
		// std::cout << "}\n";

		// While there still is directions to go and game is Running,
		// walk on that direction and remove it from list.
		while( /*!directions.empty() and*/ gameRunning ){
			system("clear");
			// gameRunning = canvas.walk( directions.front() );


			size_t dir = random() % 4;
			std::cout << "print random: " << dir << std::endl;
			game::dir real_dir;
			do{
				std::mt19937 random (
					std::chrono::system_clock::now().time_since_epoch().count()
				);
				size_t dir = random() % 4;
				switch(dir)
				{
					case 0:
						real_dir = game::dir::up;
						break;
					case 1:
						real_dir = game::dir::down;
						break;
					case 2:
						real_dir = game::dir::left;
						break;
					case 3:
						real_dir = game::dir::right;
						break;
				};
				// std::cout << "dentro do while\n";
			} while ( !canvas.walk( real_dir, false ) );
			gameRunning = canvas.walk( real_dir, true );
			canvas.printMaze();

			// Removes direction that was already used.
			// directions.pop_front();
			std::this_thread::sleep_for( std::chrono::milliseconds( int(FPS) ) );
		}
		// AppleCounter++;
	// }

	std::cout << "Exiting the game...\n";
	return 0;
}
