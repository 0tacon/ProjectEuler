#include <cstdint>
#include <vector>

#ifndef _ISDIVISIBLE_
	#include "IsDivisible.h"
#endif

#define _COMBINATION_

template<typename T>
uint64_t Combination (T n, T k)
{
	uint64_t comb = 0, numerator = 1, denominator = 1;
	std::vector<uint16_t> num, denom;
	bool factor_cancelled = true;
	
	for (uint16_t i = n; i > k; i--)
		num.push_back(i);
		
	for (uint16_t i = k; i > 0; i--)
		denom.push_back(i);
	
	while (factor_cancelled)
	{
		factor_cancelled = false;
		
		for (uint16_t a = 0; a < num.size(); a++)
			for (uint16_t b = 0; b < denom.size(); b++)
			{
				if (num[a] != 1 && denom[b] != 1)
				{
					if (IsDivisible(num[a], denom[b]))
					{
						num[a] = num[a] / denom[b];
						denom[b] = 1;
						factor_cancelled = true;
					}
					else if (num[a] == denom[b])
					{
						num[a] = 1;
						denom[b] = 1;
						factor_cancelled = true;
					}
				}
			}
	}
	
	for (std::vector<uint16_t>::iterator n = num.begin(); n != num.end(); n++)
		numerator *= *n;
	
	for (std::vector<uint16_t>::iterator d = denom.begin(); d != denom.end(); d++)
		denominator *= *d;
		
	comb = numerator / denominator;
	
	return comb;
}
