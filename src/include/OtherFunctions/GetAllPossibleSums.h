#include <cstdint>
#include <vector>
#include <iostream>

#define _GETALLPOSSIBLESUMS_

#ifndef _PRINTVECTOR_
#include "PrintVector.h"
#endif

template<typename T>
void GetAllPossibleSums_RecursiveLoop(T n, std::vector<T> v, std::vector<T> &sums)
{
    std::vector<T> temp(v.size()-1);

    for (typename std::vector<T>::iterator a = v.begin(); a != v.end(); a++)
    {
        /*std::cout << "n = " << n << "\n";
        std::cout << "v.size() = " << v.size() << "\n";
        std::cout << "a = " << *a << "\n";*/

        if (n != 0)
            sums.push_back(n + *a);

        if (v.size() > 1 && a != std::prev(v.end(), 1))
        {
            //std::copy(std::next(a, 1), v.end(), temp.begin());
            temp = v;
            temp.erase(temp.begin(), std::next(std::find(temp.begin(), temp.end(), *a), 1));

            //std::cout << "temp.size() = " << temp.size() << "\n";
            //PrintVector(temp); std::cout << "\n\n";

            GetAllPossibleSums_RecursiveLoop(static_cast<T>(n + *a), temp, sums);

            temp.clear();
        }
    }
}

template<typename T>
std::vector<T> GetAllPossibleSums(std::vector<T> v)
{
    std::vector<T> sums;

    GetAllPossibleSums_RecursiveLoop(static_cast<T>(0), v, sums);

    return sums;
}
