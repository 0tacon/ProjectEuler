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
