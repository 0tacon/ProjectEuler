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

#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

#define _ISPANDIGITAL_

template<typename T>
bool IsPanDigital (T n)
{
    std::string str = std::to_string(static_cast<uint64_t>(n)), ref_str = "";

    if (str.size() < 10)
    {
        for (uint8_t i = 0; i < str.size(); i++)
            ref_str += std::to_string(i+1);

        if (std::is_permutation(str.begin(), str.end(), ref_str.begin()))
            return true;
    }
    else
        printf("\nError: Number has to many digits to be pandigital.\n");

    return false;
}
