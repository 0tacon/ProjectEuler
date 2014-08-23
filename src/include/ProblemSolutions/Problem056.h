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
	A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

	Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
*/

#include <cstdint>
#include <cstdio>

#include "../Classes/StringNum.h"

bool Problem56()
{
	uint64_t largest_sum_digits = 0;
	StringNum max("101.000000"), unity("1.000000"), result;

	for (StringNum base = unity; !(base == max); base = base + unity)
	{
		for (StringNum exp = unity; !(exp == max); exp = exp + unity)
		{
			result = base^exp;
			
			uint64_t sum_digits = result.SumDigits();

			if (sum_digits > largest_sum_digits)
				largest_sum_digits = sum_digits;
		}
	}

	std::printf("\nProblem 056: %lu\n", largest_sum_digits);
	return true;
}