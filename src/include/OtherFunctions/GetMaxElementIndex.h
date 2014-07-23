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
#include <algorithm>

#define _GETMAXELEMENTINDEX_

template<typename T>
uint16_t GetMaxElementIndex (std::vector<T> vect)
{
	uint16_t index = std::distance(vect.begin(), std::max_element(vect.begin(), vect.end()));
	return index;
}

template<typename T>
uint16_t GetMaxElement (std::vector<T> vect)
{
	typename std::vector<T>::iterator max_element = std::max_element(vect.begin(), vect.end());
	return *max_element;
}

template<typename T>
uint16_t GetNextHighestElementIndex (std::vector<T> vect, T max)
{
	std::replace_if(vect.begin(), vect.end(), std::bind(std::greater_equal<T>(), std::placeholders::_1, max), 0);

	uint16_t index = std::distance(vect.begin(), std::max_element(vect.begin(), vect.end()));

	return index;
}

template<typename T>
uint16_t GetDiffBetweenElementAndNextHighest (std::vector<T> vect, T max)
{
	std::replace_if(vect.begin(), vect.end(), std::bind(std::greater_equal<T>(), std::placeholders::_1, max), 0);

	typename std::vector<T>::iterator max_element = std::max_element(vect.begin(), vect.end());

	uint16_t diff = max - *max_element;

	return diff;
}
