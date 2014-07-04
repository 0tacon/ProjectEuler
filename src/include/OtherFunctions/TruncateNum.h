#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>

#define _TRUNCATENUM_

template<typename T>
uint64_t TruncateNum (T n, T r, char from_dir)
{
    uint64_t result = 0, rem = static_cast<uint64_t>(r);
    std::string str;

    str = std::to_string(static_cast<uint64_t>(n));

    if (r >= str.size())
    {
        printf("\nError: Attempting to truncate too many digits.\n");
        return result;
    }

    if (from_dir == 'L')
        str.erase(str.begin(), std::next(str.begin(), rem));
    else if (from_dir == 'R')
        str.erase(std::prev(str.end(), rem), str.end());
    else
    {
        printf("\nError: Invalid truncation direction.\n");
        return result;
    }

    result = std::stoi(str);

    return result;
}
