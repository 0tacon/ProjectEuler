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
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdint>

#ifndef _STRINGNUM_
#include "../Classes/StringNum.h"
#endif

bool Problem16 ()
{
	StringNum result("2.000000"), unity("1.000000"), base("2.000000"), exp("1000.000000");

	for (StringNum i("1.000000"); i.GetNum() != exp.GetNum(); i = i + unity)
		result = result * base;

	std::cout << "\nProblem 016: " << result.SumDigits() << "\n";
	return true;
}
