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

#include <cstdint>
#include <cstdio>
#include <string>
#include <iterator>

#define _SUMDIGITS_

template<typename T>
uint64_t SumDigits (T n)
{
    uint64_t sum = 0;
    std::string num = std::to_string(static_cast<uint64_t>(n));

    for (std::string::iterator itr = num.begin(); itr != num.end(); itr++)
        sum += *itr - '0';

    return sum;
}
