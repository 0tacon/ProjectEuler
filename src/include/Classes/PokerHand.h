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

#ifndef _POKERHAND_
#define _POKERHAND_

#include <cstdint>
#include <cstdio>
#include <vector>

#include "PlayingCard.h"

class cPokerHand
{
public:
	enum eHandType
	{
		HIGHCARD = 0,
		ONEPAIR = 1,
		TWOPAIR = 2,
		THREE_OF_A_KIND = 3,
		STRAIGHT = 4,
		FLUSH = 5,
		FULLHOUSE = 6,
		FOUR_OF_A_KIND = 7,
		STRAIGHT_FLUSH = 8,
		ROYAL_FLUSH = 9,
	};

	cPokerHand();
	cPokerHand(std::vector<char> hand);
	~cPokerHand() {}

	void PrintHand();
	void AnalyseHand();

	bool IsRoyalFlush();
	bool IsStraightFlush();
	bool IsFourOfAKind();
	bool IsFullHouse();
	bool IsFlush();
	bool IsStraight();
	bool IsThreeOfAKind();
	bool IsTwoPair();
	bool IsOnePair();

	void PrintValue(cPlayingCard::eCardValue value);

private:
	std::vector<cPlayingCard> m_Cards;
	eHandType m_HandType;
	std::vector<cPlayingCard::eCardValue> m_HighCards, m_HandValues;
};

#endif