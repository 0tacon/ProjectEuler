#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

#define _ISPANDIGITAL_

template<typename T>
bool IsPanDigital (T n)
{
    std::string str = std::to_string(static_cast<uint64_t>(n)), ref_str = "";

    if (str.size() < 10)
    {
        for (uint8_t i = 0; i < str.size(); i++)
            ref_str += std::to_string(i+1);

        if (std::is_permutation(str.begin(), str.end(), ref_str.begin()))
            return true;
    }
    else
        printf("\nError: Number has to many digits to be pandigital.\n");

    return false;
}
