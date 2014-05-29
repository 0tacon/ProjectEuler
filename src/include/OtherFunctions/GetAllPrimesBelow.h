#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <functional>

#define _GETALLPRIMESBELOW_

template<typename T>
std::vector<uint32_t> GetAllPrimesBelow (T max)
{
	std::vector<uint32_t> ret;
	std::map<uint32_t, bool> primes;
	
	if (max < 2)
	{
		ret.push_back(0);
		return ret;
	}
	else if ( max == 2 ) 
	{
		ret.push_back(2);
		return ret;
	}
	else
	{
		for (uint32_t i = 3; i < max; i += 2)
			primes[i] = true;
		
		for (uint32_t i = 3; i < sqrt(max); i += 2)
			if (primes[i] == true)
				for (uint32_t n = i*i; n < max; n+=i)
					primes[n] = false;

		for (std::map<uint32_t, bool>::iterator p = primes.begin(); p != primes.end(); p++)
			if (p->second == true)
				ret.push_back(p->first);
		
		ret.insert(ret.begin(), 2);
		return ret;
	}
}
