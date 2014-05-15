#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#ifndef _ISDIVISIBLE_
	#include "IsDivisible.hpp"
	#define _ISDIVISIBLE_
#endif

template<typename T>
uint64_t GetSumPrimesBelow (T max)
{
	uint64_t sum = 2;
	
	if (max < 2) return 0;
	else if ( max == 2 ) return 2;
	else
	{
		std::vector<uint64_t> primes;
		primes.reserve(max);
		
		for (uint64_t i = 3; i < max; i+=2) primes.push_back(i);
		
		for (std::vector<uint64_t>::iterator n = primes.begin(); n != primes.end() && *n < sqrt(max); n++)
			if (*n != 0)
				std::replace_if(primes.begin(), primes.end(), std::bind(IsDivisible, std::placeholders::_1, (*n)), 0);
			
		primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
		
		for (std::vector<uint64_t>::iterator n = primes.begin(); n != primes.end(); n++) sum += *n;
		return sum;
	}
}
