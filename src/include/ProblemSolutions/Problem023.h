/*
	A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

#ifndef _SUMALLFACTORS_
#include "..\\OtherFunctions\\SumAllFactors.h"
#endif

bool Problem23()
{
	uint32_t max = 28123;
	uint64_t sum = 0;
	std::map<uint32_t, uint64_t> Divisors_Below_Max;
	std::vector<uint32_t> abundant_numbers, sums_of_abundants, non_abundants;

	for (uint32_t i = 1; i <= max; i++)
		Divisors_Below_Max[i] = SumAllFactors(i);

	for (std::map<uint32_t, uint64_t>::iterator a = Divisors_Below_Max.begin(); a != Divisors_Below_Max.end(); a++)
		if (a->first < a->second)
			abundant_numbers.push_back(a->first);

	for (std::vector<uint32_t>::iterator a = abundant_numbers.begin(); a != abundant_numbers.end(); a++)
		for (std::vector<uint32_t>::iterator b = std::next(a, 0); b != abundant_numbers.end(); b++)
			if (*a + *b <= max)
				sums_of_abundants.push_back(*a + *b);

	for (uint32_t a = 1; a <= max; a ++)
		non_abundants.push_back(a);

	for (std::vector<uint32_t>::iterator a = sums_of_abundants.begin(); a != sums_of_abundants.end(); a++)
		non_abundants.erase(std::remove(non_abundants.begin(), non_abundants.end(), *a), non_abundants.end());

	for (std::vector<uint32_t>::iterator a = non_abundants.begin(); a != non_abundants.end(); a++)
		sum += *a;

	std::cout << "\nProblem 023: " << sum << "\n";
	return true;
}