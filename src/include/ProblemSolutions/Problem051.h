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
	By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

	By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

	Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/

#include <cstdio>
#include <cstdint>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
#include <string>

#ifndef _GETALLPRIMESBELOW_
#include "../OtherFunctions/GetAllPrimesBelow.h"
#endif //_GETALLPRIMESBELOW_

bool Problem51()
{
	std::vector<uint32_t> primes = GetAllPrimesBelow(57000);
	std::map<uint32_t, std::map<uint8_t, std::vector<uint8_t> > > digit_breakdowns;

	for (std::vector<uint32_t>::iterator prime = primes.begin(); prime != primes.end(); prime++)
		if (*prime > 56000)
		{
			std::string str_prime = std::to_string(*prime);
			std::map<uint8_t, std::vector<uint8_t> > digit_positions;

			for (std::string::iterator letter = str_prime.begin(); letter != str_prime.end(); letter++)
				digit_positions[*letter - '0'].push_back(std::distance(str_prime.begin(), letter));

			digit_breakdowns[*prime] = digit_positions;
		}

	/*for (std::map<uint32_t, std::map<uint8_t, std::vector<uint8_t> > >::iterator digit_breakdown = digit_breakdowns.begin(); digit_breakdown != digit_breakdowns.end(); digit_breakdown++)
	{
		std::printf("\nPrime = %d", digit_breakdown->first);

		for (std::map<uint8_t, std::vector<uint8_t> >::iterator digit_position = digit_breakdown->second.begin(); digit_position != digit_breakdown->second.end(); digit_position++)
		{
			std::printf("\n\tDigit = %d : Positions = ", digit_position->first);
				
			for (std::vector<uint8_t>::iterator position = digit_position->second.begin(); position != digit_position->second.end(); position++)
				std::printf("%d, ", *position);
		}
			
		std::printf("\n");
	}*/

	std::vector<std::vector<uint32_t> > prime_families;
	for (std::map<uint32_t, std::map<uint8_t, std::vector<uint8_t> > >::iterator digit_breakdown = digit_breakdowns.begin(); digit_breakdown != digit_breakdowns.end(); digit_breakdown++)
		for (std::map<uint8_t, std::vector<uint8_t> >::iterator digit_positions = digit_breakdown->second.begin(); digit_positions != digit_breakdown->second.end(); digit_positions++)
			if (digit_positions->second.size() > 1)
			{
				std::vector<uint32_t> prime_family;

				std::string prime = std::to_string(digit_breakdown->first);

				for (std::vector<uint8_t>::iterator position = digit_positions->second.begin(); position != digit_positions->second.end(); position++)
					prime[*position] = 'A';

				prime.erase(std::remove(prime.begin(), prime.end(), 'A'), prime.end());

				prime_family.push_back(digit_breakdown->first);

				for (std::map<uint32_t, std::map<uint8_t, std::vector<uint8_t> > >::iterator other_digit_breakdown = std::next(digit_breakdown, 1); other_digit_breakdown != digit_breakdowns.end(); other_digit_breakdown++)
				{
					std::string other_prime = std::to_string(other_digit_breakdown->first);

					char comparison_letter = other_prime[digit_positions->second[0]];
					bool comparison_successful = true;

					for (std::vector<uint8_t>::iterator position = digit_positions->second.begin(); position != digit_positions->second.end(); position++)
						if (other_prime[*position] != comparison_letter)
							comparison_successful = false;
					
					if (comparison_successful)
					{
						for (std::vector<uint8_t>::iterator position = digit_positions->second.begin(); position != digit_positions->second.end(); position++)
							other_prime[*position] = 'A';

						other_prime.erase(std::remove(other_prime.begin(), other_prime.end(), 'A'), other_prime.end());

						if (prime == other_prime)
							prime_family.push_back(other_digit_breakdown->first);
					}
				}

				if (prime_family.size() > 6)
					prime_families.push_back(prime_family);
			}

	for (std::vector<std::vector<uint32_t> >::iterator prime_family = prime_families.begin(); prime_family != prime_families.end(); prime_family++)
	{
		std::printf("\n");
		for (std::vector<uint32_t>::iterator prime = prime_family->begin(); prime != prime_family->end(); prime++)
			std::printf("%d, ", *prime);
		std::printf("\n");
	}

	std::printf("\nProblem 051: \n");
	return true;
}