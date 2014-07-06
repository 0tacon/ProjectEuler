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
