/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdint>
#include <cmath>

#ifndef _GETDIGIT_
	#include "..\\OtherFunctions\\GetDigit.hpp"
	#define _GETDIGIT_
#endif

#ifndef _GETNUMDIGITS_
	#include "..\\OtherFunctions\\GetNumDigits.hpp"
	#define _GETNUMDIGITS_
#endif

bool Problem16 ()
{
	double num = pow(2,1000);
	
	//std::cout << GetNumDigits(num);
	
	std::cout << "\nProblem 016: " << "\n";
	return true;
}
