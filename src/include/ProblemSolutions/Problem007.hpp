/*
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

	What is the 10 001st prime number?
*/

#include <iostream>
#include <cstdint>

#ifndef _GETPRIMENUMBER_
	#include "..\\OtherFunctions\\GetPrimeNumber.hpp"
	#define _GETPRIMENUMBER_
#endif

bool Problem7 ()
{
	std::cout << "\nProblem 007: " << GetPrimeNumber(10001) << "\n";
	
	return true;
}
