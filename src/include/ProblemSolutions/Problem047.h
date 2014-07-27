/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

/*
    The first two consecutive numbers to have two distinct prime factors are:

    14 = 2 × 7
    15 = 3 × 5

    The first three consecutive numbers to have three distinct prime factors are:

    644 = 2² × 7 × 23
    645 = 3 × 5 × 43
    646 = 2 × 17 × 19.

    Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/

#include <cstdint>
#include <cstdio>
#include <vector>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

#ifndef _GETPRIMEFACTORS_
#include "../OtherFunctions/GetPrimeFactors.h"
#endif // _GETPRIMEFACTORS_

bool Problem47()
{
    std::vector<uint32_t> answers, primes_under_1000 = GetAllPrimesBelow(1000);
    std::map<uint32_t, uint32_t> prime_factors;
    uint32_t min = 647, max = 200000, num_factors = 4;

    for (uint32_t i = min; i < max; i++)
    {
        bool ans_found = false;

        prime_factors = GetPrimeFactors(i, primes_under_1000);

        if (prime_factors.size() == num_factors)
        {
            ans_found = true;

            for (uint32_t temp = i + 1; temp < i + num_factors; temp++)
            {
                prime_factors = GetPrimeFactors(temp, primes_under_1000);

                if (prime_factors.size() != num_factors)
                    ans_found = false;
            }
        }

        if (ans_found)
        {
            for (uint32_t temp = i; temp < i + num_factors; temp++)
                answers.push_back(temp);

            i = max;
        }
    }

    std::printf("\nProblem 047: %d\n", answers[0]);
    return true;
}
