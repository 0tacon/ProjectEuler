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

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

#define _READFILEINTOVECT_

template<typename T>
bool ReadFileIntoVect ( std::vector<T> &vect, std::string &filepath )
{
	std::fstream file;
	char c;

	file.open(filepath.c_str(), std::ios::in);

	if ( !file.is_open() )
	{
		file.clear();
		std::cout << "\nError: file does not exist...\n";
		return false;
	}
	else
		while ( file.get(c) )
            vect.push_back(c);

	file.close();

	return true;
}
