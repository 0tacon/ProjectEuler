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

#include <cstdint>
#include <cmath>

#define _COUNTHIGHBITS_

template<typename T>
T CountHighBits(T n, uint8_t bit_length)
{
	uint8_t num_high_bits=0;
	T limit = 1+pow(2,bit_length-1);

	T i = 1;
	while(i<limit)
	{
		if ( (n&i) == i )	num_high_bits++;
		i = pow(2,log2(i)+1);
	}

	return num_high_bits;
}
