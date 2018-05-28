#include "maze.hpp"
	
// Constructors
Maze::Maze( int width, int height ){
/*Random map constructor{{{*/
	// update the class values
	_width = width;
	_height = height;

	// initializes the actual canvas with a 2d array
	_canvas = new char *[_height];
	for( int i = 0; i < _height; i++){
		_canvas[i] = new char[_width];
	}
}
/*}}}*/

Maze::Maze( std::ifstream & _ifs ){
/*From file map constructor{{{*/
	// update the class values
	_ifs >> _height >> _width;

	// initializes the actual canvas with a 2d array
	_canvas = new char *[_height];
	for( int i = 0; i < _height; i++){
		_canvas[i] = new char[_width];
	}
}
/*}}}*/

Maze::~Maze(){
/*{{{*/
	for( size_t i = 0; i < _height; i++ ){
		delete [] _canvas[i];
	}
	delete [] _canvas;
}
/*}}}*/

void Maze::print(){
/*{{{*/
	std::cout << "\e[34;4m>>> THE MAZE:\e[0m\n";
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width; j++ ){
			std::cout << _canvas[i][j];
		}
		std::cout << "\n";
	} std::cout << "\n";
}
/*}}}*/

void Maze::populate(){
/*Random populate{{{*/
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width; j++ ){
			_canvas[i][j] = random();
		}
	}
}
/*}}}*/

void Maze::populate( std::ifstream & _ifs ){
/*From file populate{{{*/
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width; j++ ){
			_canvas[i][j] = read( _ifs );
		}
	}
}
/*}}}*/

char Maze::read( std::ifstream & _ifs ){
/*{{{*/
	char c_;
	_ifs >> c_;
	
	switch( c_ ){
		
		case ' ': return sym::_none;
		case '#': return sym::_wall;
		case '*': return sym::_apple;
	}
}
/*}}}*/

char Maze::random(){
/*{{{*/
}
/*}}}*/
