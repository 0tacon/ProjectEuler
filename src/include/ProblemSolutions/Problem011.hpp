/*
	What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally)
	in the 20×20 grid in Problem11.txt?
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>

#ifndef _READFILEINTOVECT_
	#include "..\\OtherFunctions\\ReadFileIntoVect.hpp"
	#define _READFILEINTOVECT_
#endif

#ifndef _PRINTVECTOR_
	#include "..\\OtherFunctions\\PrintVector.hpp"
	#define _PRINTVECTOR_
#endif

bool Extract2DigitNumbers (std::vector<uint16_t> &vect)
{
	std::vector<uint16_t> temp;
	
	for (uint16_t i=0; i<799; i+=2)	temp.push_back( vect[i]*10 + vect[i+1] );
	
	vect = temp;
	
	return true;
}

bool CreateMaps (	std::vector<uint16_t> 						&vect, 
					std::map<uint8_t, std::vector<uint16_t> > 	&rows, 
					std::map<uint8_t, std::vector<uint16_t> > 	&cols, 
					std::map<uint8_t, std::vector<uint16_t> > 	&fwd_diags, 
					std::map<uint8_t, std::vector<uint16_t> > 	&bck_diags		)
{
	uint16_t count=0;
	
	for ( std::vector<uint16_t>::iterator i=vect.begin(); i!=vect.end(); i++ )
	{
		rows[ (count/20)+1 ].push_back(*i);
		
		count++;
		
		if ( count%20!=0 ) cols[ count%20 ].push_back(*i);
		else cols[20].push_back(*i);
	}
	
	return true;
}

bool Problem11 ()
{
	std::vector<uint16_t> vect;
	std::map<uint8_t, std::vector<uint16_t> > rows, cols, fwd_diags, bck_diags;
	std::string filepath = "..\\data\\Problem11.txt";
		
	ReadFileIntoVect (vect, filepath);
	
	vect.erase( std::remove(vect.begin(), vect.end(), 65520), vect.end() );
	
	Extract2DigitNumbers (vect);
	
	CreateMaps (vect, rows, cols, fwd_diags, bck_diags);
	
	std::cout << "\nProblem 011:\n";
	
	return true;
}
