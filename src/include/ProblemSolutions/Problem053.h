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
	There are exactly ten ways of selecting three from five, 12345:

	123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

	In combinatorics, we use the notation, 5C3 = 10.

	In general,
	nCr = (n!)/(r!(n−r)!), where r <= n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

	It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

	How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100, are greater than one-million?
*/

#include <cstdio>
#include <cstdint>

#ifndef _COMBINATION_
#include "../OtherFunctions/Combination.h"
#endif //_COMBINATION_

bool Problem53()
{
	uint64_t combo, num_total_combos = 0;
	bool overflow_flag = false;

	for (uint8_t n = 1; n <= 100; n++)
	{
		uint8_t start_num;
		if (n % 2 == 0)
			start_num = n / 2;
		else
			start_num = (n + 1) / 2;

		uint64_t num_current_combos = 0;

		for (uint8_t k = start_num; k < n; k++)
		{
			combo = Combination(n, k, overflow_flag);

			if (combo > 1000000 || overflow_flag)
			{
				num_current_combos++;
				overflow_flag = false;
			}
			else
				break;
		}

		if (num_current_combos != 0)
		{
			num_current_combos *= 2;
			if (n % 2 == 0)
				num_current_combos -= 1;


			num_total_combos += num_current_combos;
		}
	}

	std::printf("\nProblem 053: %lu\n", num_total_combos);
	return true;
}