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
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <map>

bool Problem5 ()
{
	uint32_t ans=1;
	std::vector<uint8_t> primes_under_twenty = {2,3,5,7,11,13,17,19};
	std::map<uint8_t, uint8_t> factor_frequency;
	uint8_t temp, count;

	for (std::vector<uint8_t>::iterator n=primes_under_twenty.begin(); n!=primes_under_twenty.end(); n++)	factor_frequency[*n] = 0;

	for (uint8_t i=2; i<21; i++)
	{
		temp = i;
		for (std::vector<uint8_t>::iterator n=primes_under_twenty.begin(); n!=primes_under_twenty.end(); n++)
		{
			count = 0;
			while(temp%*n==0)
			{
				temp = temp / *n;
				count++;
			}
			if (count>factor_frequency[*n]) factor_frequency[*n] = count;
		}
	}

	for (std::vector<uint8_t>::iterator n=primes_under_twenty.begin(); n!=primes_under_twenty.end(); n++)	ans *= pow(*n, factor_frequency[*n]);

	std::cout << "\nProblem 005: " << ans << "\n";

	return true;
}
