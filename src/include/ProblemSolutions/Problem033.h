/*
    The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
    which is correct, is obtained by cancelling the 9s.

    We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

    There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

    If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <cstdint>
#include <cstdio>
#include <vector>

#ifndef _FRACTION_
#include "../Classes/Fraction.h"
#endif // _FRACTION_

bool Problem33()
{
    std::vector<Fraction> vect;
    Fraction a_frac, other_frac, ans;
    uint16_t numerator = 1, denominator = 1;

    for (uint8_t num = 11; num < 100; num++)
        for (uint8_t denom = num + 1; denom < 100; denom++)
            if (num%10 != 0 && denom%10 != 0)
            {
                a_frac.SetNum(num);
                a_frac.SetDenom(denom);

                if (a_frac.DoNumDenomShareDigits())
                {
                    other_frac = a_frac.CancelIncorrectly();

                    if (a_frac.GetVal() == other_frac.GetVal())
                        vect.push_back(other_frac);
                }
            }

    for (std::vector<Fraction>::iterator itr = vect.begin(); itr != vect.end(); itr++)
    {
        numerator *= itr->GetNum();
        denominator *= itr->GetDenom();
    }

    ans.SetNum(numerator);
    ans.SetDenom(denominator);
    ans = ans.Cancel();

    printf("\nProblem 033: %d\n", ans.GetDenom());
    return true;
}
