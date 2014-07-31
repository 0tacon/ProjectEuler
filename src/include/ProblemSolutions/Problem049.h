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
    The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

    There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

    What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem49()
{
    std::string full_str = "123456789", trunc_str;
    std::vector<std::string> permutations, str_primes;
    std::vector<uint32_t> primes = GetAllPrimesBelow(10000);

    for (std::vector<uint32_t>::iterator itr = primes.begin(); itr != primes.end(); itr++)
        str_primes.push_back(std::to_string(*itr));

    trunc_str = full_str;
    trunc_str.erase(std::prev(trunc_str.end(), 5), trunc_str.end());

    std::next_permutation(full_str.begin(), full_str.end());

    while(full_str != "123456789")
    {
        trunc_str = full_str;
        trunc_str.erase(std::prev(trunc_str.end(), 5), trunc_str.end());

        if (std::count(permutations.begin(), permutations.end(), trunc_str) == 0 && std::count(str_primes.begin(), str_primes.end(), trunc_str) == 1)
            permutations.push_back(trunc_str);

        std::next_permutation(full_str.begin(), full_str.end());
    }

    std::map<std::string, bool > map_perms;
    for (std::vector<std::string>::iterator a = permutations.begin(); a != permutations.end(); a++)
        map_perms[*a] = false;

    std::map<uint16_t, std::vector<uint16_t> > perm_sequences;

    uint16_t counter = 0;
    for (std::vector<std::string>::iterator a = permutations.begin(); a != permutations.end(); a++)
    {
        if (map_perms[*a] != true)
        {
            map_perms[*a] = true;
            perm_sequences[counter].push_back(std::stoi(*a));

            for (std::vector<std::string>::iterator b = std::next(a, 1); b != permutations.end(); b++)
                if (map_perms[*b] != true && *a != *b && std::is_permutation(a->begin(), a->end(), b->begin()))
                {
                    map_perms[*b] = true;
                    perm_sequences[counter].push_back(std::stoi(*b));
                }
        }

        counter++;
    }

    for (std::map<uint16_t, std::vector<uint16_t> >::iterator itr = perm_sequences.begin(); itr != perm_sequences.end(); itr++)
    {
        printf("\n");
        for (std::vector<uint16_t>::iterator num = itr->second.begin(); num != itr->second.end(); num++)
            printf("%d, ", *num);
    }

    std::printf("\nProblem 049: \n");
    return true;
}
