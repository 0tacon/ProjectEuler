/*
	Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

	For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file?
*/

#include <iostream>
#include <cstdint>
#include <string>

#ifndef _NAMELIST_
#include "..//Classes//NameList.h"
#endif

bool Problem22()
{
	std::string filename = "../../data/names.txt";

	NameList name_list(filename);

	std::cout << "\nProblem 022: " << name_list.SumAlphaScores() << "\n";
	return true;
}
