#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#ifndef _GETALLPRIMESBELOW_
	#include "GetAllPrimesBelow.h"
#endif

#define _GETPRIMENUMBER_

template<typename T>
uint64_t GetPrimeNumber (T prime_pos)
{
	if (prime_pos == 1 || prime_pos == 2) return prime_pos+1;
	else
	{
		uint64_t max = 110000;
		std::vector<uint64_t> primes;
		primes.reserve(max);
		
		primes = GetAllPrimesBelow(max);
		
		if (prime_pos<=primes.size()) return primes.at(prime_pos-1);
		else
		{
			std::cout << "Error: prime number requested is not less than 110,000!";
			return 0;
		}
	}
}
