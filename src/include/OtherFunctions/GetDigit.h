#include <cstdint>

#define _GETDIGIT_

template<typename T>
uint8_t GetDigit(T n, uint8_t pos)
{
	uint8_t digit;
	
	for (uint8_t i=1; i<pos; i++) n = n/10;
	
	digit = n%10;
	
	return digit;
}
