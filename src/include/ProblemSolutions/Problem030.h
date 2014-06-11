/*
    Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

        1634 = 1^4 + 6^4 + 3^4 + 4^4
        8208 = 8^4 + 2^4 + 0^4 + 8^4
        9474 = 9^4 + 4^4 + 7^4 + 4^4

    As 1 = 1^4 is not a sum it is not included.

    The sum of these numbers is 1634 + 8208 + 9474 = 19316.

    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>

#ifndef _FACTORIAL_
#include "../OtherFunctions/Factorial.h"
#endif

#ifndef _GETALLPOSSIBLESUMS_
#include "../OtherFunctions/GetAllPossibleSums.h"
#endif

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif

bool Problem30()
{
    std::map<uint8_t, uint16_t> v;
    std::vector<uint16_t> vect = {1,2,3,4}, sums;

    /*for (uint8_t i = 1; i != 10; i++)
        v[i] = pow(i,5);

    for (std::map<uint8_t, uint16_t>::iterator i = v.begin(); i != v.end(); i++)
        printf("%d => %d\n", i->first, i->second);

    printf("9! = %lf\n", Factorial(9));*/

    sums = GetAllPossibleSums(vect);

    PrintVector(vect);
    printf("\n");
    PrintVector(sums);

    printf("\nProblem 030: \n");
    return true;
}
