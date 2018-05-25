#include "ia.hpp"
#include "maze.hpp"
#include "snake.hpp"

// STL includes
#include <iostream>
#include <fstream>

int main(void){
	Maze main_map(20, 20);
	main_map.populate();
	main_map.print();
	return 0;	
}
