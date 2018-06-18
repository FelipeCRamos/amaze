#include <iostream>
#include "maze.hpp"

// Snake functions
Maze::Snake::Snake( int x, int y ){
/*{{{*/
	std::pair<int, int> _position( x, y );
	snake.push_front( _position );
}
/*}}}*/

void Maze::Snake::create( int x, int y ){
/*{{{*/
	std::pair<int, int> _position( x, y );
	snake.push_front( _position );
}
/*}}}*/

bool Maze::Snake::check_pos( int x, int y ){
/*{{{*/
	for( auto &i : snake ){
		if( std::pair<int, int>(x,y) == i ){
			return true;
		}
	}
	return false;
}
	/*}}}*/

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
	bool snake_created = false;
	while( config_file.good() ){
		std::getline(config_file, buf);
		// std::cout << "buf: " << buf << std::endl;
		if( !buf.empty() ){
			std::stringstream line(buf);
			char el; // el(ement)
			size_t width_axis = 0;
			while(line.get(el)){
				// now, taking individual elements
				if(width_axis++ < _width){
					switch(el){
						case sym::_none:
							if(!snake_created){
								m_snake.create(width_axis, height_axis);
								snake_created = true;
							}
							_canvas[height_axis][width_axis] = sym::_none;	
							break;

						case sym::_wall:
							_canvas[height_axis][width_axis] = sym::_wall;	
							break;

						case sym::_apple:
							this->m_apple.first = width_axis;
							this->m_apple.second = height_axis;
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

// Internal functions
void Maze::print(){
/*{{{*/
	std::cout << "\e[34;4m>>> THE MAZE:\e[0m\n";
	for( int i = 0; i < _height; i++ ){
		for( int j = 0; j < _width+1; j++ ){// Why does it take <= instead < only?!
			if( m_snake.check_pos(j, i) ){
				std::cout << "\e[0m" << char(sym::_snake_body) << "\e[0m";
			} else {
				switch(_canvas[i][j]){
					case sym::_none:
						std::cout << "\e[2m" << char(sym::_none) << "\e[0m";
						break;
					case sym::_wall:
						std::cout << "\e[2m" << char(sym::_wall) << "\e[0m";
						break;
					case sym::_apple:
						std::cout << "\e[1;5;31m" << char(sym::_apple) << "\e[0m";
						break;
					case sym::_snake_head:
						std::cout << "\e[1m" << char(sym::_snake_head) << "\e[0m";
						break;
					case sym::_snake_body:
						std::cout << "\e[0m" << char(sym::_snake_body) << "\e[0m";
						break;
				}
			}
			
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

bool Maze::swalk( DIR _dir ){
} 

char Maze::get( int x, int y ){
/*{{{*/
	return _canvas[y][x];
}
/*}}}*/

