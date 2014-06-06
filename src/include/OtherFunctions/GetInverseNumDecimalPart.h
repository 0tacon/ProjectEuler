#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>

#ifndef _FINDLARGESTREPEATEDSET_
#include "../OtherFunctions/FindLargestRepeatedSet.h"
#endif

#define _GETINVERSENUMDECIMALPART_

std::vector<uint16_t> GetInverseNumDecimalPart (uint16_t denom)
{
    uint16_t temp = 1, num = 1, rem = num, c = 0;
    std::vector<uint16_t> ans, prev_nums = {1};
    bool recurrance_found = false;

    while (!recurrance_found && c < 1000)
    {
        temp = rem;
        rem = (10*temp)%denom;
        num = ((10*temp) - rem)/denom;

        if (std::count(prev_nums.begin(), prev_nums.end(), rem) > 0)
            recurrance_found = true;
        else
            prev_nums.push_back(rem);

        ans.push_back(num);

        c++;
    }
    uint16_t max = ans.size();
    for (uint16_t i = 0; i < max; i++)
    {
        temp = rem;
        rem = (10*temp)%denom;
        num = ((10*temp) - rem)/denom;
        ans.push_back(num);
    }

    /*std::cout << "\nans = ";
    PrintVector(ans);
    std::cout << "\nans.size = " << ans.size() << "\n";*/

    ans = FindLargestRepeatedSet(ans);

    return ans;
}
