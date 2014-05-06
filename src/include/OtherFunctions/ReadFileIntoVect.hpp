#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>

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
	{
		while ( file.get(c) ) 
		{
			if ( c != '\n' )	vect.push_back( c-48 );
		}
	}
	
	file.close();
	
	return true;
}
