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

#define _GETSUMPRIMESBELOW_

template<typename T>
uint64_t GetSumPrimesBelow (T max)
{
	uint64_t sum = 0;
	std::vector<uint32_t> primes;
	primes.reserve(max);

	primes = GetAllPrimesBelow(max);

	for (std::vector<uint32_t>::iterator n = primes.begin(); n != primes.end(); n++) sum += *n;

	return sum;
}
