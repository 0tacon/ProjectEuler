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
