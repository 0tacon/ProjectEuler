/*
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

    What is the largest n-digit pandigital prime that exists?
*/

#include <cstdio>
#include <cstdint>
#include <vector>

#ifndef _ISPANDIGITAL_
#include "../OtherFunctions/IsPanDigital.h"
#endif // _ISPANDIGITAL_

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem41()
{
    std::vector<uint32_t> primes = GetAllPrimesBelow(10000000);
    uint32_t ans;

    for (std::reverse_iterator<std::vector<uint32_t>::iterator> prime = primes.rbegin(); prime != primes.rend(); prime++)
        if (IsPanDigital(*prime))
        {
            ans = *prime;
            prime = std::prev(primes.rend(), 1);
        }

    printf("\nProblem 041: %u\n", ans);
    return true;
}
