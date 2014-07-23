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
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#ifndef _STRINGNUM_
#include "StringNum.h"
#endif

#define _LARGEFACTORIAL_

class LargeFactorial
{
public:
	LargeFactorial();
	LargeFactorial(StringNum);
	~LargeFactorial();

	void SetResult(StringNum n) { result = n; }
	StringNum GetResult() { return result; }

private:
	StringNum result;
};

LargeFactorial::LargeFactorial() { result.SetNum("1.000000"); }

LargeFactorial::LargeFactorial(StringNum n)
{
	StringNum unity("1.000000"), temp("1.000000");
	result.SetNum("1.000000");

	for (StringNum i = n; i.GetNum() != ".000000"; i = i - unity)
	{
		//result.Print();
		//i.Print();
		temp = result * i;
		//temp.Print();
		result.SetNum(temp.GetNum());
		//result.Print();
	}
}

LargeFactorial::~LargeFactorial() {}
