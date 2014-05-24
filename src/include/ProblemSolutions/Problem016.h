/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdint>

#ifndef _LARGEBASE2_
	#include "..\\Classes\\LargeBase2.h"
#endif

bool Problem16 ()
{
	LargeBase2 n(1000);
	
	std::cout << "\nProblem 016: " << n.SumDigits() << "\n";
	return true;
}
