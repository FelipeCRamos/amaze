#include "snake.hpp"

/* Constructors implementation {{{*/

Snake::Snake( void ){
/*{{{*/
	// STUB
	this->snake.push_front(std::pair<int,int>(0,0));
}
/*}}}*/

Snake::Snake( int x, int y ){
/*{{{*/
	this->snake.push_front(std::pair<int, int> (x, y));
}
/*}}}*/

/*}}}*/

void Snake::walk( dir ){
/*{{{*/
	// TODO	
}
/*}}}*/
