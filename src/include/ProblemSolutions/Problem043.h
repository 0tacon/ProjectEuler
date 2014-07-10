/*
    The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

    Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

        d2d3d4=406 is divisible by 2
        d3d4d5=063 is divisible by 3
        d4d5d6=635 is divisible by 5
        d5d6d7=357 is divisible by 7
        d6d7d8=572 is divisible by 11
        d7d8d9=728 is divisible by 13
        d8d9d10=289 is divisible by 17

    Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

#ifndef _GETNUMDIGITS_
#include "../OtherFunctions/GetNumDigits.h"
#endif // _GETNUMDIGITS_

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif // _PRINTVECTOR_

bool Problem43()
{
    std::vector<uint16_t> primes = {2,3,5,7,11,13,17};
    std::map<uint8_t, std::vector<std::string> > numbers;
    uint16_t num;
    std::string temp_num;
    bool repeated_digits = false;

    for (std::vector<uint16_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
        for (uint16_t i = (10/ *prime); i < (1000/ *prime) + 1; i++)
        {
            temp_num = std::to_string(*prime*i);

            if (temp_num.size() == 2 || temp_num.size() == 3)
            {
                if (temp_num.size() == 2)
                    temp_num = "0" + temp_num;

                for (std::string::iterator letter = temp_num.begin(); letter != temp_num.end(); letter++)
                    if (std::count(temp_num.begin(), temp_num.end(), *letter) > 1)
                        repeated_digits = true;

                if (!repeated_digits)
                    numbers[*prime].push_back(temp_num);

                repeated_digits = false;
            }
        }

    for (std::map<uint8_t, std::vector<std::string> >::iterator i = numbers.begin(); i != numbers.end(); i++)
    {
        std::printf("\nPrime = %d\n", i->first);
        for (std::vector<std::string>::iterator j = i->second.begin(); j != i->second.end(); j++)
            std::printf("%s, ", j->c_str());
        std::printf("\n");
    }

    std::printf("\nProblem 043: \n");
    return true;
}
