/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

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
#include "../Classes/NumericTriangle.h"
#endif

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif

#ifndef _EXTRACTNDIGITNUMS_
#include "../OtherFunctions/ExtractNDigitNums.h"
#endif

bool Problem18 ()
{
	std::vector<uint16_t> vect, path;
	std::string filename = "../../data/Problem18.txt";

	ReadFileIntoVect (vect, filename);
	vect.erase(std::remove(vect.begin(), vect.end(), 13), vect.end());
    vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
	for (uint32_t i = 0; i < vect.size(); i++)
        vect[i] -= 48;

    vect.erase(std::remove(vect.begin(), vect.end(), 65520), vect.end());

	ExtractNDigitNums(vect, 2);

	NumericTriangle tri(vect);

	std::cout << "\nProblem 018: " << tri.FindHighestPathSum() << "\n";
	return true;
}
