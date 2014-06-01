/*
	A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

	012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

bool Problem24()
{
	std::string str = "0123456789";

	for (uint32_t i = 0; i < 999999; i++)
		std::next_permutation(str.begin(), str.end());

	printf("\nProblem 024: %s\n", str);
	return true;
}