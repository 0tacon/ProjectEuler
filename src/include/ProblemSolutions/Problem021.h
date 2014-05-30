/*
	Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <cstdint>
#include <vector>

#ifndef _GETALLFACTORS_
#include "..\\OtherFunctions\\GetAllFactors.h"
#endif

bool Problem21()
{
	std::vector<uint32_t> factors = GetAllFactors(284);
	std::map<uint32_t, uint32_t> prime_factors = GetPrimeFactors(16200);

	PrintVector(factors);

	for (std::map<uint32_t, uint32_t>::iterator factor = prime_factors.begin(); factor != prime_factors.end(); factor++)
		std::cout << "\nfactor = " << factor->first << ", exp = " << factor->second;

	std::cout << "\nProblem 021: " << "\n";
	return true;
}