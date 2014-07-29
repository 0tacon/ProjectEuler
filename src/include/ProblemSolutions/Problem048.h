/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

/*
    The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

    Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <cstdint>
#include <cstdio>
#include <cmath>

#ifndef _STRINGNUM_
#include "../Classes/StringNum.h"
#endif // _STRINGNUM_

bool Problem48()
{
    StringNum unity("1.000000"), max("1001.000000"), total("0.000000"), exp_result, multi_result;

    for (StringNum base("1.000000"); base.GetNum() != max.GetNum(); base = base + unity)
    {
        exp_result = base;

        // Calculate exp_result = base^base
        for (StringNum i("1.000000"); i.GetNum() != base.GetNum(); i = i + unity)
        {
            multi_result.SetNum("0.000000");

            // Calculate multi_result = base*base
            for (StringNum k = base; k.GetNum() != ".000000"; k = k - unity)
            {
                multi_result = multi_result + exp_result;
                multi_result.TruncateStringNum(10);
            }

            exp_result = multi_result;
            exp_result.TruncateStringNum(10);
        }

        total = total + exp_result;
        total.TruncateStringNum(10);
    }

    std::string answer = total.GetNum();
    answer.erase(std::prev(answer.end(), 7), answer.end());

    std::printf("\nProblem 048: %s\n", answer.c_str());
    return true;
}
