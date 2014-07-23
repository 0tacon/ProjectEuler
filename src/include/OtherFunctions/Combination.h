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
    Computes the combination: n choose k

    n choose k = n!/(k!(n-k)!) = (n(n-1)...(n-k+1))/(k(k-1)...1)
*/

#include <cstdint>
#include <vector>

#ifndef _ISDIVISIBLE_
	#include "IsDivisible.h"
#endif

#define _COMBINATION_

template<typename T>
uint64_t Combination (T n, T k)
{
	uint64_t comb = 0, numerator = 1, denominator = 1;
	std::vector<uint16_t> num, denom;
	bool factor_cancelled = true;

	// Fill the numerator product vector with all nums from n-k+1 to n
	for (uint16_t i = n; i > k; i--)
		num.push_back(i);

    // Fill the denominator product vector with all nums from 1 to k
	for (uint16_t i = k; i > 0; i--)
		denom.push_back(i);

	// Cancel out all common factors in numerator and denominator product vectors
	while (factor_cancelled)
	{
		factor_cancelled = false;

		for (uint16_t a = 0; a < num.size(); a++)
			for (uint16_t b = 0; b < denom.size(); b++)
			{
				if (num[a] != 1 && denom[b] != 1)
				{
					if (IsDivisible(num[a], denom[b]))
					{
						num[a] = num[a] / denom[b];
						denom[b] = 1;
						factor_cancelled = true;
					}
					else if (num[a] == denom[b])
					{
						num[a] = 1;
						denom[b] = 1;
						factor_cancelled = true;
					}
				}
			}
	}

	// Compute the actual numertor
	for (std::vector<uint16_t>::iterator n = num.begin(); n != num.end(); n++)
		numerator *= *n;

	// Compute the actual denominator
	for (std::vector<uint16_t>::iterator d = denom.begin(); d != denom.end(); d++)
		denominator *= *d;

    // Calculate the combination
	comb = numerator / denominator;

	return comb;
}
