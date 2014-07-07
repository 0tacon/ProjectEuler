/*
    An irrational decimal fraction is created by concatenating the positive integers:

    0.123456789101112131415161718192021...

    It can be seen that the 12th digit of the fractional part is 1.

    If dn represents the nth digit of the fractional part, find the value of the following expression.

    d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <cstdio>
#include <cstdint>
#include <string>
#include <iterator>

bool Problem40()
{
    std::string str = "";
    uint32_t ans = 1;

    for (uint32_t i = 1; str.size() < 1000000; i++)
        str += std::to_string(i);

    for (uint32_t i = 1; i < 1000001; i*=10)
        ans *= str[i-1] - '0';

    printf("\nProblem 040: %u\n", ans);
    return true;
}
