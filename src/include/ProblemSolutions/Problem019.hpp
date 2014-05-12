/*
	You are given the following information, but you may prefer to do some research for yourself.
	
	1 Jan 1900 was a Monday.
	Thirty days has September,
	April, June and November.
	All the rest have thirty-one,
	Saving February alone,
	Which has twenty-eight, rain or shine.
	And on leap years, twenty-nine.
	A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
	How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>
#include <cstdint>

#ifndef _DATE_
	#include "..\\Classes\\Date.hpp"
	#define _DATE_
#endif

bool Problem19 ()
{
	Date d1, d2;
	
	d1.PrintDate();
	d2.PrintDate();
	
	for (uint8_t i=0; i<5; i++) d2.IncrementBy1Week();
	d1.PrintDate();
	d2.PrintDate();
	
	if (d2>d1) std::cout << "\nConfirmed, d2 greater than d1\n";
	if (d1>d2) std::cout << "\nError d1 incorrectly identified as greater than d2\n";
	
	std::cout << "\nProblem 019: " << "\n";
	return true;
}
