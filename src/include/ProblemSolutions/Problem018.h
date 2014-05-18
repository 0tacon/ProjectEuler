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

bool Problem18 ()
{
	std::vector<uint16_t> vect, path;
	/*std::string filename = "..\\data\\Problem18.txt";
	
	ReadFileIntoVect (vect, filename);
	
	PrintVector(vect);*/
	
	vect = {3,7,4,2,4,6,8,5,9,3};
	path = {1,1,2,3};
	
	NumericTriangle tri (vect);
	
	tri.PrintTriangle();
	
	//if (tri.IsValidPath(path)) std::cout << "\nConfirmed: Path is valid\n";
	
	std::cout << tri.FindHighestPathSum();
	
	std::cout << "\nProblem 018: " << "\n";
	return true;
}
