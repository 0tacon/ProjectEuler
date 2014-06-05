#include <cstdint>
#include <vector>

#ifndef _GETNUMDIGITS_
#include  "../OtherFunctions/GetNumDigits.h"
#endif

#define _GETQUOTIENT_

void GetQuotient (std::vector<uint16_t> &ans, uint16_t &num, uint16_t denom)
{
    uint16_t temp = 1, rem = num, c = 0;

    while (std::count(ans.begin(), ans.end(), num) < 2 || c <= GetNumDigits(denom))
    {
        temp = rem;
        rem = (10*temp)%denom;
        num = ((10*temp) - rem)/denom;

        ans.push_back(num);
        c++;
    }

    num = temp;

    ans.erase(std::prev(ans.end(), 1), ans.end());
}
