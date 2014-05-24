/*
	n! means n × (n - 1) × ... × 3 × 2 × 1

	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
	
	Find the sum of the digits in the number 100!
*/

#include <iostream>
#include <cstdint>

#ifndef _LARGEFACTORIAL_
	#include "..\\Classes\\LargeFactorial.h"
#endif

bool Problem20()
{
	LargeBase2 n1(4), n2(5), n3;
	
	//n1.Print();
	//n2.Print();
	
	std::cout << "\nProblem 020: " << "\n";
	return true;
}
