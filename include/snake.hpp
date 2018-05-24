#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <iostream>
#include <list>

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
		bool grow_now = false;
	public:
		// Constructors/Destructors
		Snake();
		Snake( int x, int y );

		// Movement functions
		bool go( dir );

		// Size related functions
		bool grow( size_t len );
};

#endif
