#ifndef _MAZE_HPP_
#define _MAZE_HPP_

// STL Includes
#include <chrono>
#include <list>
#include <random>
#include <fstream>
#include <sstream>



class Maze{
	private:
		enum sym{
			_none = ' ',
			_wall = '#',
			_apple = '*',
			_snake_head = '@',
			_snake_body = '+'
		};

		enum DIR{
			up,
			down,
			left,
			right,
		};

		class Snake{
			private:
				/* Snake object itself, made by a list with positions (x,y). */
				std::list< std::pair<int,int> > snake;
				size_t _bodySize = 0;
			public:
				/** Snake default constructor, initializes with specified (x,y)
				 * and `_bodySize = 1`. */
				Snake( int, int );		// default constructor, initializes with body=1

				Snake(){/* */};

				/** Create a Snake on x, y */
				void create( int x, int y );

				/** Make the Snake walks to the `DIR` specified. */
				void walk( DIR );

				/** Make the Snake grow in the `DIR` specified. */
				void grow( DIR );

				/** Check's if is possible to grow/walk in that direction. */
				bool check( DIR );

				/** Check if a position is a snake position. */
				bool check_pos( int, int );
		};

		Snake m_snake;				// double linked list for the snake

		/* track variables */
		int _width = 0;
		int _height = 0;

		/* Actual canvas */
		char **_canvas;					// 2d array
		std::pair<int, int> m_apple;		// position of the apple (x, y)

	public:
		
		/** Randomic initializes maze structure. */
		Maze( int width, int height );

		/** Maze main constructor. Allocates suficient space for maze. */
		Maze( std::ifstream & ifs_ );

		/** Default destructor */
		~Maze();

		// debug functions
		
		/** Prints the Maze canvas on std::cout. */
		void print();

		/** Updates the current Maze canvas */
		void update_canvas();

		/** Creates the Maze structure randomly. */
		void populate();

		/** Reads a char from the defined file, to create maze. */
		char read( std::ifstream & ifs_ );

		/**  */
		char random();

		bool swalk( DIR );

		/** Returns the char element on position passed. */
		char get( int x, int y );

};

#endif
