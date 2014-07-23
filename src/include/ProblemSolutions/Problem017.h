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
	If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
	contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>
#include <cstdint>

#ifndef _GETLETTERSINNUM_
	#include "../OtherFunctions/GetLettersInNum.h"
#endif

bool Problem17 ()
{
	uint16_t letters = 11;	// one thousand = 11

	for (uint16_t i=1; i<1000; i++) letters+=GetLettersInNum(i);

	std::cout << "\nProblem 017: " << letters << "\n";
	return true;
}
