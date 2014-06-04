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