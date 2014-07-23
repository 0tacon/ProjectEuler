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

#include <vector>
#include <cmath>
#include <iostream>

#define _EXTRACTNDIGITNUMS_

template<typename T, typename t>
void ExtractNDigitNums (std::vector<T> &v, t n)
{
	if (fmod(v.size(), n) != 0.0)
	{
		std::cout << "\nError: Vector size is not an integer multiple of n.\n";
	}
	else
	{
		std::vector<T> temp_vect;
		T temp_num=0;

		for (t i = 0; i < v.size()-n+1; i+=n)
		{
			temp_num=0;

			for (t j = 1; j < n+1; j++)
				temp_num += v[i+(j-1)]*pow(10, n-j);

			temp_vect.push_back(temp_num);
		}

		v = temp_vect;
	}
}
