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
    Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13

    It can be verified that the sum of the numbers on the diagonals is 101.

    What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <cstdint>
#include <cstdio>

bool Problem28()
{
    uint32_t spacing = 2, appends = 0;
    uint64_t sum = 1;

    for (uint32_t i = 1; i < 1002001; i++)
    {
        if (i%spacing == 0)
        {
            sum += i+1;

            appends++;

            if (appends == 4)
            {
                appends = 0;
                spacing += 2;
            }
        }
    }

    printf("\nProblem 028: %lu\n", sum);
    return true;
}
