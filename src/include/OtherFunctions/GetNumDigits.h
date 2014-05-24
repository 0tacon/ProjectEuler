#include <cstdint>
#include <cmath>

#define _GETNUMDIGITS_

template<typename T>
uint8_t GetNumDigits (T num)
{
	uint8_t digits=0;
	int8_t i=19;
	bool found_num_digits = false;
	
	while ( i > -1 && !found_num_digits )
	{
		if ( num > pow(10, i-1)-1 && num < pow(10, i) )
		{
			digits = i;
			found_num_digits = true;
		}
		i--;
	}
	
	return digits;
}
