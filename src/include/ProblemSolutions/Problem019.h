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
	#include "..\\Classes\\Date.h"
#endif

bool Problem19 ()
{
	Date sunday, max_date;
	uint32_t sunday_the_1st_count=0;

	sunday.SetMembers(6,1,1901);		// The first Sunday of the 20th century
	max_date.SetMembers(1,1,2001);		// Must only analyse dates before this one
	
	while (max_date>sunday)
	{
		sunday.IncrementByNumDays(7);
		if (sunday.GetDay() == 1) sunday_the_1st_count++;
	}
	
	std::cout << "\nProblem 019: " << sunday_the_1st_count << "\n";
	return true;
}
