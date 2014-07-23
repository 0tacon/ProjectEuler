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
#include <algorithm>

#define _TRUNCATENUM_

template<typename T>
uint64_t TruncateNum (T n, T r, char from_dir)
{
    uint64_t result = 0, rem = static_cast<uint64_t>(r);
    std::string str;

    str = std::to_string(static_cast<uint64_t>(n));

    if (r >= str.size())
    {
        printf("\nError: Attempting to truncate too many digits.\n");
        return result;
    }

    if (from_dir == 'L')
        str.erase(str.begin(), std::next(str.begin(), rem));
    else if (from_dir == 'R')
        str.erase(std::prev(str.end(), rem), str.end());
    else
    {
        printf("\nError: Invalid truncation direction.\n");
        return result;
    }

    result = std::stoi(str);

    return result;
}
