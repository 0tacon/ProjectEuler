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
