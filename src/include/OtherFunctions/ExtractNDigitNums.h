#include <vector>
#include <cmath>
#include <iostream>

#define _EXTRACTNDIGITNUMS_

template<typename T, typename t>
void ExtractNDigitNums (std::vector<T> &v, t n)
{
	if (fmod(static_cast<double>(v.size()), static_cast<double>(n)) != 0.0)
	{
		std::cout << "\nError: Vector size is not an integer multiple of n.\n";
	}
	else
	{
		std::vector<T> temp_vect;
		T temp_num=0;
		
		for (t i = 0; i < v.size()-n+1; i+=n)
		{
			temp_num=0;
			
			for (t j = 1; j < n+1; j++)
				temp_num += v[i+(j-1)]*pow(10, n-j);
			
			temp_vect.push_back(temp_num);			
		}
		
		v = temp_vect;
	}
}
