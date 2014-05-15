#include <cstdint>
#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include <map>

#ifndef _ISDIVISIBLE_
	#include "IsDivisible.hpp"
	#define _ISDIVISIBLE_
#endif

#ifndef _GETALLPRIMESBELOW_
	#include "GetAllPrimesBelow.hpp"
	#define _GETALLPRIMESBELOW_
#endif

template<typename T>
uint16_t GetNumDivisors (T n)
{
	uint16_t divisors = 1, temp = static_cast<uint64_t>(n);
	std::vector<uint64_t> primes;
	std::map<uint64_t, uint64_t> prime_factors;
	
	primes = GetAllPrimesBelow(n);
	
	primes.erase(std::remove_if(primes.begin(), primes.end(), std::bind(IsNotDivisible, n, std::placeholders::_1)), primes.end());
	
	for (std::vector<uint64_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
	{
		prime_factors[*prime] = 0;
		while(IsDivisible(temp, *prime) || temp == *prime)
		{
			temp = temp/ *prime;
			prime_factors[*prime]++;
		}
	}
	
	for (std::map<uint64_t, uint64_t>::iterator factor = prime_factors.begin(); factor != prime_factors.end(); factor++)
		divisors *= (factor->second+1);
	
	return divisors;
}
