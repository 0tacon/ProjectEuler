#include <iostream>
#include <cstdint>
#include <map>

class Date
{
	public:
		
		Date();
		~Date();
		
		void IncrementBy1Week();
		
		bool IsLeapYear();
		
		uint8_t GetDaysInMonth ();
		
		bool operator>(const Date& other);
		
		void PrintDate();
		
		uint8_t GetYear() const { return year; }
		uint8_t GetMonth() const { return month; }
		uint8_t GetDay() const { return day; }
		
	private:
		
		uint8_t day, month;
		
		uint16_t year;
};

Date::Date ()
{
	day = 1;
	month = 1;
	year = 1900;
}

Date::~Date () {}

void Date::IncrementBy1Week ()
{
	day += 7;
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
	if (year%100 == 0)
	{
		if (year%400 == 0)
		{
			return true;
		}
	}
	else if (year&4 == 0) return true;
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

bool Date::operator>(const Date& other)
{
    if ( this->GetYear() > other.GetYear() ) return true;
    else if ( this->GetYear()==other.GetYear() && this->GetMonth()>other.GetMonth() ) return true;
    else if ( this->GetYear()==other.GetYear() && this->GetMonth()==other.GetMonth() && this->GetDay()>other.GetDay() ) return true;
    else false;
}

void Date::PrintDate ()
{
	std::cout << "\n" << static_cast<uint16_t>(day) << "/" << static_cast<uint16_t>(month) << "/" << static_cast<uint16_t>(year) << "\n";
}
