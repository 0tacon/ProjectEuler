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

#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif

#define _FINDLARGESTREPEATEDSET_

template<typename T>
std::vector<T> FindLargestRepeatedSet (std::vector<T> vect)
{
    bool repetition_found = false;
    uint16_t i = 0;

    if (vect.size()%2 != 0)
        vect.erase(vect.begin(), std::next(vect.begin(), 1));

    std::vector<T> set1(vect.size()/2), set2(vect.size()/2);

    while (!repetition_found)
    {
        std::copy(std::next(vect.begin(), i + vect.size()/2), vect.end(), set1.begin());

        std::copy(std::next(vect.begin(), 2*i), std::next(vect.begin(), i + vect.size()/2), set2.begin());

        if (i != 0)
        {
            set1.erase(std::prev(set1.end(), 1), set1.end());
            set2.erase(std::prev(set2.end(), 1), set2.end());
        }

        /*std::cout << "\nset1 = ";
        PrintVector(set1);
        std::cout << "\nset2 = ";
        PrintVector(set2);
        std::cout << "\n";*/

        if (set1 == set2)
            repetition_found = true;

        i++;
    }

    return set1;
}
