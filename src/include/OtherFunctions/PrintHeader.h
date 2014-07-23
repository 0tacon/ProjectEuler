#include <iostream>
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

#include <ctime>

#define _PRINTHEADER_

void PrintHeader (void)
{
    std::time_t time = std::time(NULL);
    char strTime[11];
    std::strftime(strTime, sizeof(strTime), "%d/%m/%Y", std::localtime(&time));

	std::cout << "\n========================================\n";
	std::cout << "=                                      =\n";
	std::cout << "=            Project  Euler            =\n";
	std::cout << "=               1.00.001               =\n";
	std::cout << "=                                      =\n";
	std::cout << "========================================\n";
	std::cout << "=                                      =\n";
	std::cout << "=              " << strTime << "              =\n";
	std::cout << "=                                      =\n";
	std::cout << "========================================\n";
	std::cout << "=                                      =\n";
	std::cout << "=                0tacon                =\n";
	std::cout << "=                                      =\n";
	std::cout << "========================================\n\n";
}
