#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <chrono>
#include <random>

namespace game
{
	/** Struct for a posision (x, y). */
	struct pos
	{
		int width; 		//!< X-axis of the position
		int height;		//!< Y-axis of the position

		/** Void constructor, initializes the position with (0,0). */
		pos( void ) : width(0), height(0){/* */};

		/** Default constructor, takes (x,y) argument. */
		pos( int _wid, int _hei ) : width(_wid), height(_hei){/* */};
	};

	/** Enumerates the symbols used in the maze. */
	enum sym
	{
		none_ = ' ',
		inv_wall_ = '.',
		apple_ = '@',
		wall_ = '#',
		snake_ = '*'
	};

	/** Enumerates the directions that the snake can take. */
	enum dir
	{
		up,
		down,
		left,
		right,
		stay
	};

	/* Struct for BFS purposes. */
	struct queueNode
	{
		pos _cord;
		std::list<game::dir> where_to_move;
	};

	/** Maze class, contains all info about the current maze, snakes, apples. */
	class maze
	{
		protected:
			std::list<pos> m_snake;			//!< Snake object, linked list
			int m_height;					//!< Height of the map
			int m_width;					//!< Width of the map

			/* Map array, each (x,y) contains a char `sym` */
			char ** m_canvas;	

			pos m_apple;					//!< Apple position (NOT IMPLEMENTED)

			/** Class that tells the direction the snake must go in order to
			 * eat the apple. (NOT IMPLEMENTED YET) */
			class ai
			{
				protected:
					pos f_apple;	//!< Apple that the algorithm will search

				public:
					/* The successful path to the apple object. */
					std::list<pos> f_pos;

					/* Future recurssive function to find the path. */
					//std::list<dir> find_route( pos, pos );

					// For when path to apple is inexistent.
					// Default movement will just send snake to die.
					//std::list<dir> DEFAULT_MOVEMENTS( 100, up );
	
			};

		public:
			/** Default constructor, recieve a ifstream with map config. */
			maze( std::ifstream & _ifsfile, bool & _snk );

			/** Print the entire maze on the screen. */
			bool printMaze();

			/** Flushes the map, rebuilding snake body onto the map. */
			bool flushCanvas();

			/** Creates the snake on specified position. */
			bool createSnake( pos );

			/** Makes the snake walk to the specified direction. */
			bool walk( dir );

			/** Check bounds. */
			bool checkbound( pos _position );

			/** Check if a given `pos` is an apple, set the bool value to true
			 * if is, false otherwise. */
			bool isApple( pos, bool & );

			std::list<dir> find_route( pos, pos );

			bool randomApplePosition();

			pos applePos();

			pos snakeHead();
	};
}
#endif
