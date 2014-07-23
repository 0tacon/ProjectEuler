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
#include <cmath>

#define _ISDIVISIBLE_

bool IsDivisible (uint64_t a, uint64_t b)
{
	if (a <= b) return false;
	else if (fmod(static_cast<double>(a), static_cast<double>(b)) == 0.0 ) return true;
	else return false;
}

bool IsNotDivisible (uint64_t a, uint64_t b)
{
	bool n = !(IsDivisible (a,b));
	return n;
}
