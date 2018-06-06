#ifndef _MAZE_H_
#define _MAZE_H_
#include "snake.hpp"
#include <chrono>
#include <random>
#include <fstream>

enum sym{
	_none = ' ',
	_wall = '#',
	_apple = '*',
};

class Maze{

	private:
		// track variables
		int _width = 0;
		int _height = 0;

		// actual canvas
		char **_canvas;					// 2d array
		std::pair<int, int> _apple;		// position of the apple (x, y)

		Snake _cur_snake;				// double linked list for the snake

	public:
		
		Maze( int width, int height );	// randomic initializes maze structure
		/* @brief Maze main constructor. Allocates suficient space for maze. */
		Maze( std::ifstream & ifs_ );	// from file initializes maze structure
		~Maze();						// default destructor

		// debug functions
		/* @brief prints on terminal the maze itself. */
		void print();

		/* @brief creates the maze structure randomicly. */
		void populate();

		/* @brief from a file, constructs maze structure. */
		void populate( std::ifstream & ifs_ );

		/* @brief reads a char from the defined file, to create maze. */
		char read( std::ifstream & ifs_ );
		char random();

		/* @brief returns the char element on position passed. */
		char at_char( int x, int y );

		// ia functions
			//TODO...
};

#endif
