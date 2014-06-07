/*
    Euler discovered the remarkable quadratic formula:

    n² + n + 41

    It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

    The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

    Considering quadratics of the form:

        n² + an + b, where |a| < 1000 and |b| < 1000

        where |n| is the modulus/absolute value of n
        e.g. |11| = 11 and |−4| = 4

    Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include <cstdint>
#include <cstdio>
#include <vector>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif

bool Problem27()
{
    std::vector<uint32_t> primes = GetAllPrimesBelow(10000), seq;
    int32_t n = 0, Tn = 0, a = -1000, b = -1000, x = 0, y = 0;
    uint32_t longest_seq = 0;

    for (; a < 1001; a++)
    {
        for (; b < 1001; b++)
        {
            n = 0;
            Tn = 0;

            while (Tn == 0 || std::count(primes.begin(), primes.end(), Tn) == 1)
            {
                Tn = n*n + a*n + b;

                if (std::count(primes.begin(), primes.end(), Tn) == 1)
                    seq.push_back(Tn);

                n++;
            }

            if (seq.size() > longest_seq)
            {
                longest_seq = seq.size();
                x = a;
                y = b;
            }

            seq.clear();
        }

        b = -1000;
    }

    printf("\nProblem 027: %d\n", x*y);
    return true;
}
