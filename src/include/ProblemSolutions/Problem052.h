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
	It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

	Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>

bool Problem52()
{
	uint32_t num;

	for (uint32_t i = 125875; i < 1000000; ++i)
	{
		uint8_t  num_digit_comparison_count = 1;
		num = i;
		uint32_t other_num = 2*num;
		std::string str_num = std::to_string(num), str_other_num = std::to_string(other_num);

		while (std::is_permutation(str_num.begin(), str_num.end(), str_other_num.begin()))
		{
			num_digit_comparison_count++;

			other_num += num;
			str_other_num = std::to_string(other_num);
		}

		if (num_digit_comparison_count == 6)
			break;
	}

	std::printf("\nProblem 052: %d\n", num);
	return true;
}