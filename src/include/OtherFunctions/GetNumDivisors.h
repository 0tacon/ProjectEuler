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
#include <map>

#ifndef _GETPRIMEFACTORS_
#include "GetPrimeFactors.h"
#endif

#define _GETNUMDIVISORS_

template<typename T>
uint16_t GetNumDivisors (T n)
{
	uint16_t divisors = 1;
	std::map<uint32_t, uint32_t> prime_factors = GetPrimeFactors(n);

	for (std::map<uint32_t, uint32_t>::iterator factor = prime_factors.begin(); factor != prime_factors.end(); factor++)
		divisors *= (factor->second+1);

	return divisors;
}
