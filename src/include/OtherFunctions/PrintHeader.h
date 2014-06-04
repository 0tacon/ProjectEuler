#include <iostream>
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
