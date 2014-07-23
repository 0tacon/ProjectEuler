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
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cstdint>

#ifndef _GETSUMPRIMESBELOW_
	#include "../OtherFunctions/GetSumPrimesBelow.h"
#endif

bool Problem10 ()
{
	std::cout << "\nProblem 010: " << GetSumPrimesBelow(2000000) << "\n";

	return true;
}
