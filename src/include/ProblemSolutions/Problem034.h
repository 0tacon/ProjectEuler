/*
    145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

    Find the sum of all numbers which are equal to the sum of the factorial of their digits.

    Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <cstdint>
#include <cstdio>
#include <map>
#include <vector>
#include <string>

#ifndef _FACTORIAL_
#include "../OtherFunctions/Factorial.h"
#endif // _FACTORIAL_

bool Problem34()
{
    std::map<uint8_t, uint32_t> digit_factorials;
    std::vector<uint64_t> results;
    std::string number;
    uint64_t sum = 0;

    for (uint32_t i = 0; i < 10; i++)
        digit_factorials[i] = Factorial(i);

    for (uint64_t i = 10; i < 1000000; i++)
    {
        number = std::to_string(i);
        sum = 0;

        for (std::string::iterator itr = number.begin(); itr != number.end(); itr++)
            sum += digit_factorials[*itr - '0'];

        if (sum == i)
            results.push_back(i);
    }

    sum = 0;

    for (std::vector<uint64_t>::iterator itr = results.begin(); itr != results.end(); itr++)
        sum += *itr;

    printf("\nProblem 034: %lu\n", sum);
    return true;
}
