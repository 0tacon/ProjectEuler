/*
	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
	
																	3
																   7 4
																  2 4 6
																 8 5 9 3
	That is, 3 + 7 + 4 + 9 = 23.
	
	Find the maximum total from top to bottom of the triangle in Problem18.txt
*/

#include <iostream>
#include <string>
#include <vector>

#ifndef _NUMERICTRIANGLE_
	#include "..\\Classes\\NumericTriangle.h"
#endif

#ifndef _READFILEINTOVECT_
	#include "..\\OtherFunctions\\ReadFileIntoVect.h"
#endif

#ifndef _PRINTVECTOR_
	#include "..\\OtherFunctions\\PrintVector.h"
#endif

#ifndef _EXTRACTNDIGITNUMS_
	#include "..\\OtherFunctions\\ExtractNDigitNums.h"
#endif

bool Problem18 ()
{
	std::vector<uint16_t> vect, path;
	std::string filename = "..\\data\\Problem18.txt";
	
	ReadFileIntoVect (vect, filename);
	
	ExtractNDigitNums(vect, 2);
	
	NumericTriangle tri(vect);
	
	std::cout << "\nProblem 018: " << tri.FindHighestPathSum() << "\n";
	return true;
}
