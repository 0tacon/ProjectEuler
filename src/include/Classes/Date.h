#include <iostream>
#include <cstdint>
#include <map>

#define _DATE_

class Date
{
public:
	Date();
	~Date();
		
	void SetMembers (uint8_t d, uint8_t m, uint16_t y);
		
	void IncrementByNumDays(uint16_t days);
		
	bool IsLeapYear();
		
	uint8_t GetDaysInMonth ();
		
	bool operator>(const Date& other) const;
	bool operator<(const Date& other) const { return other > *this; }
		
	void PrintDate();
		
	void PrintWeekDay ();
		
	uint8_t GetYear() const { return year; }
	uint8_t GetMonth() const { return month; }
	uint8_t GetDay() const { return day; }
		
private:
	uint8_t day, month, week_day;
		
	uint16_t year;
};

Date::Date ()
{
	day = 1;
	month = 1;
	year = 1900;
	week_day = 1;
}

Date::~Date () {}

void Date::SetMembers (uint8_t d, uint8_t m, uint16_t y)
{
	Date reference;
	uint32_t difference = 0;
	
	day = d;
	month = m;
	year = y;
	
	while (reference < *this)
	{
		reference.IncrementByNumDays(1);
		difference++;
	}
	
	week_day += difference%7;
	if (week_day%7 != 0) week_day = week_day%7;
	else week_day = 7;
}

void Date::IncrementByNumDays (uint16_t days)
{
	uint16_t month_multiples;
	
	week_day += days%7;
	if (week_day%7!=0) week_day = week_day%7;
	else week_day = 7;
	
	if (days>28)
	{
		month_multiples = (days-days%28)/28;
		days = days%28;
		
		for (uint8_t i=0; i<month_multiples; i++)
		{
			day += 28;
			if(day > GetDaysInMonth())
			{
				day -= GetDaysInMonth();
				
				month++;
				if (month > 12)
				{
					month = 1;
					year++;
				}
			}
		}
	}
	
	day += days;
	if(day > GetDaysInMonth())
	{
		day -= GetDaysInMonth();
		
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

bool Date::IsLeapYear()
{
	if (year%100 == 0 && (year/100)%4 == 0) return true;
	else if (year%100 != 0 && year%4 == 0) return true;
	else return false;
}

uint8_t Date::GetDaysInMonth ()
{
	std::map<uint8_t, uint8_t> days_in_month;
	
	days_in_month[1] = 31;
	days_in_month[2] = 28;
	days_in_month[3] = 31;
	days_in_month[4] = 30;
	days_in_month[5] = 31;
	days_in_month[6] = 30;
	days_in_month[7] = 31;
	days_in_month[8] = 31;
	days_in_month[9] = 30;
	days_in_month[10] = 31;
	days_in_month[11] = 30;
	days_in_month[12] = 31;
	
	if (month==2 && IsLeapYear())	return days_in_month[2]+1;
	else return days_in_month[month];
}

bool Date::operator>(const Date& other) const
{
    if ( this->GetYear() > other.GetYear() ) return true;
    else if ( this->GetYear()==other.GetYear() && this->GetMonth()>other.GetMonth() ) return true;
    else if ( this->GetYear()==other.GetYear() && this->GetMonth()==other.GetMonth() && this->GetDay()>other.GetDay() ) return true;
    else 
		return false;
}

void Date::PrintDate ()
{
	std::cout << "\n";
	PrintWeekDay();
	std::cout << " " << static_cast<uint16_t>(day) << "/" << static_cast<uint16_t>(month) << "/" << static_cast<uint16_t>(year) << "\n";
}

void Date::PrintWeekDay ()
{
	if (week_day==1) std::cout << "Monday";
	else if (week_day==2) std::cout << "Tuesday";
	else if (week_day==3) std::cout << "Wednesday";
	else if (week_day==4) std::cout << "Thursday";
	else if (week_day==5) std::cout << "Friday";
	else if (week_day==6) std::cout << "Saturday";
	else std::cout << "Sunday";
}
