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
#include <algorithm>

#define _AREDIGITSREPEATED_

template<typename T>
bool AreDigitsRepeated (T n)
{
    std::string str = std::to_string(static_cast<uint64_t>(n));

    for (std::string::iterator i = str.begin(); i != str.end(); i++)
        if (std::count(str.begin(), str.end(), *i) > 1)
            return true;

    return false;
}
