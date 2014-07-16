/*
    It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

    9 = 7 + 2×1^2
    15 = 7 + 2×2^2
    21 = 3 + 2×3^2
    25 = 7 + 2×3^2
    27 = 19 + 2×2^2
    33 = 31 + 2×1^2

    It turns out that the conjecture was false.

    What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif // _PRINTVECTOR_

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem46()
{
    uint32_t max = 100;
    std::vector<uint32_t> sqrs, primes = GetAllPrimesBelow(max*max), odd_composites, results;

    for (uint32_t i = 1; i <= max; i++)
        sqrs.push_back(i*i);

    for (uint32_t i = 9; i <= max*max; i+=2)
        if (std::count(primes.begin(), primes.end(), i) == 0)
            odd_composites.push_back(i);

    results = odd_composites;

    for (std::vector<uint32_t>::iterator odd_composite = odd_composites.begin(); odd_composite != odd_composites.end(); odd_composite++)
        for (std::vector<uint32_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
            if (*prime < *odd_composite)
            {
                uint32_t remainder = *odd_composite - *prime;

                if (remainder%2 == 0)
                {
                    remainder /= 2;

                    if (std::count(sqrs.begin(), sqrs.end(), remainder) == 1 && std::count(results.begin(), results.end(), *odd_composite) == 1)
                    {
                        results.erase(std::remove(results.begin(), results.end(), *odd_composite), results.end());

                        prime = std::prev(primes.end(), 1);
                    }
                }
            }

    std::printf("\nProblem 046: %u\n", results[0]);
    return true;
}
