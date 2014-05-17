/*
	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
	there are exactly 6 routes to the bottom right corner.
	
	How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include <cstdint>
#include <cmath>

#ifndef _COMBINATION_
	#include "..\\OtherFunctions\\Combination.h"
#endif
	
bool Problem15 ()
{
	std::cout << "\nProblem 015: " << Combination(40, 20) << "\n";
	return true;
}
