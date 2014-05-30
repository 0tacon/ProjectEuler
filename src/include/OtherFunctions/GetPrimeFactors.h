#include <cstdint>
#include <cmath>
#include <functional>
#include <vector>
#include <map>

#ifndef _ISDIVISIBLE_
#include "IsDivisible.h"
#endif

#ifndef _GETALLPRIMESBELOW_
#include "GetAllPrimesBelow.h"
#endif

#define _GETPRIMEFACTORS_

template<typename T>
std::map<uint32_t, uint32_t> GetPrimeFactors(T n)
{
	uint32_t temp = static_cast<uint32_t>(n), new_n = static_cast<uint32_t>(n);
	std::vector<uint32_t> primes, primes_under_1000 = GetAllPrimesBelow(1000), prime_factors_under_1000;
	std::map<uint32_t, uint32_t> prime_factors;

	for (std::vector<uint32_t>::iterator p = primes_under_1000.begin(); p != primes_under_1000.end(); p++)
	if (IsDivisible(n, *p))
		prime_factors_under_1000.push_back(*p);

	for (std::vector<uint32_t>::iterator p = prime_factors_under_1000.begin(); p != prime_factors_under_1000.end(); p++)
	while (IsDivisible(new_n, *p) && new_n / *p > sqrt(n))
		new_n /= *p;

	new_n++;
	primes = GetAllPrimesBelow(new_n);

	primes.erase(std::remove_if(primes.begin(), primes.end(), std::bind(IsNotDivisible, n, std::placeholders::_1)), primes.end());

	for (std::vector<uint32_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
	{
		prime_factors[*prime] = 0;
		while (IsDivisible(temp, *prime) || temp == *prime)
		{
			temp = temp / *prime;
			prime_factors[*prime]++;
		}
	}

	return prime_factors;
}