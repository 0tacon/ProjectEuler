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
#include <string>
#include <iterator>

#define _DONUMSSHAREDIGITS_

template<typename T1, typename T2>
bool DoNumsShareDigits (T1 a, T2 b)
{
    std::string str_a = std::to_string(static_cast<uint64_t>(a)), str_b = std::to_string(static_cast<uint64_t>(b));

    for (std::string::iterator itr_a = str_a.begin(); itr_a != str_a.end(); itr_a++)
        for (std::string::iterator itr_b = str_b.begin(); itr_b != str_b.end(); itr_b++)
            if (*itr_a == *itr_b)
                return true;

    return false;
}
