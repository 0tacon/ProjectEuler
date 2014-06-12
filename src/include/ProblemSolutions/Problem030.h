/*
    Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

        1634 = 1^4 + 6^4 + 3^4 + 4^4
        8208 = 8^4 + 2^4 + 0^4 + 8^4
        9474 = 9^4 + 4^4 + 7^4 + 4^4

    As 1 = 1^4 is not a sum it is not included.

    The sum of these numbers is 1634 + 8208 + 9474 = 19316.

    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

#ifndef _GETALLPOSSIBLESUMS_
#include "../OtherFunctions/GetAllPossibleSums.h"
#endif

bool Problem30()
{
    std::map<uint8_t, uint16_t> v;
    std::vector<uint32_t> vect;
    std::vector<std::pair<uint32_t, std::vector<uint32_t> > > sums;
    std::string str1, str2;

    for (uint8_t i = 1; i != 10; i++)
        v[i] = pow(i,4);

    for (std::map<uint8_t, uint16_t>::iterator i = v.begin(); i != v.end(); i++)
        vect.push_back(i->second);

    sums = GetAllPossibleSums(vect);

    for (std::vector<std::pair<uint32_t, std::vector<uint32_t> > >::iterator itr = sums.begin(); itr != sums.end(); itr++)
    {
        for (uint32_t i = 0; i < itr->second.size(); i++)
            itr->second.at(i) = pow(itr->second.at(i), 0.25);

        str1 = std::to_string(itr->first);

        for (std::vector<uint32_t>::iterator n = itr->second.begin(); n != itr->second.end(); n++)
            str2 += std::to_string(*n);

        if (std::is_permutation(str1.begin(), str1.end(), str2.begin()) && str1.size() == str2.size())
            printf("\nsum = %s, nums = %s", str1.c_str(), str2.c_str());

        str2 = "";
    }

    printf("\nProblem 030: \n");
    return true;
}
