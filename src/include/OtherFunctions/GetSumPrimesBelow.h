#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#ifndef _GETALLPRIMESBELOW_
	#include "GetAllPrimesBelow.h"
#endif

#define _GETSUMPRIMESBELOW_

template<typename T>
uint64_t GetSumPrimesBelow (T max)
{
	uint64_t sum = 0;
	std::vector<uint32_t> primes;
	primes.reserve(max);
	
	primes = GetAllPrimesBelow(max);
	
	for (std::vector<uint32_t>::iterator n = primes.begin(); n != primes.end(); n++) sum += *n;
	
	return sum;
}
