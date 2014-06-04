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