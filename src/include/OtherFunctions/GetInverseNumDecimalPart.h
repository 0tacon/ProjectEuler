#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>

#define _GETINVERSENUMDECIMALPART_

std::vector<uint16_t> GetInverseNumDecimalPart (uint16_t denom)
{
    uint16_t temp = 1, num = 1, rem = num;
    std::vector<uint16_t> ans, prev_nums = {1};
    bool recurrance_found = false;

    while (!recurrance_found)
    {
        temp = rem;
        rem = (10*temp)%denom;
        num = ((10*temp) - rem)/denom;

        if (std::count(prev_nums.begin(), prev_nums.end(), rem) > 0)
            recurrance_found = true;
        else
            prev_nums.push_back(rem);

        ans.push_back(num);
    }
    uint16_t max = ans.size();
    for (uint16_t i = 0; i < max; i++)
    {
        temp = rem;
        rem = (10*temp)%denom;
        num = ((10*temp) - rem)/denom;
        ans.push_back(num);
    }

    return ans;
}
