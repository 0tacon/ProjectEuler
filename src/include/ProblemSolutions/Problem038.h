/*
    Take the number 192 and multiply it by each of 1, 2, and 3:

        192 × 1 = 192
        192 × 2 = 384
        192 × 3 = 576

    By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

    The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

    What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

bool Problem38()
{
    std::string str, ref_str = "123456789";
    uint16_t i = 0;
    std::vector<uint32_t> results;

    for (uint16_t n = 1; n < 10000; n++)
    {
        str = std::to_string(n);

        i = 2;

        while (str.size() < 9)
        {
            str += std::to_string(n*i);
            i++;
        }

        if (str.size() == 9 && std::is_permutation(ref_str.begin(), ref_str.end(), str.begin()))
            results.push_back(std::stoi(str));
    }

    std::vector<uint32_t>::iterator ans = std::max_element(results.begin(), results.end());

    printf("\nProblem 038: %u\n", *ans);
    return true;
}
