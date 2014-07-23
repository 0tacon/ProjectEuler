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
	Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <cstdint>
#include <vector>

#ifndef _SUMALLFACTORS_
#include "../OtherFunctions/SumAllFactors.h"
#endif

bool Problem21()
{
	std::map<uint32_t, uint64_t> Divisors_Below_10000;
	uint64_t sum_amicable_nums = 0;

	for (uint32_t i = 1; i < 10000; i++)
		Divisors_Below_10000[i] = SumAllFactors(i);

	for (std::map<uint32_t, uint64_t>::iterator a = Divisors_Below_10000.begin(); a != Divisors_Below_10000.end(); a++)
		for (std::map<uint32_t, uint64_t>::iterator b = Divisors_Below_10000.begin(); b != Divisors_Below_10000.end(); b++)
			if (a->first != b->first && a->first == b->second && a->second == b->first)
				sum_amicable_nums += a->first + a->second;

	sum_amicable_nums /= 2;

	std::cout << "\nProblem 021: " << sum_amicable_nums << "\n";
	return true;
}
