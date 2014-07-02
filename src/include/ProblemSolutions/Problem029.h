/*
    Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

        2^2=4, 2^3=8, 2^4=16, 2^5=32
        3^2=9, 3^3=27, 3^4=81, 3^5=243
        4^2=16, 4^3=64, 4^4=256, 4^5=1024
        5^2=25, 5^3=125, 5^4=625, 5^5=3125

    If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

    4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

    How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>

#ifndef _STRINGNUM_
#include "../Classes/StringNum.h"
#endif // _STRINGNUM_

bool Problem29()
{
    StringNum unity("1.000000"), max("101.000000"), result;
    std::vector<std::string> results;

    for (StringNum base("2.000000"); base.GetNum() != max.GetNum(); base = base + unity)
    {
        //base.Print();

        for (StringNum exp("2.000000"); exp.GetNum() != max.GetNum(); exp = exp + unity)
        {
            //exp.Print();

            result = base;

            for (StringNum i("1.000000"); i.GetNum() != exp.GetNum(); i = i + unity)
                result = result * base;

            if (std::count(results.begin(), results.end(), result.GetNum()) == 0)
                results.push_back(result.GetNum());

            //result.Print();
        }
    }

    //for (std::vector<std::string>::iterator itr = results.begin(); itr != results.end(); itr++)
        //printf("\n%s", itr->c_str());

    printf("\nProblem 029: %lu\n", results.size());
    return true;
}
