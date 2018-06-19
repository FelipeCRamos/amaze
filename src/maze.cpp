#include "maze.hpp"

game::maze::maze( std::ifstream & _ifsfile ){
	/*{{{*/
	_ifsfile >> m_height >> m_width;

	// initializes the actual canvas with a 2d array
	m_canvas = new char *[m_height];
	for( int i = 0; i < m_height; i++){
		m_canvas[i] = new char[m_width];
	}
	
	// Populates the canvas with the file's values
	std::string buf;
	size_t height_axis = 0;
	// bool snake_created = false;
	while( _ifsfile.good() ){
		std::getline(_ifsfile, buf);
		// std::cout << "buf: " << buf << std::endl;
		if( !buf.empty() ){
			std::stringstream line(buf);
			char el; // el(ement)
			size_t width_axis = 0;
			while(line.get(el)){
				// now, taking individual elements
				if(width_axis++ < m_width){
					switch(el){
						case sym::none_:
							m_canvas[height_axis][width_axis] = sym::none_;	
							break;

						case sym::wall_:
							m_canvas[height_axis][width_axis] = sym::wall_;	
							break;

						case sym::apple_:
							this->m_apple.width = width_axis;
							this->m_apple.height = height_axis;
							m_canvas[height_axis][width_axis] = sym::apple_;	
							break;

						default:
							std::cerr << "Char not recognized! ";
							std::cerr << "<" << height_axis << "," << width_axis;
							std::cerr << ">\n"; 
							break;
					}
				}
			}
			height_axis++;
		}
	}
}
/*}}}*/

bool game::maze::printMaze(){
	/*{{{*/
	/* Delete all the snake members of the map */
	for( int _height = 0; _height < this->m_height; _height++ )
	{
		for( int _width = 0; _width < this->m_width; _width++ )
		{
			/* clear from prev cycle */
			if( m_canvas[_height][_width] == sym::snake_ )
			{
				m_canvas[_height][_width] = sym::none_;
			}
		}
	}

	/* insert all snake members into the canvas */
	std::cout << "{x,y} -> Snake(" << m_snake.size() << "): ";
	for( auto &snk_m : m_snake )
	{
		std::cout << "{" << snk_m.width << "," << snk_m.height << "} ";
		m_canvas[snk_m.height][snk_m.width] = sym::snake_;
	}
	std::cout << std::endl;

	std::cout << "   ";
	for( int _width = 0; _width < this->m_width; _width++ ){
		if( _width % 10 == 0 )
			std::cout << _width << std::setw(10) << std::setfill(' ');
	}
	std::cout << "\n";

	for( int _height = 0; _height < this->m_height; _height++ )
	{
		if( _height % 5 == 0 ){
			if( _height / 10 < 1 ){ std::cout << _height << "  "; }
			else std::cout << _height << " ";
		}
		else{
			std::cout << "   ";
		}
		for( int _width = 0; _width < this->m_width; _width++ )
		{
			/* Decide's what to print */
			std::cout << char(m_canvas[_height][_width]);
		}
		std::cout << std::endl;
	}
	return true;
}
/*}}}*/

bool game::maze::createSnake( pos _position ){
	/*{{{*/
	m_snake.push_front(_position);
	return true;
}
/*}}}*/

bool game::maze::walk( dir _dir ){
/*{{{*/
	pos headNode(m_snake.front());
	bool grow = false;

	if( _dir == dir::up )					// UP DIRECTION
	{
		int _xof = 0, _yof = -1;
		pos _curr( _xof, _yof );
		if( checkbound(_curr) )
		{
			isApple(_curr, grow);
			m_snake.push_front( pos(headNode.width+_xof, headNode.height+_yof));
			if(!grow) m_snake.pop_back();
		} else return false;
	} 
	
	else if ( _dir == dir::down )			// DOWN DIRECTION
	{
		int _xof = 0, _yof = +1;
		pos _curr( _xof, _yof );
		if( checkbound(_curr) )
		{
			isApple(_curr, grow);
			m_snake.push_front( pos(headNode.width+_xof, headNode.height+_yof));
			if(!grow) m_snake.pop_back();
		} else return false;
	}
	
	else if( _dir == dir::left )			// LEFT DIRECTION
	{
		int _xof = -1, _yof = 0;
		pos _curr( _xof, _yof );
		if( checkbound(_curr) )
		{
			isApple(_curr, grow);
			m_snake.push_front( pos(headNode.width+_xof, headNode.height+_yof));
			if(!grow) m_snake.pop_back();
		} else return false;
	} 
	
	else if( _dir == dir::right )			// RIGHT DIRECTION
	{
		int _xof = +1, _yof = 0;
		pos _curr( _xof, _yof );
		if( checkbound(_curr) )
		{
			isApple(_curr, grow);
			m_snake.push_front( pos(headNode.width+_xof, headNode.height+_yof));
			if(!grow) m_snake.pop_back();
		} else return false;
	}
	return true;
}
/*}}}*/

bool game::maze::checkbound( pos _position ){
/*{{{*/
	/* _position is a **RELATIVE** position (+1, -1) for example */
	pos headNode(m_snake.front());

	if(
			headNode.height + _position.height <= 0 or 
			headNode.height + _position.height >= this->m_height - 1
	)
	{
		return false;
	}
	else if( 
			headNode.width + _position.width <= 0 or 
			headNode.width + _position.width >= this->m_width - 1 )
	{
		return false;
	}
	else
	{
		if( m_canvas
				[headNode.height + _position.height]
				[headNode.width + _position.width] == sym::wall_ 
		  ){
			return false;
		}
	}
	return true;
}
/*}}}*/

bool game::maze::isApple( pos _p, bool & _check ){
/*{{{*/
	pos _hn(m_snake.front());
	char _curr =char(m_canvas[_hn.height+_p.height][_hn.width+_p.width]);

	// std::cout << "sym::apple_ = " << char(sym::apple_) << std::endl;
	// std::cout << "m_canvas[...][...] = " << _curr << std::endl;
	if( _curr == char(sym::apple_) ){
		_check = true;
		return true;
	}

	return false;
}
/*}}}*/
