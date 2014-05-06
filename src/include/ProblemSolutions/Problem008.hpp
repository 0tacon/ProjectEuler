/*
	Find the greatest product of five consecutive digits in the 1000-digit number stored in Problem8.txt
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

#ifndef _READFILEINTOVECT_
	#include "..\\OtherFunctions\\ReadFileIntoVect.hpp"
	#define _READFILEINTOVECT_
#endif

bool Problem8 ()
{
	std::vector<uint8_t> vect, temp;
	uint16_t product=0, largest_product=0;
	std::string filepath = "..\\data\\Problem8.txt";
	
	ReadFileIntoVect (vect, filepath);
	
	temp.resize(5);
	
	for ( uint16_t i = 0 ; i < 996 ; i++ )
	{
		std::copy ( vect.begin()+i, vect.begin()+i+5, temp.begin() );
		
		product = 1;
		for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
		{
			product = product*(*itr);
		}
		if (product>largest_product) largest_product = product;
	}
	
	std::cout << "\nProblem 008: " << largest_product << "\n";
	
	return true;
}
