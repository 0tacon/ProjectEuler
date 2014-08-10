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

#include "PlayingCard.h"

cPlayingCard::cPlayingCard()
{
	m_Value = ACE;
	m_Suit = CLUB;
}

cPlayingCard::cPlayingCard(eCardValue value, eCardSuit suit)
{
	m_Value = value;
	m_Suit = suit;
}

cPlayingCard::cPlayingCard(char value, char suit)
{
	ConvertCharactersToCard(value, suit);
}

void cPlayingCard::ConvertCharactersToCard(char value, char suit)
{
	switch (value)
	{
	case '2':
		m_Value = TWO;
		break;
	case '3':
		m_Value = THREE;
		break;
	case '4':
		m_Value = FOUR;
		break;
	case '5':
		m_Value = FIVE;
		break;
	case '6':
		m_Value = SIX;
		break;
	case '7':
		m_Value = SEVEN;
		break;
	case '8':
		m_Value = EIGHT;
		break;
	case '9':
		m_Value = NINE;
		break;
	case 'T':
		m_Value = TEN;
		break;
	case 'J':
		m_Value = JACK;
		break;
	case 'Q':
		m_Value = QUEEN;
		break;
	case 'K':
		m_Value = KING;
		break;
	case 'A':
		m_Value = ACE;
		break;
	default:
		std::printf("\nError: Invalid card value.\n");
	}

	switch (suit)
	{
	case 'C':
		m_Suit = CLUB;
		break;
	case 'D':
		m_Suit = DIAMOND;
		break;
	case 'H':
		m_Suit = HEART;
		break;
	case 'S':
		m_Suit = SPADE;
		break;
	default:
		std::printf("\nError: Invalid card suit.\n");
	}
}

void cPlayingCard::PrintCard()
{
	switch (m_Value)
	{
	case TEN:
		std::printf("T");
		break;
	case JACK:
		std::printf("J");
		break;
	case QUEEN:
		std::printf("Q");
		break;
	case KING:
		std::printf("K");
		break;
	case ACE:
		std::printf("A");
		break;
	default:
		std::printf("%c", m_Value + '0');
	}

	std::printf("%c", m_Suit);
}