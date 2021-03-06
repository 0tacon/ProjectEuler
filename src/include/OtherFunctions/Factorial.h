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

#include <cstdint>

#define _FACTORIAL_

template<typename T>
double Factorial (T n)
{
	double fact = 1;
	T temp = n;

	while (temp > 1)
	{
		fact *= temp;
		temp--;
	}

	return fact;
}

template<typename T>
uint64_t Factorial (T n, T k)
{
	uint64_t fact = 1;
	T temp = n;

	while (temp > n - k)
	{
		fact *= temp;
		temp--;
	}

	return fact;
}
