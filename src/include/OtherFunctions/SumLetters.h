#include <cstdint>
#include <string>

#define _SUMLETTERS_

uint64_t SumLetters(std::string str)
{
	uint64_t sum = 0;

	for (uint32_t i = 0; i < str.size(); i++)
		sum += str[i] - 64;

	return sum;
}