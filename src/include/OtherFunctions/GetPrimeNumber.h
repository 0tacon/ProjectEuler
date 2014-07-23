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
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#ifndef _GETALLPRIMESBELOW_
	#include "GetAllPrimesBelow.h"
#endif

#define _GETPRIMENUMBER_

template<typename T>
uint32_t GetPrimeNumber (T prime_pos)
{
	if (prime_pos == 1 || prime_pos == 2) return prime_pos+1;
	else
	{
		uint32_t max = 110000;
		std::vector<uint32_t> primes;
		primes.reserve(max);

		primes = GetAllPrimesBelow(max);

		if (prime_pos<=primes.size()) return primes.at(prime_pos-1);
		else
		{
			std::cout << "Error: prime number requested is not less than 110,000!";
			return 0;
		}
	}
}
