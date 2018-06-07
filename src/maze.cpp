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


Maze::Maze( std::ifstream &config_file ){
/* From file map constructor {{{*/
	// update the class values
	config_file >> _height >> _width;
	std::cout << "Reading values... Height: " << _height;
	std::cout << ", Width: " << _width << std::endl;

	// initializes the actual canvas with a 2d array
	_canvas = new char *[_height];
	for( int i = 0; i < _height; i++){
		_canvas[i] = new char[_width];
	}
	
	// Populates the canvas with the file's values
	std::string buf;
	size_t height_axis = 0;
	while( config_file.good() ){
		std::getline(config_file, buf);
		if( !buf.empty() ){
			std::stringstream line(buf);
			char el; // el(ement)
			size_t width_axis = 0;
			while(line.get(el)){
				// now, taking individual elements
				if(width_axis++ < _width){
					switch(el){
						case sym::_none:
							_canvas[height_axis][width_axis] = sym::_none;	
							break;
						case sym::_wall:
							_canvas[height_axis][width_axis] = sym::_wall;	
							break;
						case sym::_apple:
							_canvas[height_axis][width_axis] = sym::_apple;	
							break;
						default:
							std::cout << "Char not recognized! ";
							std::cout << "<" << height_axis << "," << width_axis;
							std::cout << ">\n"; 
							break;
					}
				}
			}
			height_axis++;
		}
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
	// std::cout << "Printing: " << _height << "x" << _width << std::endl;
	std::cout << "\e[34;4m>>> THE MAZE:\e[0m\n";
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j <= _width; j++ ){	// Why does it take <= instead < only?!
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

char Maze::get( int x, int y ){
/*{{{*/
	return 1;
}
/*}}}*/
