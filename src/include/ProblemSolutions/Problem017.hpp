/*
	If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
	contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>
#include <cstdint>

#ifndef _GETLETTERSINNUM_
	#include "..\\OtherFunctions\\GetLettersInNum.hpp"
	#define _GETLETTERSINNUM_
#endif

bool Problem17 ()
{
	uint16_t letters = 11;	// one thousand = 11
	
	for (uint16_t i=1; i<1000; i++) letters+=GetLettersInNum(i);
	
	std::cout << "\nProblem 017: " << letters << "\n";
	return true;
}
