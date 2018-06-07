#include "snake.hpp"

/* Constructors implementation {{{*/

Snake::Snake( void ){
/*{{{*/
	// STUB
	this->m_snake.push_front(std::pair<int,int>(0,0));
}
/*}}}*/

Snake::Snake( int x, int y ){
/*{{{*/
	this->m_snake.push_front(std::pair<int, int> (x, y));
}
/*}}}*/

/*}}}*/

void Snake::walk( Angle _dir ){
/*{{{*/
	std::cout << _dir << std::endl;
	// TODO	
}
/*}}}*/
