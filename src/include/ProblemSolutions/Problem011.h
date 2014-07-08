/*
	What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally)
	in the 20×20 grid in Problem11.txt?
*/

#include <iostream>
#include <vector>
#include <cstdint>

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif

#ifndef _NUMERICGRID_
#include "../Classes/NumericGrid.h"
#endif

#ifndef _EXTRACTNDIGITNUMS_
#include "../OtherFunctions/ExtractNDigitNums.h"
#endif

bool Problem11 ()
{
	std::vector<uint8_t> vect;
	std::string filepath = "../../data/Problem11.txt";
	uint32_t prod;

	ReadFileIntoVect (vect, filepath);
	vect.erase(std::remove(vect.begin(), vect.end(), 13), vect.end());
    vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
	for (uint32_t i = 0; i < vect.size(); i++)
        vect[i] -= 48;

	vect.erase(std::remove(vect.begin(), vect.end(), 240), vect.end());

	ExtractNDigitNums(vect, 2);

	NumericGrid grid(vect);

	prod = grid.FindGreatestProduct();

	std::cout << "\nProblem 011: " << prod << "\n";

	return true;
}
