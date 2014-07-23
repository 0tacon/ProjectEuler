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
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <functional>

#define _GETALLPRIMESBELOW_

template<typename T>
std::vector<uint32_t> GetAllPrimesBelow (T max)
{
	std::vector<uint32_t> ret;
	std::map<uint32_t, bool> primes;

	if (max < 2)
	{
		ret.push_back(0);
		return ret;
	}
	else if ( max == 2 )
	{
		ret.push_back(2);
		return ret;
	}
	else
	{
		for (uint32_t i = 3; i < max; i += 2)
			primes[i] = true;

		for (uint32_t i = 3; i < sqrt(max); i += 2)
			if (primes[i] == true)
				for (uint32_t n = i*i; n < max; n+=i)
					primes[n] = false;

		for (std::map<uint32_t, bool>::iterator p = primes.begin(); p != primes.end(); p++)
			if (p->second == true)
				ret.push_back(p->first);

		ret.insert(ret.begin(), 2);
		return ret;
	}
}
