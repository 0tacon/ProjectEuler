#include <cstdint>
#include <string>
#include <iterator>

#define _DONUMSSHAREDIGITS_

template<typename T1, typename T2>
bool DoNumsShareDigits (T1 a, T2 b)
{
    std::string str_a = std::to_string(static_cast<uint64_t>(a)), str_b = std::to_string(static_cast<uint64_t>(b));

    for (std::string::iterator itr_a = str_a.begin(); itr_a != str_a.end(); itr_a++)
        for (std::string::iterator itr_b = str_b.begin(); itr_b != str_b.end(); itr_b++)
            if (*itr_a == *itr_b)
                return true;

    return false;
}
