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

#ifndef _STRINGNUM_
#define _STRINGNUM_

#include <cstdint>
#include <string>

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

	StringNum operator^(StringNum other);

	uint64_t SumDigits();

	void Print();

	void TruncateStringNum(uint64_t n);

private:
	std::string number;
	uint16_t first_digit_index;
};

#endif //_STRINGNUM_