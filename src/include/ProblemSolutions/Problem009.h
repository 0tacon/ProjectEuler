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
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a^2 + b^2 = c^2
	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include <iostream>
#include <cstdint>
#include <cmath>

bool Problem9 ()
{
	uint16_t b=1, a=1;
	uint32_t product;
	bool triplet_found = false;

	while ( a<500 && !triplet_found )
	{
		b = 1;
		while ( b<500 && !triplet_found )
		{
			if ( a + b + sqrt(a*a + b*b) == 1000 ) triplet_found = true;
			else b++;
		}
		if ( !triplet_found ) a++;
	}

	product = a*b*sqrt(a*a + b*b);

	std::cout 	<< "\nProblem 009: " << product << "\n";

	return true;
}
