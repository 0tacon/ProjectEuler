#include <iostream>
#include <vector>

template <typename T>
bool PrintVector ( std::vector<T> &v )
{
	for ( typename std::vector<T>::iterator i=v.begin() ; i!=v.end() ; i++ )
	{
		if ( i!=v.begin() )	std::cout << ", ";
		std::cout << *i;
	}
	return true;
}
