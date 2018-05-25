#ifndef _MAZE_H_
#define _MAZE_H_
#include "snake.hpp"
#include <chrono>
#include <random>

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
		Maze( int width, int height );	// initializes with width x height
		~Maze();						// default destructor

		// debug functions
		void print();
		void populate();
		char random();
};

#endif
