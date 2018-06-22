#include "maze.hpp"
#include <queue>
#include <cstring>

game::maze::maze( std::ifstream & _ifsfile ){
	/*{{{*/
	_ifsfile >> m_height >> m_width;
	this->m_width += 1;

	/* initializes the actual canvas with a 2d array */
	m_canvas = new char *[m_height];
	for( int i = 0; i < m_height; i++){
		m_canvas[i] = new char[m_width];
	}
	
	/* Parse file's config to the actual m_canvas array */
	std::string buf;			// just a buffer, helps with strings
	size_t height_axis = 0;		// a simple counter, to keep track of height

	while( _ifsfile.good() )
	{
		std::getline(_ifsfile, buf);
		if( !buf.empty() )
		{
			std::stringstream line(buf);
			char el; 						// el(ement)
			size_t width_axis = 0;
			while(line.get(el))
			{
				// now, taking individual elements
				if(width_axis++ < m_width)
				{
					switch(el)
					{
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
							std::cerr << "ERROR: Char not recognized! Pos";
							std::cerr << "<" << height_axis << "," << width_axis;
							std::cerr << ">\n"; 
							break;
					}
				}
			}
			height_axis++;		// updates the height that has been read
		}
	}
}
/*}}}*/

bool game::maze::printMaze(){
	/*{{{*/

	/* Escape sequence codes */
	std::string normal = "\e[0m";
	std::string faint = "\e[2m";
	std::string bold = "\e[1m";
	std::string blink = "\e[5m";
	std::string cRed = "\e[31m";
	std::string cGreen = "\e[32m";

	flushCanvas();		//!< Renew the map, updating snake values

	/* This boolean value set's the ruler on the map sides, true = ON */
	bool rulerGuide = true;
	if( rulerGuide )
	{
		std::cout << "   ";
		for( int _width = 0; _width < this->m_width; _width++ )
		{
			if( _width % 10 == 0 )
				std::cout << _width << std::setw(10) << std::setfill(' ');
		}
		std::cout << "\n";
	}
	

	for( int _height = 0; _height < this->m_height; _height++ )
	{
		if( _height % 5 == 0 and rulerGuide )
		{
			if( _height / 10 < 1 ){ std::cout << _height << "  "; }
			else std::cout << _height << " ";
		}
		else if( rulerGuide )
		{
			std::cout << "   ";
		}

		for( int _width = 0; _width < this->m_width; _width++ )
		{
			/* Decide's what to print */
			// std::cout << char(m_canvas[_height][_width]); 	// pure print
			switch(m_canvas[_height][_width])
			{
				case sym::none_:
					std::cout << " ";
					break;
				case sym::apple_:
					std::cout 
						// << blink		// think is annoying
						<< cRed 
						<< char(sym::apple_)
						<< normal;
					break;
				case sym::wall_:
					std::cout 
						<< faint 
						<< char(sym::wall_)
						<< normal;
					break;
				case sym::snake_:
					std::cout
						<< bold
						<< cGreen
						<< char(sym::snake_)
						<< normal;
					break;
			}
		}
		std::cout << std::endl;
	}
	return true;
}
/*}}}*/

bool game::maze::flushCanvas(){
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
	std::cout << "{x,y} -> Snake(" << m_snake.size() << "): ";	// debug print
	for( auto &snk_m : m_snake )
	{
		std::cout << "{" << snk_m.width << "," << snk_m.height << "} ";
		m_canvas[snk_m.height][snk_m.width] = sym::snake_;
	}
	std::cout << std::endl;
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

	if( _curr == char(sym::apple_) ){
		_check = true;
		return true;
	}

	return false;
}
/*}}}*/

std::list<game::dir> game::maze::find_route( pos _start, pos _apple ){ 
/*{{{*/
	int rowNum[] = {-1, 0, 0, 1};
	int colNum[] = {0, -1, 1, 0};

	std::list<dir> moving;

	bool visited[/*game::maze::m_height*/10][10/*this->m_width*/];
	std::memset(visited, false, sizeof visited);

	// Mark coordinate as visited.
	visited[_start.height][_start.width] = true;

	/*
	struct queueNode{
		pos _cord;
		std::list<dir> where_to_move;

		queueNode( pos coordinate,
	};
	*/
	// Create a queue for BFS.
	std::queue<queueNode> q;

	// Direction to reach _curr from _curr;
	moving.push_back( dir::stay );
	queueNode inicio = { _start, moving };
	q.push( inicio );

	// Do BFS starting from current cell.
	while( !q.empty() ){
		queueNode curr = q.front();
		pos point = curr._cord;

		// If we have reached the destination cell, we are done.
		if( point.height == _apple.height and point.width == _apple.width ){
			return curr.where_to_move;
		}

		// Otherwise dequeue the front coordinate in the queue,
		// and enqueue it's adjacent coordinates.
		q.pop();

		for( int i=0; i < 4; i++ ){
			int row = point.height + rowNum[i];
			int col = point.width + colNum[i];

			pos atMoment;
			atMoment.width = colNum[i];
			atMoment.height = rowNum[i];

			// If adjacent coordinate is valid, has path and
			// not visited yet, enqueue it.
			if( /*true == checkbound( pos(colNum[i], rowNum[i]) ) and */false == visited[row][col] ){
				// Mark coordinate as visited and enqueue it.
				dir aux; // Where it went.
				if( i == 0) aux = dir::up;
				else if( i == 1 ) aux = dir::left;
				else if( i == 2 ) aux = dir::right;
				else aux = dir::down;

				visited[row][col] = true;
				curr.where_to_move.push_back( aux );
				queueNode adj = { {row, col},
								  curr.where_to_move };
				
				curr.where_to_move.pop_back();
				q.push( adj );
			}
		}
	}

	// return an default movement if apple can't be reached.
	return moving;
}
/*}}}*/
