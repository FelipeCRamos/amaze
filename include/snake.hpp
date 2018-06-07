#ifndef _SNAKE_H_
#define _SNAKE_H_
// STL includes
#include <iostream>
#include <list>

// Project includes
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

using m_pos = std::pair<int,int>;

class Snake{
private:
	/* For conventions, we will use [x, y] based axis */
	std::list<m_pos> snake;

public:
	/** Initializes the snake with empty position */
	Snake( void );

	/** Born the snake with a head on (x,y) position */
	Snake( int x, int y );

	/** Walk to the nearest '*' on the map */
	void walk( dir );
};

#endif
