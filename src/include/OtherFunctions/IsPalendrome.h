#include <iostream>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <cstring>

#ifndef _GETNUMDIGITS_
	#include "../OtherFunctions/GetNumDigits.h"
#endif

#define _ISPALENDROME_

bool IsPalendrome ( uint64_t num )
{
	std::string vect = std::to_string(num);

	if ( std::equal( vect.begin(), vect.begin() + vect.size()/2, vect.rbegin() ) ) return true;

	return false;
}
