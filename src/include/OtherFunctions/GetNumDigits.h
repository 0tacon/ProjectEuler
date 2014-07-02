#include <cstdint>
#include <cmath>
#include <cstring>

#define _GETNUMDIGITS_

template<typename T>
uint8_t GetNumDigits (T num)
{
	std::string str = std::to_string(static_cast<uint64_t>(num));

    return str.size();
}
