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
#include <vector>

#define _PRINTVECTOR_

template <typename T>
bool PrintVector ( std::vector<T> &v )
{
    std::cout << "\n";
	for ( typename std::vector<T>::iterator i=v.begin() ; i!=v.end() ; i++ )
	{
		if ( i!=v.begin() )	std::cout << ", ";
		std::cout << static_cast<uint64_t>(*i);
	}
    std::cout << "\n";
	return true;
}
