#include <cstdint>
#include <map>

#ifndef _GETDIGIT_
	#include "..\\OtherFunctions\\GetDigit.h"
#endif

#define _GETLETTERSINNUM_

template<typename T>
uint8_t GetLettersInNum (T n)
{
	uint8_t letters=0;
	std::map<uint8_t, uint8_t> unit, ten, teen;		// Param1: Number, Param2: Corresponding letter count
	
	unit[0] = 0;
	unit[1] = 3;	//one
	unit[2] = 3;	//two
	unit[3] = 5;	//three
	unit[4] = 4;	//four
	unit[5] = 4;	//five
	unit[6] = 3;	//six
	unit[7] = 5;	//seven
	unit[8] = 5;	//eight
	unit[9] = 4;	//nine
	
	ten[0] = 0;
	ten[2] = 6;		//twenty
	ten[3] = 6;		//thirty
	ten[4] = 5;		//forty
	ten[5] = 5;		//fifty
	ten[6] = 5;		//sixty
	ten[7] = 7;		//seventy
	ten[8] = 6;		//eighty
	ten[9] = 6;		//ninety
	
	teen[10] = 3;	//ten
	teen[11] = 6;	//eleven
	teen[12] = 6;	//twelve
	teen[13] = 8;	//thirteen
	teen[14] = 8;	//fourteen
	teen[15] = 7;	//fifteen
	teen[16] = 7;	//sixteen
	teen[17] = 9;	//seventeen
	teen[18] = 8;	//eighteen
	teen[19] = 8;	//nineteen
	
	if (GetNumDigits(n)>1)
	{
		for (uint8_t i=GetNumDigits(n); i>1; i--)
		{
			if (i==2 && GetDigit(n, 2)==1)
			{
				letters += teen[ 10*GetDigit(n, 2) + GetDigit(n, 1) ];
			}
			else if (i==2)
			{
				letters += ten[GetDigit(n, 2)] + unit[GetDigit(n, 1)];
			}
			else
			{
				if (GetDigit(n, 2)==0 && GetDigit(n, 1)==0) letters += unit[GetDigit(n, 3)] + 7;
				else letters += unit[GetDigit(n, 3)] + 10;
			}
		}
	}
	else letters += unit[n];
	
	return letters;
}
