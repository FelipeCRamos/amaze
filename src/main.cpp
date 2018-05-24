#include "ia.hpp"
#include "maze.hpp"
#include "snake.hpp"

// STL includes
#include <iostream>
#include <fstream>

int main(void){
	Snake test(2, 2);
	
	// test
	test.go(dir::up);
	test.go(dir::down);
	test.go(dir::left);
	test.go(dir::right);

	return 0;	
}
