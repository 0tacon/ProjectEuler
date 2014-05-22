/*
	The following iterative sequence is defined for the set of positive integers:
	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)
	
	Using the rule above and starting with 13, we generate the following sequence:
	13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
	
	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
	
	Which starting number, under one million, produces the longest chain?
	
	NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include <cstdint>

#ifndef _LENGTHOFCOLLATZSEQ_
	#include "..\\OtherFunctions\\LengthOfCollatzSeq.h"
#endif

bool Problem14()
{
	uint16_t max_seq_length=0, seq_length=1;
	double max_starting_num;
	
	for (double n=999999.0; n>10.0; n--)
	{
		LengthOfCollotzSeq(n, seq_length);
		
		if (seq_length>max_seq_length)
		{
			max_seq_length = seq_length;
			max_starting_num = n;
		}
		
		seq_length = 0;
	}

	std::cout << "\nProblem 014: " << max_starting_num << "\n";
	return true;
}
