/*
	The sum of the squares of the first ten natural numbers is,
	1^2 + 2^2 + ... + 10^2 = 385
	
	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)^2 = 55^2 = 3025
	
	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <cstdint>

bool Problem6 ()
{
	uint32_t sum1=0, sum2=0;
	
	for ( uint32_t i = 1 ; i<101 ; i++ )
	{
		sum1 += i*i;
		
		sum2 += i;
	}
	sum2 = sum2*sum2;
	
	std::cout << "\nProblem 006: " << sum2-sum1 << "\n";
	
	return true;
}
