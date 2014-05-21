/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <array>

bool Problem16 ()
{
	double num = pow(2,1000);
	char digits[310];
	uint16_t sum_digits = 0;
	
	std::sprintf(digits, "%f", num);
	
	uint16_t i = 0;
	while (digits[i] != '.')
	{
		sum_digits += digits[i] - 48;
		i++;
	}
	
	std::cout << "\nProblem 016: " << sum_digits << "\n";
	return true;
}
