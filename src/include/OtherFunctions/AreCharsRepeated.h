#include <cstdint>
#include <cstdio>
#include <string>
#include <iterator>
#include <algorithm>

#define _ARECHARSREPEATED_

bool AreCharsRepeated (std::string str)
{
    for (std::string::iterator i = str.begin(); i != str.end(); i++)
        if (std::count(str.begin(), str.end(), *i) > 1)
            return true;

    return false;
}
