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
#include <vector>

#define _GETALLPOSSIBLEPRODUCTS_

template<typename T>
void GetAllPossibleProducts(T &n, std::vector<T> &vect, std::vector<T> &products)
{
	std::vector<T> temp;
	T new_n;

	for (uint32_t i = 0; i < vect.size(); i++)
	{
		products.push_back(n*vect.at(i));

		if (vect.size() > 1 && i+1 < vect.size())
		{
			for (uint32_t j = i+1; j < vect.size(); j++)
				temp.push_back(vect.at(j));

			new_n = n*vect.at(i);

			GetAllPossibleProducts(new_n, temp, products);

			temp.clear();
		}
	}
}
