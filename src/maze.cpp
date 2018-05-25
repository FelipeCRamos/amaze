#include "maze.hpp"

// Constructors
Maze::Maze( int width, int height ){
/*{{{*/
	// update the class values
	_width = width;
	_height = height;

	// initializes the actual canvas with a 2d array
	_canvas = new char *[_height];
	for( size_t i = 0; i < _height; i++){
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
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width; j++ ){
			std::cout << _canvas[i][j];
		}
		std::cout << std::endl;
	}
}
/*}}}*/

void Maze::populate(){
/*{{{*/
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width; j++ ){
			// _canvas[i][j] = sym::_apple;
			// _canvas[i][j] = sym::_wall;
			// _canvas[i][j] = sym::_none;
		}
	}
}
/*}}}*/
