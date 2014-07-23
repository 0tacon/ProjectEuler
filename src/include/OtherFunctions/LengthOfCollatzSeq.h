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
