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

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#ifndef _READFILEINTOVECT_
#include "..//OtherFunctions//ReadFileIntoVect.h"
#endif

#ifndef _SUMLETTERS_
#include "..//OtherFunctions//SumLetters.h"
#endif

#define _NAMELIST_

class NameList
{
public:
	NameList(std::string);
	~NameList();

	void Print();

	uint64_t SumAlphaScores();

private:
	std::map<uint32_t, std::string> name_list;
};

NameList::NameList(std::string filename)
{
	uint32_t index = 1;
	std::vector<uint8_t> vect;
	std::vector<std::string> temp;
	ReadFileIntoVect(vect, filename);

    vect.erase(std::remove(vect.begin(), vect.end(), 13), vect.end());
    vect.erase(std::remove(vect.begin(), vect.end(), 10), vect.end());
	for (uint32_t i = 0; i < vect.size(); i++)
        vect[i] -= 48;

	for (uint32_t i = 0; i < vect.size(); i++)
		vect.at(i) += 48;

	for (std::vector<uint8_t>::iterator i = vect.begin(); i != vect.end(); i++)
	{
		if (*i != '"' && *i != ',')
			name_list[index] += *i;
		else if (*i == ',')
			index++;
	}

	index = 1;

	for (std::map<uint32_t, std::string>::iterator i = name_list.begin(); i != name_list.end(); i++)
		temp.push_back(i->second);

	std::sort(temp.begin(), temp.end());

	name_list.clear();

	for (std::vector<std::string>::iterator i = temp.begin(); i != temp.end(); i++)
	{
		name_list[index] = *i;
		index++;
	}
}

NameList::~NameList() {}

void NameList::Print()
{
	for (std::map<uint32_t, std::string>::iterator i = name_list.begin(); i != name_list.end(); i++)
		std::cout << "\nName #" << i->first << " = " + i->second;
}

uint64_t NameList::SumAlphaScores()
{
	uint64_t sum = 0;

	for (std::map<uint32_t, std::string>::iterator i = name_list.begin(); i != name_list.end(); i++)
		sum += i->first * SumLetters(i->second);

	return sum;
}
