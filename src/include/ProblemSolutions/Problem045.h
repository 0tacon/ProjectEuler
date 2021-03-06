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
    Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
    Triangle 	  	Tn=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
    Pentagonal 	  	Pn=n(3n−1)/2 	  	1, 5, 12, 22, 35, ...
    Hexagonal 	  	Hn=n(2n−1) 	  	1, 6, 15, 28, 45, ...

    It can be verified that T285 = P165 = H143 = 40755.

    Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <cstdint>
#include <cstdio>
#include <cmath>

bool Problem45()
{
    double n, Tn, pos = 286.0f;
    bool ans_found = false;

    while (!ans_found)
    {
        Tn = (pos*(pos + 1.0f))/2.0f;

        n = (1.0f + sqrt(1.0f + 24.0f*Tn))/6.0f;

        if (fmod(n, 1.0f) == 0.0f)
        {
            n = (1.0f + sqrt(1.0f + 8.0f*Tn))/4.0f;

            if (fmod(n, 1.0f) == 0.0f)
                ans_found = true;
        }

        pos++;
    }

    std::printf("\nProblem 045: %f\n", Tn);
    return true;
}
