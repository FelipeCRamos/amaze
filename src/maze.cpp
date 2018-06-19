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
	bool snake_created = false;
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
	/* put the snake on the maze */

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

	for( auto &snake_member : m_snake )
	{
		// std::cout << "member at " <<
			// snake_member.height << ", " << snake_member.width << std::endl;
		m_canvas[snake_member.height][snake_member.width] = sym::snake_;
	}

	for( int _height = 0; _height < this->m_height; _height++ )
	{
		for( int _width = 0; _width < this->m_width; _width++ )
		{
			/* Decide's what to print */
			std::cout << char(m_canvas[_height][_width]);
		}
		std::cout << std::endl;
	}
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
	std::cout << "m_snake.front() = " 
		<< m_snake.front().width << ", "
		<< m_snake.front().height << std::endl;
	std::cout << "m_canvas[" << m_snake.front().width << "]"
		<< "[" << m_snake.front().height << "] = "
		<< char(m_canvas[m_snake.front().width][m_snake.front().height]) << std::endl;
	bool grow = false;

	switch(_dir)
	{
		case up:
			if( checkbound( pos(0, -1) ))
			{
				if( m_canvas[headNode.width+0][headNode.height-1] == sym::apple_ )
					grow = true;	// Não entra aqui!!!
				m_snake.push_front( pos(headNode.width+0, headNode.height-1) );
				if( !grow )
					m_snake.pop_back();
				return true;
			} else {
				return false;
			}
			break;

		case down:
			if( checkbound( pos(0, +1) ))
			{
				if( m_canvas[headNode.width+0][headNode.height+1] == sym::apple_ ){
					grow = true;
				}
				m_snake.push_front( pos(headNode.width+0, headNode.height+1) );
				if( !grow )
					m_snake.pop_back();
				return true;
			} else {
				return false;
			}
			break;

		case left:
			if( checkbound( pos(-1, 0) ))
			{
				if( m_canvas[headNode.width-1][headNode.height+0] == sym::apple_ )
					grow = true;
				m_snake.push_front( pos(headNode.width-1, headNode.height+0) );
				if( !grow )
					m_snake.pop_back();
				return true;
			} else {
				return false;
			}
			break;

		case right:
			if( checkbound( pos(+1, 0) ))
			{
				if( m_canvas[headNode.width+1][headNode.height+0] == sym::apple_ )
					grow = true;
				m_snake.push_front( pos(headNode.width+1, headNode.height+0) );
				if( !grow )
					m_snake.pop_back();
				return true;
			} else {
				return false;
			}
			break;
	}
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
