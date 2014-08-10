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

#ifndef _PLAYINGCARD_
#define _PLAYINGCARD_

#include <cstdint>
#include <cstdio>

class cPlayingCard
{
public:
	enum eCardSuit
	{
		CLUB = 'C',
		DIAMOND = 'D',
		HEART = 'H',
		SPADE = 'S',
	};

	enum eCardValue
	{
		ACE_LOW = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 11,
		QUEEN = 12,
		KING = 13,
		ACE = 14,
	};

	cPlayingCard(eCardValue value, eCardSuit suit);
	cPlayingCard(char value, char suit);
	cPlayingCard();
	~cPlayingCard() {}

	void SetValue(eCardValue value) { m_Value = value; }
	void SetSuit(eCardSuit suit) { m_Suit = suit; }

	eCardValue GetValue() { return m_Value; }
	eCardSuit GetSuit() { return m_Suit; }

	void PrintCard();

	void ConvertCharactersToCard(char value, char suit);

private:
	eCardValue m_Value;
	eCardSuit m_Suit;
};

#endif