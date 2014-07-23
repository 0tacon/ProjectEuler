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

*/

#include <cstdio>
#include <cstdint>

#ifndef _STRINGNUM_
#include ".//Classes//StringNum.h"
#endif

bool Problem25()
{
	StringNum n("2.000000"), n1("1.000000"), n2("1.000000");
	uint64_t pos = 2;

	while (n.GetNum().size() < 1007)
	{
		n = n1 + n2;
		n2 = n1;
		n1 = n;
		pos++;
	}

	printf("\nProblem 025: %lu\n", pos);
	return true;
}
