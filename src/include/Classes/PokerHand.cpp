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
#include <algorithm>

#include "PokerHand.h"

cPokerHand::cPokerHand()
{
	m_Cards.push_back(cPlayingCard('2','C'));
	m_Cards.push_back(cPlayingCard('3', 'D'));
	m_Cards.push_back(cPlayingCard('4', 'H'));
	m_Cards.push_back(cPlayingCard('5', 'S'));
	m_Cards.push_back(cPlayingCard('7', 'C'));

	AnalyseHand();

	m_HighCards.clear();
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
		m_HighCards.push_back(card->GetValue());

	std::sort(m_HighCards.begin(), m_HighCards.end());
	std::reverse(m_HighCards.begin(), m_HighCards.end());
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
		m_Cards.push_back(cPlayingCard('2', 'C'));
		m_Cards.push_back(cPlayingCard('3', 'D'));
		m_Cards.push_back(cPlayingCard('4', 'H'));
		m_Cards.push_back(cPlayingCard('5', 'S'));
		m_Cards.push_back(cPlayingCard('7', 'C'));

		std::printf("\nError: Invalid card count, a hand requires exactly 5 cards, setting to default hand.\n");
	}

	AnalyseHand();

	m_HighCards.clear();
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
		m_HighCards.push_back(card->GetValue());

	std::sort(m_HighCards.begin(), m_HighCards.end());
	std::reverse(m_HighCards.begin(), m_HighCards.end());
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

	switch (m_HandType)
	{
	case ROYAL_FLUSH:
		std::printf("Royal Flush\n");
		break;
	case STRAIGHT_FLUSH:
		std::printf("Straight Flush\n");
		break;
	case FOUR_OF_A_KIND:
		std::printf("Four of a Kind\n");
		break;
	case FULLHOUSE:
		std::printf("Full House\n");
		break;
	case FLUSH:
		std::printf("Flush\n");
		break;
	case STRAIGHT:
		std::printf("Straight\n");
		break;
	case THREE_OF_A_KIND:
		std::printf("Three of a Kind\n");
		break;
	case TWOPAIR:
		std::printf("Two Pair\n");
		break;
	case ONEPAIR:
		std::printf("One Pair\n");
		break;
	case HIGHCARD:
		std::printf("High Card\n");
		break;
	}

	for (std::vector<cPlayingCard::eCardValue>::iterator high_card = m_HighCards.begin(); high_card != m_HighCards.end(); high_card++)
		std::printf("%d ", *high_card);
	std::printf("\n");
}

void cPokerHand::AnalyseHand()
{
	if (IsRoyalFlush())
		m_HandType = ROYAL_FLUSH;
	else if (IsStraightFlush())
		m_HandType = STRAIGHT_FLUSH;
	else if (IsFourOfAKind())
		m_HandType = FOUR_OF_A_KIND;
	else if (IsFullHouse())
		m_HandType = FULLHOUSE;
	else if (IsFlush())
		m_HandType = FLUSH;
	else if (IsStraight())
		m_HandType = STRAIGHT;
	else if (IsThreeOfAKind())
		m_HandType = THREE_OF_A_KIND;
	else if (IsTwoPair())
		m_HandType = TWOPAIR;
	else if (IsOnePair())
		m_HandType = ONEPAIR;
	else
		m_HandType = HIGHCARD;
}

bool cPokerHand::IsRoyalFlush()
{
	bool ace_present = false, king_present = false;
	if (IsStraightFlush())
	{
		for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
		{
			if (card->GetValue() == cPlayingCard::KING)
				king_present = true;

			if (card->GetValue() == cPlayingCard::ACE)
				ace_present = true;

			if (king_present && ace_present)
				return true;
		}
	}

	return false;
}

bool cPokerHand::IsStraightFlush()
{
	if (IsStraight() && IsFlush())
		return true;

	return false;
}

bool cPokerHand::IsFourOfAKind()
{
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
	{
		uint8_t repeats = 0;

		for (std::vector<cPlayingCard>::iterator other_card = m_Cards.begin(); other_card != m_Cards.end(); other_card++)
		{
			if (card != other_card)
			{
				if (card->GetValue() == other_card->GetValue())
					repeats++;
			}
		}

		if (repeats == 3)
			return true;
	}

	return false;
}

bool cPokerHand::IsFullHouse()
{
	if (IsThreeOfAKind() && IsOnePair())
		return true;

	return false;
}

bool cPokerHand::IsFlush()
{
	for (std::vector<cPlayingCard>::iterator other_card = std::next(m_Cards.begin(), 1); other_card != m_Cards.end(); other_card++)
	{
		std::vector<cPlayingCard>::iterator card = m_Cards.begin();
		if (card->GetSuit() != other_card->GetSuit())
			return false;
	}

	return true;
}

bool cPokerHand::IsStraight()
{
	//Are they in consecutive order?
	std::vector<cPlayingCard::eCardValue> values;
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
		values.push_back(card->GetValue());

	//If there is an Ace in the hand, search for a King or a Two
	bool ace_present = false;

	for (std::vector<cPlayingCard::eCardValue>::iterator value = values.begin(); value != values.end(); value++)
	{
		if (*value == cPlayingCard::ACE)
		{
			ace_present = true;
			break;
		}
	}

	bool king_present = false, two_present = false;
	if (ace_present)
	{
		for (std::vector<cPlayingCard::eCardValue>::iterator value = values.begin(); value != values.end(); value++)
		{
			if (*value == cPlayingCard::KING)
				king_present = true;
			else if (*value == cPlayingCard::TWO)
				two_present = true;

			if (king_present && two_present)
				break;
		}
	}

	//If there are aces in hand and both a king and a two, then there cannot be a straight
	if (ace_present && king_present && two_present)
		return false;
	//Otherwise if there are aces in hand with a two, then make the aces low
	else if (ace_present && two_present)
	{
		for (uint8_t i = 0; i < values.size(); i++)
		{
			if (values[i] == cPlayingCard::ACE)
				values[i] = cPlayingCard::ACE_LOW;
		}
	}
	//If there's no ace, or an ace and a king only, then leave aces high and proceed as usual

	std::sort(values.begin(), values.end());

	//If there's still a chance that it's a straight then determine whether it is or not
	for (std::vector<cPlayingCard::eCardValue>::iterator value = std::next(values.begin(), 1); value != values.end(); value++)
	{
		std::vector<cPlayingCard::eCardValue>::iterator prev_value = std::prev(value, 1);

		if (*value != *prev_value + 1)
		{
			return false;
		}
	}

	return true;
}

bool cPokerHand::IsThreeOfAKind()
{
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
	{
		uint8_t repeats = 0;

		for (std::vector<cPlayingCard>::iterator other_card = m_Cards.begin(); other_card != m_Cards.end(); other_card++)
		{
			if (card != other_card)
			{
				if (card->GetValue() == other_card->GetValue())
					repeats++;
			}
		}

		if (repeats == 2)
		{
			return true;
		}
	}

	return false;
}

bool cPokerHand::IsTwoPair()
{
	uint8_t num_pairs = 0;

	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
	{
		uint8_t repeats = 0;

		for (std::vector<cPlayingCard>::iterator other_card = std::next(card, 1); other_card != m_Cards.end(); other_card++)
		{
			if (card != other_card)
			{
				if (card->GetValue() == other_card->GetValue())
					repeats++;
			}
		}

		if (repeats == 1)
			num_pairs++;
		if (num_pairs == 2)
			return true;
	}

	return false;
}

bool cPokerHand::IsOnePair()
{
	for (std::vector<cPlayingCard>::iterator card = m_Cards.begin(); card != m_Cards.end(); card++)
	{
		uint8_t repeats = 0;

		for (std::vector<cPlayingCard>::iterator other_card = m_Cards.begin(); other_card != m_Cards.end(); other_card++)
		{
			if (card != other_card)
			{
				if (card->GetValue() == other_card->GetValue())
					repeats++;
			}
		}

		if (repeats == 1)
			return true;
	}

	return false;
}