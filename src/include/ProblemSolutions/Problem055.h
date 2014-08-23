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
	If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

	Not all numbers produce palindromes so quickly. For example,

	349 + 943 = 1292,
	1292 + 2921 = 4213
	4213 + 3124 = 7337

	That is, 349 took three iterations to arrive at a palindrome.

	Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. 
	A number that never forms a palindrome through the reverse and add process is called a Lychrel number. 
	Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number 
	is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either 
	(i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, 
	has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations 
	before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

	Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

	How many Lychrel numbers are there below ten-thousand?

	NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/

#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stdexcept>

#include "../Classes/StringNum.h"

bool Problem55()
{
	uint16_t num_lychrels = 0;
	StringNum min("11.000000"), max("10000.000000"), unity("1.000000");

	for (StringNum n = min; !(n == max); n = n + unity)
	{
		std::string str_n = n.GetNum();

		StringNum num(n.GetNum()), rev_num;
		bool palendrome_found = false;

		for (uint8_t i = 0; i < 50; i++)
		{
			std::string num_str = num.GetNum(), rev_str;
			rev_str.resize(num.Get1stDigitIndex() + 1);

			std::reverse_copy(num_str.begin(), std::next(num_str.begin(), num.Get1stDigitIndex() + 1), rev_str.begin());
			rev_str += ".000000";

			rev_num.SetNum(rev_str);

			StringNum sum = num + rev_num;
			std::string sum_str = sum.GetNum();
			sum_str.erase(std::next(sum_str.begin(), sum.Get1stDigitIndex() + 1), sum_str.end());

			palendrome_found = std::equal(sum_str.begin(), sum_str.begin() + sum_str.size() / 2, sum_str.rbegin());

			if (palendrome_found)
				break;

			num = sum;
		}

		if (!palendrome_found)
			num_lychrels++;
	}
	
	std::printf("\nProblem 055: %d\n", num_lychrels);
	return true;
}