/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

/*
	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>
#include <cstdint>
#include <vector>

bool Problem2()
{
	uint32_t sum=0, pre_i=0, i=1, temp=0;
	std::vector<uint32_t> Fibonacci;

	for ( uint32_t j = 1 ; j < 32 ; j++ )
	{
		temp = pre_i;
		pre_i = i;
		i += temp;
		temp = pre_i+i;
		if ( temp<4000001 && temp%2==0 ) Fibonacci.push_back ( temp );
	}

	for ( std::vector<uint32_t>::iterator itr = Fibonacci.begin() ; itr != Fibonacci.end() ; itr++ )
	{
		sum+=*itr;
	}

	std::cout << "\nProblem 002: " << sum << "\n";

	return true;
}
