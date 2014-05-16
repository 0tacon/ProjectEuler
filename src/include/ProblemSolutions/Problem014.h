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
#include <cmath>

bool func (double n, uint16_t &seq_length)
{
	if (fmod(n,2.0)==0.0)	n = n/2.0;
	
	else n = 3.0*n + 1.0;
	
	seq_length++;
	
	if (n>1.0) func(n, seq_length);
	
	else if (n==1.0) return true;
	
	else return false;
}

bool Problem14()
{
	uint16_t max_seq_length=0, seq_length=1;
	double max_starting_num;
	
	for (double n=999999.0; n>10.0; n--)
	{
		
		func(n, seq_length);
		
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
