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
    In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

        1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

    It is possible to make £2 in the following way:

        1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

    How many different ways can £2 be made using any number of coins?
*/

#include <cstdint>
#include <cstdio>
#include <vector>

#ifndef _MAKETOTALFROMSET_
#include "../OtherFunctions/MakeTotalFromSet.h"
#endif // _MAKETOTALFROMSET_

bool Problem31()
{
    std::vector<std::vector<uint64_t> > two_pound;
    std::vector<uint64_t> coins = {1,2,5,10,20,50,100,200};
    uint64_t total = 200;

    two_pound = MakeTotalFromSet(coins, total);

    printf("\nProblem 031: %lu\n", two_pound.size());
    return true;
}
