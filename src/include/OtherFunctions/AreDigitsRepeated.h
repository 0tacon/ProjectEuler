#include <cstdint>
#include <string>
#include <iterator>
#include <algorithm>

#define _AREDIGITSREPEATED_

template<typename T>
bool AreDigitsRepeated (T n)
{
    std::string str = std::to_string(static_cast<uint64_t>(n));

    for (std::string::iterator i = str.begin(); i != str.end(); i++)
        if (std::count(str.begin(), str.end(), *i) > 1)
            return true;

    return false;
}
