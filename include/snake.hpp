#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <iostream>
#include <list>

#include "maze.hpp"

/*!
 *	\file 	snake.hpp
 *	\brief	Where all the snake object implementations are defined 
 *	\author	Daniel Guerra and Felipe Ramos
 */

/** Direction enumerate, used for guidance */
enum dir{
	up = 'u',
	down = 'd',
	left = 'l',
	right = 'r'
};

class Snake{

private:
	/* For conventions, we will use [x, y] based axis */
	std::list< std::pair<int, int> > snake;

public:
	/** Born the snake with a head on (x,y) position */
	Snake( int x, int y );

	/** Walk to the nearest '*' on the map */
	void walk( Maze &mz );
};

#endif
