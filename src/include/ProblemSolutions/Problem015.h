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
	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
	there are exactly 6 routes to the bottom right corner.

	How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include <cstdint>
#include <cmath>

#ifndef _COMBINATION_
	#include "../OtherFunctions/Combination.h"
#endif

bool Problem15 ()
{
	std::cout << "\nProblem 015: " << Combination(40, 20) << "\n";
	return true;
}
