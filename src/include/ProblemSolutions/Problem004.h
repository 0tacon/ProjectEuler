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
	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <cstdint>

#ifndef _ISPALENDROME_
	#include "../OtherFunctions/IsPalendrome.h"
#endif

bool Problem4()
{
	uint32_t prod, largest_pdrome=0;

	for ( uint32_t num1=100 ; num1<1000 ; num1++ )
	{
		for ( uint32_t num2=100 ; num2<1000 ; num2++ )
		{
			prod = num1*num2;
			if ( IsPalendrome( prod ) && prod>largest_pdrome ) largest_pdrome = prod;
		}
	}

	std::cout << "\nProblem 004: " << largest_pdrome << "\n";

	return true;
}
