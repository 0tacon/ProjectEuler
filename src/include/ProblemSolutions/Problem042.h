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
    The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

    By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

    Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

#include <cstdio>
#include <cstdint>
#include <vector>
#include <cmath>

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif // _READFILEINTOVECT_

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif // _PRINTVECTOR_

bool Problem42()
{
    std::string filename = "../../data/words.txt";
    std::vector<uint8_t> input, word_sums;
    uint8_t word_sum = 0;
    bool capture = false;
    float tn, n;

    ReadFileIntoVect(input, filename);

    for (std::vector<uint8_t>::iterator letter = input.begin(); letter != input.end(); letter++)
    {
        if (capture && *letter != '"')
            word_sum += *letter - 'A' + 1;
        else if (word_sum > 0)
        {
            tn = static_cast<float>(word_sum);
            n = (sqrt(1.0f + 8.0f*tn) - 1.0f)/2.0f;

            if (fmod(n, 1.0f) == 0.0f)
                word_sums.push_back(word_sum);

            word_sum = 0;
        }

        if (*letter == '"')
            capture = !capture;
    }

    printf("\nProblem 042: %lu\n", word_sums.size());
    return true;
}
