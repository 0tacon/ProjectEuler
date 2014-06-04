#include <cstdint>
#include <cmath>

#define _LENGTHOFCOLLATZSEQ_

bool LengthOfCollotzSeq (double n, uint16_t &seq_length)
{
	if (fmod(n,2.0)==0.0)
        n = n/2.0;

	else
        n = 3.0*n + 1.0;

	seq_length++;

	if (n>1.0)
        LengthOfCollotzSeq(n, seq_length);

	else if (n==1.0)
        return true;


    return false;
}
