/*
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

    The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

    Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
    HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

bool Problem32()
{
    std::vector<std::pair<std::vector<uint32_t>, std::string> > results;
    std::vector<uint32_t> vect, ans;
    std::string ref_str = "123456789";
    std::string str;
    uint64_t sum = 0;

    for (uint32_t a = 1; a < 10000; a++)
        for (uint32_t b = 1; b < 100; b++)
        {
            str = std::to_string(a) + std::to_string(b) + std::to_string(a*b);

            if (str.size() == 9)
            {
                vect.clear();
                vect.push_back(a);
                vect.push_back(b);
                vect.push_back(a*b);
                results.push_back(std::make_pair(vect, str));
            }
        }

    for (std::vector<std::pair<std::vector<uint32_t>, std::string> >::iterator itr = results.begin(); itr != results.end(); itr++)
    {
        std::vector<uint32_t>::iterator product = std::prev(itr->first.end(), 1);

        if (std::is_permutation(ref_str.begin(), ref_str.end(), itr->second.begin()) && std::count(ans.begin(), ans.end(), *product) == 0)
            ans.push_back(*product);
    }

    for (std::vector<uint32_t>::iterator i = ans.begin(); i != ans.end(); i++)
        sum += *i;

    printf("\nProblem 032: %lu\n", sum);
    return true;
}
