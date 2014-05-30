#include <cstdint>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

#ifndef _GETPRIMEFACTORS_
#include "GetPrimeFactors.h"
#endif

#define _GETALLFACTORS_

template<typename T>
std::vector<uint32_t> GetAllFactors(T n)
{
	std::vector<uint32_t> factors;
	std::map<uint32_t, uint32_t> prime_factors = GetPrimeFactors(n);

	factors.push_back(1);
	std::sort(factors.begin(), factors.end());

	return factors;
}