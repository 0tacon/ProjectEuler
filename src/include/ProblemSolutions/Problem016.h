/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstdio>

#ifndef _STRINGNUM_
#include "..\\Classes\\StringNum.h"
#endif

bool Problem16 ()
{
	StringNum result("2.000000"), unity("1.000000"), base("2.000000"), exp("1000.000000");

	for (StringNum i("1.000000"); i.GetNum() != exp.GetNum(); i = i + unity)
		result = result * base;

	std::cout << "\nProblem 016: " << result.SumDigits() << "\n";
	return true;
}