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

#include <string>

#define _STRINGNUM_

class StringNum
{
public:
	StringNum();
	~StringNum();
	StringNum(std::string);

	void SetNum(std::string str);

	std::string GetNum() const { return number; }
	uint16_t Get1stDigitIndex() const { return first_digit_index; }

	StringNum operator+(StringNum other);
	StringNum operator-(StringNum other);
	StringNum operator*(StringNum other);
	bool operator==(const StringNum other);

	uint64_t SumDigits();

	void Print();

private:
	std::string number;
	uint16_t first_digit_index;
};

StringNum::StringNum()
{
	number = "0.000000";
	first_digit_index = 0;
}

StringNum::~StringNum() {}

StringNum::StringNum(std::string str)
{
	number = str;

	uint16_t i = 0;
	while (str[i] != '.')
		i++;

	first_digit_index = i - 1;
}

void StringNum::Print() { std::cout << "\n" << number << "\n"; }

void StringNum::SetNum(std::string str)
{
	number = str;

	uint16_t i = 0;
	while (str[i] != '.')
		i++;

	first_digit_index = i - 1;
}

StringNum StringNum::operator+(StringNum other)
{
	std::string sum = ".000000";
	uint16_t this_num_index = first_digit_index + 1, other_num_index = other.Get1stDigitIndex() + 1, sum_num = 0, carry = 0, unit = 0;

	while (this_num_index != 0 || other_num_index != 0)
	{
		sum_num = carry;

		if (this_num_index > 0)
		{
			this_num_index--;

			sum_num += number[this_num_index] - 48;
		}

		if (other_num_index > 0)
		{
			other_num_index--;

			sum_num += other.GetNum()[other_num_index] - 48;
		}

		if (sum_num > 9)
			carry = 1;
		else
			carry = 0;

		unit = sum_num % 10;

		sum.insert(0, 1, unit + 48);
	}

	if (carry == 1)
		sum.insert(0, 1, '1');

	StringNum result(sum);

	return result;
}

uint64_t StringNum::SumDigits()
{
	uint64_t sum = 0;

	uint16_t i = 0;
	while (number[i] != '.')
	{
		sum += number[i] - 48;
		i++;
	}

	return sum;
}

StringNum StringNum::operator-(StringNum other)
{
	std::string diff = ".000000";
	uint16_t this_num_index = first_digit_index + 1, other_num_index = other.Get1stDigitIndex() + 1;
	int16_t diff_num = 0, carry = 0, unit = 0;

	/*std::cout << "\nfirst_digit_index" << first_digit_index;
	std::cout << "\nother.Get1stDigitIndex()" << other.Get1stDigitIndex();*/

	while (this_num_index != 0 || other_num_index != 0)
	{
		diff_num = carry;

		if (this_num_index > 0)
		{
			this_num_index--;

			/*std::cout << "\nthis_num_index" << this_num_index;
			std::cout << "\nnumber[this_num_index] = " << number[this_num_index];*/
			diff_num += number[this_num_index] - 48;
		}

		if (other_num_index > 0)
		{
			other_num_index--;

			/*std::cout << "\nother_num_index" << other_num_index;
			std::cout << "\nother.GetNum()[other_num_index] = " << other.GetNum()[other_num_index];*/
			diff_num -= other.GetNum()[other_num_index] - 48;
		}

		if (diff_num < 1)
		{
			if (diff_num != 0)
			{
				unit = 10 + diff_num;
				carry = -1;
			}
			else
			{
				unit = 0;
				carry = 0;
			}
		}
		else
		{
			carry = 0;
			unit = diff_num;
		}

		diff.insert(0, 1, unit + 48);

		/*std::cout << "\ndiff_num = " << diff_num;
		std::cout << "\nunit = " << unit;
		std::cout << "\ncarry = " << carry;

		std::cout << "\n" + diff;*/
	}

	StringNum result(diff);

	std::string str = result.GetNum();

	if (str[0] == '0')
	{
		uint16_t i = 0;
		while (str[i] == '0')
			i++;

		result.SetNum(str.erase(0, i));
	}

	return result;
}

StringNum StringNum::operator*(StringNum other)
{
	StringNum unity("1.000000"), result;

	for (StringNum i = other; i.GetNum() != ".000000"; i = i - unity)
	{
		result = result + *this;
		//i.Print();
		//result.Print();
	}

	return result;
}

bool StringNum::operator==(const StringNum other)
{
    if (this->GetNum() == other.GetNum())
        return true;
    else
        return false;
}
