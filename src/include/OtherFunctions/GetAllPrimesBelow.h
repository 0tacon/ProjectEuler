#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#ifndef _ISDIVISIBLE_
	#include "IsDivisible.h"
#endif

#define _GETALLPRIMESBELOW_

template<typename T>
std::vector<uint64_t> GetAllPrimesBelow (T max)
{
	std::vector<uint64_t> primes;
	primes.reserve(max);
	
	if (max < 2) return primes;
	else if ( max == 2 ) 
	{
		primes.push_back(2.0);
		return primes;
	}
	else
	{
		for (uint64_t i = 3; i < max; i+=2) primes.push_back(i);
		
		for (std::vector<uint64_t>::iterator n = primes.begin(); n != primes.end() && *n < sqrt(max); n++)
			if (*n != 0)
				std::replace_if(n, primes.end(), std::bind(IsDivisible, std::placeholders::_1, (*n)), 0);
			
		primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
		
		primes.insert(primes.begin(), 2);
		return primes;
	}
}

template<typename T>
void AppendAllPrimesBetween (T start, T end, std::vector<uint64_t> &primes)
{
	if (IsDivisible(start, 2))
		start++;
	
	for (uint64_t i = start; i <= end; i+=2) primes.push_back(i);
	
	for (std::vector<uint64_t>::iterator n = primes.begin(); n != primes.end() && *n < sqrt(end); n++)
			if (*n != 0)
				std::replace_if(n, primes.end(), std::bind(IsDivisible, std::placeholders::_1, (*n)), 0);
				
	primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
}
