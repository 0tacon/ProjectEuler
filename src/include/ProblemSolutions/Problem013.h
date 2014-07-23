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
	Work out the first ten digits of the sum of the one-hundred 50-digit numbers in Problem13.txt.
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif

bool Problem13 ()
{
	std::vector<uint8_t> vect;
	std::string filename = "../../data/Problem13.txt";
	uint8_t digit=0, count=0;
	uint16_t carry=0;
	uint64_t answer=0;

	ReadFileIntoVect (vect, filename);
	vect.erase(std::remove(vect.begin(), vect.end(), 13), vect.end());
    vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
	for (uint32_t i = 0; i < vect.size(); i++)
        vect[i] -= 48;

	for (int8_t j=10; j>=0; j--)
	{
		count++;
		for (uint16_t i=j; i<(50*99+j+1); i+=50)
		{
			digit += vect[i];
			if (digit>10)
			{
				digit = digit%10;
				carry++;
			}
		}
		answer += pow(10, count-1)*digit + pow(10, count)*carry;
		digit = 0;
		carry = 0;
	}

	answer = (answer - answer%1000)/1000;

	std::cout << "\nProblem 013: " << answer << "\n";
	return true;
}
