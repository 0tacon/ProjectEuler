#include <cstdint>
#include <vector>

#ifndef _GETALLFACTORS_
#include "GetAllFactors.h"
#endif

#define _SUMALLFACTORS_

template<typename T>
uint64_t SumAllFactors(T n)
{
	uint64_t sum = 0;
	std::vector<uint32_t> factors = GetAllFactors(n);

	for (std::vector<uint32_t>::iterator i = factors.begin(); i != factors.end(); i++)
		sum += *i;

	return sum;
}