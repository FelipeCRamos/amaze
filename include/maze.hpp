#ifndef _MAZE_HPP_
#define _MAZE_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>

namespace game
{
	struct pos
	{
		int width;
		int height;
		pos( int _wid, int _hei ) : width(_wid), height(_hei){/* empty */};
		pos( void ) : width(0), height(0){ /* empty */ };
	};
	enum sym
	{
		none_ = ' ',
		apple_ = '*',
		wall_ = '#',
		snake_ = '%'
	};
	enum dir
	{
		up,
		down,
		left,
		right
	};

	class maze
	{
		protected:
			std::list<pos> m_snake;
			int m_height;
			int m_width;
			char ** m_canvas;
			pos m_apple;

		public:
			maze( std::ifstream & _ifsfile );

			/** Print the entire maze on the screen. */
			bool printMaze();

			/** Creates the snake on specified position. */
			bool createSnake( pos );

			/** Makes the snake walk to the specified direction. */
			bool walk( dir );

			/** Check bounds. */
			bool checkbound( pos );
	};
}
#endif
