#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

#ifndef _GETMAXELEMENTINDEX_
	#include "..\\OtherFunctions\\GetMaxElementIndex.h"
#endif

#define _NUMERICTRIANGLE_

class NumericTriangle
{
	public:
		NumericTriangle (std::vector<uint16_t>);
		~NumericTriangle ();
		
		void PrintTriangle();
		
		bool IsValidPath (std::vector<uint16_t>);
		
		uint64_t FindHighestPathSum ();
		
	private:
		std::map<uint16_t, std::vector<uint16_t> > tri_rows;
		
		uint16_t num_rows;
};

NumericTriangle::NumericTriangle (std::vector<uint16_t> vect)
{
	uint16_t vect_element = 0;
	num_rows = (sqrt(1+8*vect.size()) - 1)/2;

	for (uint8_t row = 1; row < num_rows+1; row++)
		for ( uint8_t element = 1; element < row+1; element++ )
		{
			tri_rows[row].push_back(vect[vect_element]);
			vect_element++;
		}
}

NumericTriangle::~NumericTriangle () {}

void NumericTriangle::PrintTriangle ()
{
	for (std::map<uint16_t, std::vector<uint16_t> >::iterator row = tri_rows.begin(); row != tri_rows.end(); row++)
	{
		for (std::vector<uint16_t>::iterator element = row->second.begin(); element != row->second.end(); element++)
		{
			std::cout << *element << " ";
		}
		std::cout << "\n";
	}
}

bool NumericTriangle::IsValidPath (std::vector<uint16_t> path)
{
	if (path.size() != num_rows)
		return false;
	
	bool validity = true;
	
	uint16_t pos = 1;
	while (pos < path.size() && validity)
	{
		if (path[pos] != path[pos-1] && path[pos] != path[pos-1]+1)
			validity = false;
			
		pos++;
	}
	
	return validity;
}

uint64_t NumericTriangle::FindHighestPathSum ()
{
	uint64_t sum = 0;
	std::vector<uint16_t> path;
	
	for (std::map<uint16_t, std::vector<uint16_t> >::iterator row = tri_rows.begin(); row != tri_rows.end(); row++)
	{
		path.push_back (GetMaxElementIndex(row->second));
		sum += GetMaxElement(row->second);
	}
	
	if (!IsValidPath(path)) std::cout << "\nNot a valid path\n";
	
	return sum;
}
