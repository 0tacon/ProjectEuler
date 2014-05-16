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
	#include "..\\OtherFunctions\\ReadFileIntoVect.h"
#endif

std::vector<uint8_t> PosToCoord (uint16_t pos)
{
	std::vector<uint8_t> coord;
	
	if (pos%20==0) 
	{
		coord.push_back(20);
		coord.push_back( pos/20 );
	}
	else 
	{
		coord.push_back(pos%20);
		coord.push_back( ((pos - pos%20)/20)+1 );
	}
	
	return coord;
}

uint16_t CoordToPos (std::vector<uint8_t> coord)
{
	uint16_t pos;
	
	pos = ((coord[1]-1)*20 + coord[0])-1;
	
	return pos;
}

bool Extract2DigitNumbers (std::vector<uint8_t> &vect)
{
	std::vector<uint8_t> temp;
	
	for (uint16_t i=0; i<799; i+=2)	temp.push_back( vect[i]*10 + vect[i+1] );
	
	vect = temp;
	
	return true;
}

bool CreateMaps (	std::vector<uint8_t> 						&vect, 
					std::map<uint8_t, std::vector<uint8_t> > 	&rows, 
					std::map<uint8_t, std::vector<uint8_t> > 	&cols, 
					std::map<uint8_t, std::vector<uint8_t> > 	&fwd_diags, 
					std::map<uint8_t, std::vector<uint8_t> > 	&bck_diags		)
{
	uint8_t x, y;
	uint16_t count=0;
	std::vector<uint8_t> coord;
	
	// Create the maps for the rows and columns
	for ( std::vector<uint8_t>::iterator i=vect.begin(); i!=vect.end(); i++ )
	{
		count++;
		
		rows[ ((count-1)/20)+1 ].push_back(*i);
		
		if ( count%20!=0 ) cols[ count%20 ].push_back(*i);
		else cols[20].push_back(*i);
	}
	count=0;
	
	// Create the maps for the foward and backward facing diagonals
	for ( uint8_t i=4; i<21; i++ )
	{
		count++;
		
		x=i;
		y=1;
		
		coord.push_back(x);
		coord.push_back(y);
		
		while (coord[0] > 0)
		{
			fwd_diags[count].push_back( vect.at( CoordToPos(coord) ) );
			coord[0] -= 1;
			coord[1] += 1;
		}
		
		coord.erase(coord.begin(), coord.end());
		
		x=20;
		y=i;
		
		coord.push_back(x);
		coord.push_back(y);
		
		while (coord[1] > 0)
		{
			bck_diags[count].push_back( vect.at( CoordToPos(coord) ) );
			coord[0] -= 1;
			coord[1] -= 1;
		}
		
		coord.erase(coord.begin(), coord.end());
	}
	for ( uint8_t i=2; i<18; i++ )
	{
		count++;
		
		x=i;
		y=20;
		
		coord.push_back(x);
		coord.push_back(y);
		
		while (coord[0] < 21)
		{
			fwd_diags[count].push_back( vect.at( CoordToPos(coord) ) );
			coord[0] += 1;
			coord[1] -= 1;
		}
		
		coord.erase(coord.begin(), coord.end());
		
		x=1;
		y=i;
		
		coord.push_back(x);
		coord.push_back(y);
		
		while (coord[1] < 21)
		{
			bck_diags[count].push_back( vect.at( CoordToPos(coord) ) );
			coord[0] += 1;
			coord[1] += 1;
		}
		
		coord.erase(coord.begin(), coord.end());
	}
	
	return true;
}

uint32_t FindGreatestProduct (	std::map<uint8_t, std::vector<uint8_t> > 	&rows, 
								std::map<uint8_t, std::vector<uint8_t> > 	&cols, 
								std::map<uint8_t, std::vector<uint8_t> > 	&fwd_diags, 
								std::map<uint8_t, std::vector<uint8_t> > 	&bck_diags		)
{
	uint32_t product=0, largest_product=0;
	std::vector<uint8_t> temp;
	temp.resize(4);
	
	for ( uint8_t n = 1 ; n < 21 ; n++ )
	{
		for ( uint8_t i = 0; i < 17; i++ )
		{
			std::copy ( rows[n].begin()+i, rows[n].begin()+i+4, temp.begin() );
			
			product = 1;
			for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
			{
				product = product*(*itr);
			}
			if (product>largest_product) largest_product = product;
			
			std::copy ( cols[n].begin()+i, cols[n].begin()+i+4, temp.begin() );
			
			product = 1;
			for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
			{
				product = product*(*itr);
			}
			if (product>largest_product) largest_product = product;
		}
	}
	
	for ( uint8_t n = 1 ; n < 34 ; n++ )
	{
		for ( uint32_t i = 0; i < fwd_diags[n].size()-3; i++ )
		{
			std::copy ( fwd_diags[n].begin()+i, fwd_diags[n].begin()+i+4, temp.begin() );
			
			product = 1;
			for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
			{
				product = product*(*itr);
			}
			if (product>largest_product) largest_product = product;
			
			std::copy ( bck_diags[n].begin()+i, bck_diags[n].begin()+i+4, temp.begin() );
			
			product = 1;
			for ( std::vector<uint8_t>::iterator itr = temp.begin() ; itr != temp.end() ; itr++ )
			{
				product = product*(*itr);
			}
			if (product>largest_product) largest_product = product;
		}
	}
	
	return largest_product;
}

bool Problem11 ()
{
	std::vector<uint8_t> vect;
	std::map<uint8_t, std::vector<uint8_t> > rows, cols, fwd_diags, bck_diags;
	std::string filepath = "..\\data\\Problem11.txt";
	uint32_t prod;
		
	ReadFileIntoVect (vect, filepath);
	
	vect.erase( std::remove(vect.begin(), vect.end(), 240), vect.end() );
	
	Extract2DigitNumbers (vect);
	
	CreateMaps (vect, rows, cols, fwd_diags, bck_diags);
	
	prod = FindGreatestProduct (rows, cols, fwd_diags, bck_diags);
	
	std::cout << "\nProblem 011: " << prod << "\n";
	
	return true;
}
