/*
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a^2 + b^2 = c^2
	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
	
	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include <iostream>
#include <cstdint>
#include <cmath>

bool Problem9 ()
{
	uint16_t b=1, a=1;
	bool triplet_found = false;
	
	while ( a<500 && !triplet_found )
	{
		b = 1;
		while ( b<500 && !triplet_found )
		{
			if ( a + b + sqrt(a*a + b*b) == 1000 ) triplet_found = true;
			else b++;
		}
		if ( !triplet_found ) a++;
	}
	
	std::cout 	<< "\nProblem 009: a = " << static_cast<unsigned int>(a) << ", b = " << static_cast<unsigned int>(b) 
				<< ", c = " << static_cast<unsigned int>(sqrt(a*a + b*b)) << "\n";
	
	return true;
}
