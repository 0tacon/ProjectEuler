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
	Find the greatest product of thirteen consecutive digits in the 1000-digit number stored in Problem8.txt
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif

bool Problem8 ()
{
	std::vector<uint8_t> vect, temp;
	uint64_t product=0, largest_product=0;
	std::string filepath = "../../data/Problem8.txt";

	ReadFileIntoVect (vect, filepath);
	vect.erase(std::remove(vect.begin(), vect.end(), 13), vect.end());
    vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
	for (uint32_t i = 0; i < vect.size(); i++)
        vect[i] -= 48;

	temp.resize(13);

	for ( uint16_t i = 0 ; i < 996 ; i++ )
	{
		std::copy ( vect.begin()+i, vect.begin()+i+13, temp.begin() );

		product = 1;
		for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
		{
			product = product*(*itr);
		}
		if (product>largest_product) largest_product = product;
	}

	std::cout << "\nProblem 008: " << largest_product << "\n";

	return true;
}
