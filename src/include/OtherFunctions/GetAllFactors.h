#include <cstdint>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

#ifndef _GETPRIMEFACTORS_
#include "GetPrimeFactors.h"
#endif

#ifndef _GETALLPOSSIBLEPRODUCTS_
#include "GetAllPossibleProducts.h"
#endif

#define _GETALLFACTORS_

void GetAllFactors_FindMatrixPaths(std::map<uint32_t, std::vector<uint32_t> > &factor_matrix, uint32_t &row, uint32_t &input, std::vector<uint32_t> &factors, std::vector<uint32_t> &path)
{
	row++;

	if (row <= factor_matrix.size())
	{
		for (std::vector<uint32_t>::iterator itr = factor_matrix[row].begin(); itr != factor_matrix[row].end(); itr++)
		{
			path.push_back(*itr);

			GetAllFactors_FindMatrixPaths(factor_matrix, row, input, factors, path);

			path.erase(std::remove(path.begin(), path.end(), *itr), path.end());
		}
	}
	else
	{
		if (path.size() != 0)
			GetAllPossibleProducts(input, path, factors);
		else
			factors.push_back(input);
	}

	row--;
}

template<typename T>
std::vector<uint32_t> GetAllFactors(T n)
{
	std::vector<uint32_t> factors, path;
	std::map<uint32_t, uint32_t> prime_factors = GetPrimeFactors(n);
	std::map<uint32_t, std::vector<uint32_t> > factor_matrix;
	uint32_t row = 1;

	for (std::map<uint32_t, uint32_t>::iterator p = prime_factors.begin(); p != prime_factors.end(); p++)
	{
		factor_matrix[row].push_back(p->first);
		factors.push_back(p->first);

		if (p->second > 1)
			for (uint32_t exp = 2; exp <= p->second; exp++)
			{
				factor_matrix[row].push_back(pow(p->first, exp));
				factors.push_back(pow(p->first, exp));
			}

		row++;
	}

	row = 1;

	uint32_t input;
	for (std::map<uint32_t, std::vector<uint32_t> >::iterator itr = factor_matrix.begin(); itr != factor_matrix.end(); itr++)
	{
		for (std::vector<uint32_t>::iterator a = itr->second.begin(); a != itr->second.end(); a++)
		{
			input = *a;
			GetAllFactors_FindMatrixPaths(factor_matrix, row, input, factors, path);
		}
		row++;
	}
	

	factors.push_back(1);
	std::sort(factors.begin(), factors.end());
	factors.erase(std::prev(std::unique(factors.begin(), factors.end()), 1), factors.end());

	return factors;
}