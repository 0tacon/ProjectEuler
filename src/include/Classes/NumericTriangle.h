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

#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

#ifndef _GETMAXELEMENTINDEX_
	#include "../OtherFunctions/GetMaxElementIndex.h"
#endif

#define _NUMERICTRIANGLE_

class NumericTriangle
{
public:
	NumericTriangle (std::vector<uint16_t>);
	~NumericTriangle ();

	void PrintTriangle();

	bool IsValidPath (std::vector<uint16_t>);

	void RecursivePathSum (uint32_t &current_sum, uint32_t &largest_sum, uint16_t &row, uint16_t &node_index);

	uint64_t FindHighestPathSum ();

private:
	std::map<uint16_t, std::vector<uint16_t> > tri_rows;

	uint16_t num_rows;
};

NumericTriangle::NumericTriangle (std::vector<uint16_t> vect)
{
	uint16_t vect_element = 0;
	num_rows = (sqrt(1+8*vect.size()) - 1)/2;

	for (uint16_t row = 1; row < num_rows+1; row++)
		for ( uint16_t element = 1; element < row+1; element++ )
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
		for (uint8_t i = 0; i < 2*(num_rows-row->first)+5; i++)
				std::cout << " ";

		for (std::vector<uint16_t>::iterator element = row->second.begin(); element != row->second.end(); element++)
		{
			if (*element < 10)
				std::cout << "0";

			std::cout << *element << "  ";
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

void NumericTriangle::RecursivePathSum (uint32_t &current_sum, uint32_t &largest_sum, uint16_t &row, uint16_t &node_index)
{
	row++;

	if (row < tri_rows.size()+1)
	{
		for (uint16_t leaf_index = node_index; leaf_index < node_index+2 && leaf_index < tri_rows.at(row).size(); leaf_index++)
		{
			//std::cout << "\nElement = " << tri_rows.at(row).at(leaf_index);
			current_sum += tri_rows.at(row).at(leaf_index);

			if (current_sum > largest_sum)
				largest_sum = current_sum;

			RecursivePathSum (current_sum, largest_sum, row, leaf_index);

			//std::cout << "\nCurrent Sum = " << current_sum << "\n";
			current_sum -= tri_rows.at(row).at(leaf_index);
		}
	}

	row--;
}

uint64_t NumericTriangle::FindHighestPathSum ()
{
	uint32_t current_sum = 0, largest_sum = 0;
	uint16_t row = 0, node_index = 0;

	RecursivePathSum (current_sum, largest_sum, row, node_index);

	return largest_sum;
}
