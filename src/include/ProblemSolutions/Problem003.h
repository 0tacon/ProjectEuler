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
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <cstdint>
#include <cmath>

bool Problem3 ()
{
	bool prime_found = false, is_prime = true;
	uint64_t start_of_search, num_for_factorising = 600851475143, largest_prime=0;

	start_of_search = sqrt(static_cast<double>(num_for_factorising));

	uint64_t i = start_of_search;
	while ( i>2 && !prime_found )
	{
		if ( num_for_factorising%i==0 && i%2!=0 )
		{
			uint64_t j = 2;
			while ( j<i && is_prime )
			{
				if ( i%j==0 )
				{
					is_prime = false;
				}
				j++;
			}
			if ( is_prime )
			{
				largest_prime = i;
				prime_found = true;
			}
			is_prime = true;
		}
		i--;
	}

	std::cout << "\nProblem 003: " << largest_prime << "\n";

	return true;
}
