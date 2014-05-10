/*
	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
	there are exactly 6 routes to the bottom right corner.
	
	How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include <cstdint>
#include <cmath>

#ifndef _COUNTHIGHBITS_
	#include "..\\OtherFunctions\\CountHighBits.hpp"
	#define _COUNTHIGHBITS_
#endif

uint16_t CalculateNumPaths(uint8_t grid_side_length)
{
	uint8_t num_high_bits;
	uint64_t num_paths=0;
	
	for (uint64_t n=0; n<pow(2, grid_side_length*2); n++)
	{
		num_high_bits = CountHighBits(n, grid_side_length*2);
		if (num_high_bits==grid_side_length)	num_paths++;
	}
	
	return num_paths;
}

bool Problem15()
{
	uint8_t grid_side_length = 20;
	uint64_t num_paths;
	
	num_paths = CalculateNumPaths(grid_side_length);
	
	std::cout << "\nProblem 015: " << num_paths << "\n";
	return true;
}
