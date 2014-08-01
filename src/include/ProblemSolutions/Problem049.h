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
#include <utility>
#include <algorithm>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif // _GETALLPRIMESBELOW_

bool Problem49()
{
    std::vector<uint32_t> primes = GetAllPrimesBelow(10000);
    std::map<std::string, bool> str_primes;
    std::map<uint16_t, std::vector<uint32_t> > sequences;

    for (std::vector<uint32_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
        if (*prime > 999)
            str_primes[std::to_string(*prime)] = false;

    uint16_t sequences_counter = 0;
    for (std::map<std::string, bool>::iterator prime = str_primes.begin(); prime != str_primes.end(); prime++)
    {
        if (str_primes[prime->first] == false)
        {
            sequences[sequences_counter].push_back(std::stoi(prime->first));
            str_primes[prime->first] = true;

            for (std::map<std::string, bool>::iterator other_prime = std::next(prime, 1); other_prime != str_primes.end(); other_prime++)
            {
                if (std::is_permutation(prime->first.begin(), prime->first.end(), other_prime->first.begin()))
                {
                    sequences[sequences_counter].push_back(std::stoi(other_prime->first));
                    str_primes[other_prime->first] = true;
                }
            }

            sequences_counter++;
        }
    }

    uint16_t filtered_sequences_counter = 0;
    std::map<uint16_t, std::vector<uint32_t> > filtered_sequences;
    for (std::map<uint16_t, std::vector<uint32_t> >::iterator seq = sequences.begin(); seq != sequences.end(); seq++)
    {
        if (seq->second.size() > 2)
        {
            std::vector<uint32_t> seq_differences;
            std::vector<std::pair<uint32_t, uint32_t> > filtered_sequence;
            uint16_t filtered_sequence_counter;

            uint8_t forward_shift = 0;
            for (; forward_shift < seq->second.size() - 2; forward_shift++)
            {
                filtered_sequence_counter = 1 + forward_shift;

                std::vector<uint32_t>::iterator other_num = std::next(seq->second.begin(), forward_shift);

                for (std::vector<uint32_t>::iterator num = std::next(other_num, 1); num != seq->second.end(); num++)
                    seq_differences.push_back(*num - *other_num);

                for (std::vector<uint32_t>::iterator diff = seq_differences.begin(); diff != seq_differences.end(); diff++)
                {
                    uint8_t number_multiples = 1;
                    filtered_sequence.push_back(std::make_pair(filtered_sequence_counter, *diff));
                    filtered_sequence_counter++;

                    for (std::vector<uint32_t>::iterator other_diff = std::next(diff, 1); other_diff != seq_differences.end(); other_diff++)
                    {
                        if (*other_diff%*diff == 0)
                        {
                            number_multiples++;

                            if (*other_diff == *diff * number_multiples)
                            {
                                filtered_sequence.push_back(std::make_pair(filtered_sequence_counter, *diff));
                                filtered_sequence_counter++;
                            }
                        }
                    }

                    if (number_multiples > 1 && filtered_sequence.size() == number_multiples)
                        break;

                    filtered_sequence.clear();
                }

                if (filtered_sequence.size() == 0)
                    seq_differences.clear();
                else
                    break;
            }

            if (filtered_sequence.size() > 0)
            {
                filtered_sequences[filtered_sequences_counter].push_back(seq->second[forward_shift]);

                for (std::vector<std::pair<uint32_t, uint32_t> >::iterator filtered_seq_num = filtered_sequence.begin(); filtered_seq_num != filtered_sequence.end(); filtered_seq_num++)
                    filtered_sequences[filtered_sequences_counter].push_back(seq->second[filtered_seq_num->first]);

                filtered_sequences_counter++;
            }
        }
    }

    std::string final_answer = "";
    for (std::map<uint16_t, std::vector<uint32_t> >::iterator itr = filtered_sequences.begin(); itr != filtered_sequences.end(); itr++)
        if (itr->second[0] != 1487)
            for (std::vector<uint32_t>::iterator num = itr->second.begin(); num != itr->second.end(); num++)
                final_answer += std::to_string(*num);

    std::printf("\nProblem 049: %s\n", final_answer.c_str());
    return true;
}
