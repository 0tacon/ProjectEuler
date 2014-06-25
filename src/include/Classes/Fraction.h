#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>

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
