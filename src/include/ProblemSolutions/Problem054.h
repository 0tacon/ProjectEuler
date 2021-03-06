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
	In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

		High Card: Highest value card.
		One Pair: Two cards of the same value.
		Two Pairs: Two different pairs.
		Three of a Kind: Three cards of the same value.
		Straight: All cards are consecutive values.
		Flush: All cards of the same suit.
		Full House: Three of a kind and a pair.
		Four of a Kind: Four cards of the same value.
		Straight Flush: All cards are consecutive values of same suit.
		Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

	The cards are valued in the order:
	2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

	If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

	Consider the following five hands dealt to two players:

	Hand	Player 1	 		Player 2	 			Winner

	1	 	5H 5C 6S 7S KD		2C 3S 8S 8D TD			Player 2
			Pair of Fives		Pair of Eights
	 			
	2	 	5D 8C 9S JS AC		2C 5C 7D 8S QH			Player 1
			Highest card Ace	Highest card Queen
	 		
	3	 	2D 9C AS AH AC		3D 6D 7D TD QD			Player 2
			Three Aces			Flush with Diamonds
		
	4	 	4D 6S 9H QH QC		3D 6D 7H QD QS			Player 1
			Pair of Queens		Pair of Queens
			Highest card Nine	Highest card Seven

	5	 	2H 2D 4C 4D 4S		3C 3D 3S 9S 9D			Player 1
			Full House			Full House
			With Three Fours	with Three Threes

	The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

	How many hands does Player 1 win?
*/

#include <cstdio>
#include <cstdint>
#include <vector>
#include <string>

#ifndef _READFILEINTOVECT_
#include "../OtherFunctions/ReadFileIntoVect.h"
#endif //_READFILEINTOVECT_

#include "../Classes/PokerHand.h"

bool Problem54()
{
	uint16_t p1_wins = 0;
	std::vector<char> vect;
	std::string filepath = "../../data/poker.txt";
	ReadFileIntoVect(vect, filepath);

	vect.erase(std::remove(vect.begin(), vect.end(), ' '), vect.end());
	vect.erase(std::remove(vect.begin(), vect.end(), '\n'), vect.end());

	std::vector<std::vector<char> > poker_hands;
	for (uint16_t i = 0; i < vect.size(); i += 10)
	{
		std::vector<char> poker_hand;
		
		for (uint8_t n = 0; n < 10; n++)
			poker_hand.push_back(vect[i + n]);

		poker_hands.push_back(poker_hand);
	}

	for (std::vector<std::vector<char> >::iterator poker_hand = poker_hands.begin(); poker_hand != poker_hands.end(); poker_hand+=2)
	{
		cPokerHand hand(*poker_hand);
		cPokerHand other_hand(*(poker_hand+1));
		
		if (!(hand == other_hand) && hand > other_hand)
			p1_wins++;
	}

	std::printf("\nProblem 054: %d\n", p1_wins);
	return true;
}
