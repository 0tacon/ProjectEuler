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

	printf("\nProblem 025: %d\n", pos);
	return true;
}