#include <iostream>
#include <cstdint>
#include <vector>

#ifndef _GETNUMDIGITS_
	#include "..\\OtherFunctions\\GetNumDigits.hpp"
	#define _GETNUMDIGITS_
#endif

bool IsPalendrome ( uint64_t num )
{
	uint8_t digits;
	uint64_t temp = num;
	std::vector<uint8_t> vect;
	
	digits = GetNumDigits(num);
	
	for ( uint8_t i = 0 ; i < digits ; i++ )
	{
		vect.push_back(temp%10);
		temp = (temp-temp%10)/10;
	}
	
	if ( std::equal( vect.begin(), vect.begin() + vect.size()/2, vect.rbegin() ) ) return true;
	
	return false;
}
