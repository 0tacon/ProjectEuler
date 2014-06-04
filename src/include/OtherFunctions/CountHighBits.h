#include <cstdint>
#include <cmath>

#define _COUNTHIGHBITS_

template<typename T>
T CountHighBits(T n, uint8_t bit_length)
{
	uint8_t num_high_bits=0;
	T limit = 1+pow(2,bit_length-1);
	
	T i = 1;
	while(i<limit)
	{
		if ( (n&i) == i )	num_high_bits++;
		i = pow(2,log2(i)+1);
	}
	
	return num_high_bits;
}
