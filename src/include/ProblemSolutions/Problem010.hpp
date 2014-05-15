/*
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cstdint>

#ifndef _GETSUMPRIMESBELOW_
	#include "..\\OtherFunctions\\GetSumPrimesBelow.hpp"
	#define _GETSUMPRIMESBELOW_
#endif

bool Problem10 ()
{
	std::cout << "\nProblem 010: " << GetSumPrimesBelow(2000000) << "\n";
	
	return true;
}
