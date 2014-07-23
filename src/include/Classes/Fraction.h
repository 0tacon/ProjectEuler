/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

#ifndef _GETPRIMEFACTORS_
#include "../OtherFunctions/GetPrimeFactors.h"
#endif // _GETPRIMEFACTORS_

#ifndef _ISDIVISIBLE_
#include "../OtherFunctions/IsDivisible.h"
#endif // _ISDIVISIBLE_

#ifndef _PRINTVECTOR_
#include "../OtherFunctions/PrintVector.h"
#endif // _PRINTVECTOR_

#define _FRACTION_

class Fraction
{
public:
    Fraction();
    ~Fraction();

    uint32_t GetNum() { return num; }
    uint32_t GetDenom() { return denom; }
    float GetVal() { return val; }

    void SetNum(uint32_t n)
    {
        num = n;
        if (denom != 0)
            val = (static_cast<float>(num))/(static_cast<float>(denom));
    }
    void SetDenom(uint32_t d)
    {
        denom = d;
        if (denom != 0)
            val = (static_cast<float>(num))/(static_cast<float>(denom));
    }

    void Print() { printf("\n%d/%d = %f\n", num, denom, val); }

    bool DoNumDenomShareDigits();

    Fraction Cancel();

    Fraction CancelIncorrectly();

private:
    uint32_t num;
    uint32_t denom;
    float val;
};

Fraction::Fraction()
{
    num = 0;
    denom = 0;
    val = 0;
}

Fraction::~Fraction() {}

bool Fraction::DoNumDenomShareDigits()
{
    std::string str_num, str_denom;

    str_num = std::to_string(num);
    str_denom = std::to_string(denom);

    for (std::string::iterator digit = str_num.begin(); digit != str_num.end(); digit++)
        if (std::count(str_denom.begin(), str_denom.end(), *digit) > 0)
            return true;

    return false;
}

Fraction Fraction::CancelIncorrectly()
{
    Fraction ans;
    char number = '0';
    std::string str_num, str_denom;

    str_num = std::to_string(num);
    str_denom = std::to_string(denom);

    for (std::string::iterator digit = str_num.begin(); digit != str_num.end(); digit++)
        if (std::count(str_denom.begin(), str_denom.end(), *digit) > 0)
            number = *digit;

    if (number != 0)
    {
        str_num.erase(std::find(str_num.begin(), str_num.end(), number), std::next(std::find(str_num.begin(), str_num.end(), number), 1));
        str_denom.erase(std::find(str_denom.begin(), str_denom.end(), number), std::next(std::find(str_denom.begin(), str_denom.end(), number), 1));
    }

    ans.SetNum(stoi(str_num));
    ans.SetDenom(stoi(str_denom));

    return ans;
}

Fraction Fraction::Cancel()
{
    Fraction ans;
    uint32_t ans_num = 1, ans_denom = 1;
    bool factor_cancelled = true;

    std::map<uint32_t, uint32_t> num_factors = GetPrimeFactors(static_cast<uint32_t>(num)), denom_factors = GetPrimeFactors(static_cast<uint32_t>(denom));

    std::vector<uint32_t> num_prod, denom_prod;

    for (std::map<uint32_t, uint32_t>::iterator factor = num_factors.begin(); factor != num_factors.end(); factor++)
        for (uint8_t i = 0; i < factor->second; i++)
            num_prod.push_back(factor->first);

    for (std::map<uint32_t, uint32_t>::iterator factor = denom_factors.begin(); factor != denom_factors.end(); factor++)
        for (uint8_t i = 0; i < factor->second; i++)
            denom_prod.push_back(factor->first);

    // Cancel out all common factors in numerator and denominator product vectors
	while (factor_cancelled)
	{
		factor_cancelled = false;

		for (uint16_t a = 0; a < num_prod.size(); a++)
			for (uint16_t b = 0; b < denom_prod.size(); b++)
			{
				if (num_prod[a] != 1 && denom_prod[b] != 1)
				{
					if (IsDivisible(num_prod[a], denom_prod[b]))
					{
						num_prod[a] = num_prod[a] / denom_prod[b];
						denom_prod[b] = 1;
						factor_cancelled = true;
					}
					else if (num_prod[a] == denom_prod[b])
					{
						num_prod[a] = 1;
						denom_prod[b] = 1;
						factor_cancelled = true;
					}
				}
			}
	}

    for (std::vector<uint32_t>::iterator i = num_prod.begin(); i != num_prod.end(); i++)
        ans_num *= *i;
    for (std::vector<uint32_t>::iterator i = denom_prod.begin(); i != denom_prod.end(); i++)
        ans_denom *= *i;

    ans.SetNum(ans_num);
    ans.SetDenom(ans_denom);

    return ans;
}
