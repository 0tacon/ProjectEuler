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
    The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

    There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

    How many circular primes are there below one million?
*/

#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem35()
{
    std::vector<uint32_t> primes_below_1000000 = GetAllPrimesBelow(1000000), circular_primes, test_case;
    std::string str_a, str_b;
    bool is_circular_prime = true;

    for (std::vector<uint32_t>::iterator a = primes_below_1000000.begin(); a != primes_below_1000000.end(); a++)
    {
        if(std::count(circular_primes.begin(), circular_primes.end(), *a) == 0)
        {
            test_case.clear();
            str_a = std::to_string(*a);
            str_b = str_a;

            for (uint8_t i = 0; i < str_a.size(); i++)
            {
                test_case.push_back(std::stoi(str_b));

                for (uint8_t j = 0; j < str_a.size(); j++)
                    str_b[(j+1)%str_a.size()] = str_a[j];

                str_a = str_b;
            }

            is_circular_prime = true;

            for (std::vector<uint32_t>::iterator itr = test_case.begin(); itr != test_case.end(); itr++)
                if (std::count(primes_below_1000000.begin(), primes_below_1000000.end(), *itr) == 0)
                    is_circular_prime = false;

            if (is_circular_prime)
                for (std::vector<uint32_t>::iterator itr = test_case.begin(); itr != test_case.end(); itr++)
                    if (std::count(circular_primes.begin(), circular_primes.end(), *itr) == 0)
                        circular_primes.push_back(*itr);
        }
    }

    printf("\nProblem 035: %lu\n", circular_primes.size());
    return true;
}
