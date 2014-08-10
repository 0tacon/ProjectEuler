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
#include <vector>

#include "PokerHand.h"

cPokerHand::cPokerHand()
{
	for (uint8_t i = 0; i < 5; i++)
		m_Cards.push_back(cPlayingCard());
}

cPokerHand::cPokerHand(std::vector<char> hand)
{
	if (hand.size() == 10)
	{
		for (uint8_t i = 0; i < 9; i+=2)
			m_Cards.push_back(cPlayingCard(hand[i], hand[i+1]));
	}
	else
	{
		for (uint8_t i = 0; i < 5; i++)
			m_Cards.push_back(cPlayingCard());

		std::printf("\nError: Invalid card count, a hand requires exactly 5 cards.\n");
	}
}

void cPokerHand::PrintHand()
{
	std::printf("\n");
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
	{
		card->PrintCard();
		std::printf(" ");
	}
	std::printf("\n");
}

void cPokerHand::AnalyseHand()
{
	//Do all cards have the same suit?
		//If so are they in consecutive order?
			//If so are they from ten to ace?
				//If so then Royal Flush
			//If not then Straight Flush
		//If not then flush

	//Four of a kind?
	
	//Three of a Kind?
		//If so, are the two remaining cards a pair?
			//If so then Full House
		//If not then Three of a Kind

	//Straight?

	//Is there a pair?
		//If so is there another pair?
			//If so then Two Pair
		//If not then One Pair

	//Arrange cards from highest to lowest
}