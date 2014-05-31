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
#include "..\\OtherFunctions\\SumAllFactors.h"
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