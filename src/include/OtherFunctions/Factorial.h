#include <cstdint>

#define _FACTORIAL_

template<typename T>
double Factorial (T n)
{
	double fact = 1;
	T temp = n;
	
	while (temp > 1)
	{
		fact *= temp;
		temp--;
	}
	
	return fact;
}

template<typename T>
uint64_t Factorial (T n, T k)
{
	uint64_t fact = 1;
	T temp = n;
	
	while (temp > n - k)
	{
		fact *= temp;
		temp--;
	}
	
	return fact;
}
