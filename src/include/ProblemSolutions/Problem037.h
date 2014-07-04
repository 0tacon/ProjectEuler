/*
    The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

    Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

    NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

#ifndef _TRUNCATENUM_
#include "../OtherFunctions/TruncateNum.h"
#endif // _TRUNCATENUM_

#ifndef _GETNUMDIGITS_
#include "../OtherFunctions/GetNumDigits.h"
#endif // _GETNUMDIGITS_

bool Problem37()
{
    std::vector<uint32_t> primes = GetAllPrimesBelow(739398);
    uint32_t n = 0, sum = 0;
    uint8_t truncated_primes_found = 0, num_digits = 0;

    for (std::vector<uint32_t>::iterator prime = std::next(primes.begin(), 4); prime != primes.end(); prime++)
    {
        truncated_primes_found = 0;
        num_digits = GetNumDigits(*prime);

        for (uint32_t rem = 1; rem < num_digits; rem++)
        {
            n = TruncateNum(*prime, rem, 'L');

            if (std::count(primes.begin(), primes.end(), n) > 0)
                truncated_primes_found++;

            n = TruncateNum(*prime, rem, 'R');

            if (std::count(primes.begin(), primes.end(), n) > 0)
                truncated_primes_found++;
        }

        if (truncated_primes_found == 2*(num_digits - 1))
            sum += *prime;
    }

    printf("\nProblem 037: %u\n", sum);
    return true;
}
