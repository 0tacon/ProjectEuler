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
uint64_t GetPrimeNumber (T prime_pos)
{
	if (prime_pos == 1 || prime_pos == 2) return prime_pos+1;
	else
	{
		uint64_t max = 110000;
		std::vector<uint64_t> primes;
		primes.reserve(max);
		
		for (uint64_t i = 3; i < max; i+=2) primes.push_back(i);
		
		for (std::vector<uint64_t>::iterator n = primes.begin(); n != primes.end() && *n < sqrt(max); n++)
			if (*n != 0)
				std::replace_if(primes.begin(), primes.end(), std::bind(IsDivisible, std::placeholders::_1, (*n)), 0);
			
		primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
		
		if (prime_pos-2<primes.size()) return primes.at(prime_pos-2);
		else
		{
			std::cout << "Error: prime number requested is not less than 110,000!";
			return 0;
		}
	}
}
