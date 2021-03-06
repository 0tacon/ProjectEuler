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
    The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

    Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

    (Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

#include "../OtherFunctions/IsPalendrome.h"

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif // _PRINTVECTOR_

bool Problem36()
{
    std::vector<uint32_t> palendromes, powers_of_2;
    uint64_t binary, num, sum = 0;
    uint32_t temp;

    for (uint8_t i = 0; i < 20; i++)
        powers_of_2.push_back(pow(2, i));

    for (uint32_t i = 1; i < 1000001; i+=2)
        if (IsPalendrome(i))
        {
            temp = i;
            binary = 0;

            for (int8_t a = 19; a >= 0 && temp != 0; a--)
                if (temp >= powers_of_2[a])
                {
                    temp -= powers_of_2[a];

                    num = pow(10, a);

                    binary += num;
                }

            if (IsPalendrome(binary))
                palendromes.push_back(i);
        }

    for (std::vector<uint32_t>::iterator itr = palendromes.begin(); itr != palendromes.end(); itr++)
        sum += *itr;

    printf("\nProblem 036: %lu\n", sum);
    return true;
}
