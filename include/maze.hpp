#ifndef _MAZE_HPP_
#define _MAZE_HPP_

// STL Includes
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>

// Project includes
#include "snake.hpp"

enum sym{
	_none = ' ',
	_wall = '#',
	_apple = '*',
};


class Maze{
	private:
		Snake m_snake;				// double linked list for the snake
		// track variables
		int _width = 0;
		int _height = 0;

		// actual canvas
		char **_canvas;					// 2d array
		std::pair<int, int> _apple;		// position of the apple (x, y)


	public:
		
		/** Randomic initializes maze structure. */
		Maze( int width, int height );

		/** Maze main constructor. Allocates suficient space for maze. */
		Maze( std::ifstream & ifs_ );

		/** Default destructor */
		~Maze();

		// debug functions
		
		/** Prints the Maze canvas on std::cout. */
		void print();

		/** Creates the Maze structure randomly. */
		void populate();

		/** Reads a char from the defined file, to create maze. */
		char read( std::ifstream & ifs_ );

		/**  */
		char random();

		/** Returns the char element on position passed. */
		char get( int x, int y );

};

#endif
