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

/*
    The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

    Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

        d2d3d4=406 is divisible by 2
        d3d4d5=063 is divisible by 3
        d4d5d6=635 is divisible by 5
        d5d6d7=357 is divisible by 7
        d6d7d8=572 is divisible by 11
        d7d8d9=728 is divisible by 13
        d8d9d10=289 is divisible by 17

    Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

#ifndef _ARECHARSREPEATED_
#include "../OtherFunctions/AreCharsRepeated.h"
#endif // _ARECHARSREPEATED_

#include "../Classes/StringNum.h"

void Problem43_RecursiveLoop (std::map<uint8_t, std::vector<std::string> > &numbers, std::string &current_concatenation, uint8_t &num_set, std::vector<std::string> &possible_concatenations);

bool Problem43()
{
    std::vector<uint16_t> primes = {2,3,5,7,11,13,17};
    std::map<uint8_t, std::vector<std::string> > numbers;
    uint8_t num_set = 0;
    std::string temp_num, current_concatenation;
    std::vector<std::string> possible_concatenations;
    StringNum ans("0.000000"), temp_stringnum("0.000000");

    for (std::vector<uint16_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
    {
        for (uint16_t i = (10/ *prime); i < (1000/ *prime) + 1; i++)
        {
            temp_num = std::to_string(*prime*i);

            if (temp_num.size() == 2 || temp_num.size() == 3)
            {
                if (temp_num.size() == 2)
                    temp_num = "0" + temp_num;

                if (!AreCharsRepeated(temp_num))
                    numbers[num_set].push_back(temp_num);
            }
        }

        num_set++;
    }

    num_set = 1;
    std::map<uint8_t, std::vector<std::string> >::iterator number_set = numbers.begin();
    for (std::vector<std::string>::iterator num = number_set->second.begin(); num != number_set->second.end(); num++)
    {
        if (num->at(0) != '0')
        {
            current_concatenation = *num;

            Problem43_RecursiveLoop(numbers, current_concatenation, num_set, possible_concatenations);
        }
    }

    for (uint8_t itr = 0; itr < possible_concatenations.size(); itr++)
        for (uint8_t i = 1; i < 10; i++)
            if (std::count(possible_concatenations[itr].begin(), possible_concatenations[itr].end(), i + '0') == 0)
                possible_concatenations[itr] = std::to_string(i) + possible_concatenations[itr];

    for (std::vector<std::string>::iterator itr = possible_concatenations.begin(); itr != possible_concatenations.end(); itr++)
    {
        temp_stringnum.SetNum(*itr + ".000000");
        ans = ans + temp_stringnum;
    }

    std::printf("\nProblem 043: %s\n", ans.GetNum().c_str());
    return true;
}

void Problem43_RecursiveLoop (std::map<uint8_t, std::vector<std::string> > &numbers, std::string &current_concatenation, uint8_t &num_set, std::vector<std::string> &possible_concatenations)
{
    std::string str_a, str_b;

    str_a = current_concatenation;
    str_a.erase(str_a.begin(), std::prev(str_a.end(), 2));

    std::map<uint8_t, std::vector<std::string> >::iterator number_set = std::next(numbers.begin(), num_set);
    for (std::vector<std::string>::iterator num = number_set->second.begin(); num != number_set->second.end(); num++)
    {
        str_b = *num;
        str_b.erase(std::prev(str_b.end(), 1), str_b.end());

        if (str_a == str_b)
        {
            str_b = *num;
            str_b.erase(str_b.begin(), std::prev(str_b.end(), 1));

            current_concatenation += str_b;

            if (num_set != numbers.size() - 1)
            {
                num_set++;

                Problem43_RecursiveLoop(numbers, current_concatenation, num_set, possible_concatenations);

                num_set--;
            }
            else if (!AreCharsRepeated(current_concatenation))
                possible_concatenations.push_back(current_concatenation);

            current_concatenation.erase(std::prev(current_concatenation.end(), 1), current_concatenation.end());
        }
    }
}
