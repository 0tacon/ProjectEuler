#include <cstdint>
#include <cstdio>
#include <string>
#include <iterator>

#define _SUMDIGITS_

template<typename T>
uint64_t SumDigits (T n)
{
    uint64_t sum = 0;
    std::string num = std::to_string(static_cast<uint64_t>(n));

    for (std::string::iterator itr = num.begin(); itr != num.end(); itr++)
        sum += *itr - '0';

    return sum;
}
