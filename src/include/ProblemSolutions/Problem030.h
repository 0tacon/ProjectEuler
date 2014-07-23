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
    uint8_t exp = 5;
    std::map<uint8_t, uint16_t> v;
    std::vector<uint64_t> vect, results, temp_vect;
    std::vector<std::pair<uint64_t, std::vector<uint64_t> > > sums;
    std::string str1, str2;
    uint64_t ans = 0;

    for (uint8_t i = 1; i != 10; i++)
        v[i] = pow(i,exp);

    for (std::map<uint8_t, uint16_t>::iterator i = v.begin(); i != v.end(); i++)
        vect.push_back(i->second);

    GetAllPossibleSums(vect, sums);

    for (std::vector<uint64_t>::iterator i = vect.begin(); i != vect.end(); i++)
    {
        temp_vect.push_back(*i);

        GetAllPossibleSums(vect, sums, temp_vect);

        for (std::vector<uint64_t>::iterator j = std::next(i, 1); j != vect.end(); j++)
        {
            temp_vect.push_back(*j);

            GetAllPossibleSums(vect, sums, temp_vect);

            temp_vect.erase(std::prev(temp_vect.end(), 1), temp_vect.end());
        }

        temp_vect.push_back(*i);

        GetAllPossibleSums(vect, sums, temp_vect);

        temp_vect.erase(temp_vect.begin(), temp_vect.end());
    }

    for (std::vector<std::pair<uint64_t, std::vector<uint64_t> > >::iterator itr = sums.begin(); itr != sums.end(); itr++)
    {
        for (uint64_t i = 0; i < itr->second.size(); i++)
            itr->second.at(i) = pow(itr->second.at(i), static_cast<float>(static_cast<float>(1.0)/exp));

        str1 = std::to_string(itr->first);

        for (std::vector<uint64_t>::iterator n = itr->second.begin(); n != itr->second.end(); n++)
            str2 += std::to_string(*n);

        if (std::count(str1.begin(), str1.end(), '0') > 0)
            for (uint8_t i = 0; i < std::count(str1.begin(), str1.end(), '0'); i++)
                str2 += '0';

        if (std::is_permutation(str1.begin(), str1.end(), str2.begin()) && str1.size() == str2.size())
            if (std::count(results.begin(), results.end(), itr->first) == 0)
                results.push_back(itr->first);

        str2 = "";
    }

    for (std::vector<uint64_t>::iterator i = results.begin(); i != results.end(); i++)
        ans += *i;

    printf("\nProblem 030: %lu\n", ans);
    return true;
}
