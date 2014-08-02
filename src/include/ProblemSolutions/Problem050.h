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
    The prime 41, can be written as the sum of six consecutive primes:
    41 = 2 + 3 + 5 + 7 + 11 + 13

    This is the longest sum of consecutive primes that adds to a prime below one-hundred.

    The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

    Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem50()
{
    uint32_t sum, result, max = 1000000;
    std::vector<uint32_t> primes = GetAllPrimesBelow(max), sum_primes, result_primes;

    while (primes.size() > result_primes.size())
    {
        sum = 0;
        sum_primes.clear();

        for (std::vector<uint32_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
        {
            sum += *prime;
            sum_primes.push_back(*prime);

            if (sum >= max)
                break;
            else if (std::count(primes.begin(), primes.end(), sum) == 1 && sum_primes.size() > result_primes.size())
            {
                result = sum;
                result_primes = sum_primes;
            }
        }

        primes.erase(primes.begin(), std::next(primes.begin(), 1));
    }

    std::printf("\nProblem 050: %d\n", result);
    return true;
}
