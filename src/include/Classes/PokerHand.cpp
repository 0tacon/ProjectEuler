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
		std::printf("Four of a Kind - ");
		PrintValue(m_HandValues[0]);
		std::printf("\n");
		break;
	case FULLHOUSE:
		std::printf("Full House - ");
		PrintValue(m_HandValues[0]);
		std::printf(", ");
		PrintValue(m_HandValues[1]);
		std::printf("\n");
		break;
	case FLUSH:
		std::printf("Flush\n");
		break;
	case STRAIGHT:
		std::printf("Straight\n");
		break;
	case THREE_OF_A_KIND:
		std::printf("Three of a Kind - ");
		PrintValue(m_HandValues[0]);
		std::printf("\n");
		break;
	case TWOPAIR:
		std::printf("Two Pair - ");
		PrintValue(m_HandValues[0]);
		std::printf(", ");
		PrintValue(m_HandValues[1]);
		std::printf("\n");
		break;
	case ONEPAIR:
		std::printf("One Pair - ");
		PrintValue(m_HandValues[0]);
		std::printf("\n");
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
	{
		m_HandType = HIGHCARD;

		m_HighCards.clear();
		for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
			m_HighCards.push_back(high_card->GetValue());
		std::sort(m_HighCards.begin(), m_HighCards.end());
		std::reverse(m_HighCards.begin(), m_HighCards.end());

		m_HandValues.clear();
	}
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
			{
				m_HighCards.clear();
				for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
					m_HighCards.push_back(high_card->GetValue());
				std::sort(m_HighCards.begin(), m_HighCards.end());
				std::reverse(m_HighCards.begin(), m_HighCards.end());

				m_HandValues.clear();

				return true;
			}
		}
	}

	return false;
}

bool cPokerHand::IsStraightFlush()
{
	if (IsStraight() && IsFlush())
	{
		m_HighCards.clear();
		for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
			m_HighCards.push_back(high_card->GetValue());
		std::sort(m_HighCards.begin(), m_HighCards.end());
		std::reverse(m_HighCards.begin(), m_HighCards.end());

		m_HandValues.clear();

		return true;
	}

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
		{
			m_HighCards.clear();
			for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
				if (high_card->GetValue() != card->GetValue())
					m_HighCards.push_back(high_card->GetValue());
			std::sort(m_HighCards.begin(), m_HighCards.end());
			std::reverse(m_HighCards.begin(), m_HighCards.end());

			m_HandValues.clear();
			m_HandValues.push_back(card->GetValue());

			return true;
		}
	}

	return false;
}

bool cPokerHand::IsFullHouse()
{
	if (IsThreeOfAKind() && IsOnePair())
	{
		m_HandValues.clear();

		m_HighCards.clear();
		for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
			m_HighCards.push_back(high_card->GetValue());

		for (uint8_t card_value = 0; card_value < m_HighCards.size(); card_value++)
			if (std::count(m_HighCards.begin(), m_HighCards.end(), m_HighCards[card_value]) == 3)
			{
				m_HandValues.push_back(m_HighCards[card_value]);
				break;
			}

		for (uint8_t card_value = 0; card_value < m_HighCards.size(); card_value++)
			if (std::count(m_HighCards.begin(), m_HighCards.end(), m_HighCards[card_value]) == 2)
			{
				m_HandValues.push_back(m_HighCards[card_value]);
				break;
			}

		m_HighCards.clear();

		std::sort(m_HandValues.begin(), m_HandValues.end());
		std::reverse(m_HandValues.begin(), m_HandValues.end());

		return true;
	}

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

	m_HighCards.clear();
	for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
		m_HighCards.push_back(high_card->GetValue());
	std::sort(m_HighCards.begin(), m_HighCards.end());
	std::reverse(m_HighCards.begin(), m_HighCards.end());

	m_HandValues.clear();

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
			return false;
	}

	m_HighCards.clear();
	for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
		m_HighCards.push_back(high_card->GetValue());
	std::sort(m_HighCards.begin(), m_HighCards.end());
	std::reverse(m_HighCards.begin(), m_HighCards.end());

	m_HandValues.clear();

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
			m_HighCards.clear();
			for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
				if (high_card->GetValue() != card->GetValue())
					m_HighCards.push_back(high_card->GetValue());
			std::sort(m_HighCards.begin(), m_HighCards.end());
			std::reverse(m_HighCards.begin(), m_HighCards.end());

			m_HandValues.clear();
			m_HandValues.push_back(card->GetValue());

			return true;
		}
	}

	return false;
}

bool cPokerHand::IsTwoPair()
{
	uint8_t num_pairs = 0;

	m_HandValues.clear();

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
		{
			m_HandValues.push_back(card->GetValue());

			num_pairs++;
		}
		if (num_pairs == 2)
		{
			m_HighCards.clear();
			for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
				if (std::count(m_HandValues.begin(), m_HandValues.end(), high_card->GetValue()) == 0)
					m_HighCards.push_back(high_card->GetValue());
			std::sort(m_HighCards.begin(), m_HighCards.end());
			std::reverse(m_HighCards.begin(), m_HighCards.end());

			std::sort(m_HandValues.begin(), m_HandValues.end());
			std::reverse(m_HandValues.begin(), m_HandValues.end());

			return true;
		}
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
		{
			m_HandValues.clear();
			m_HandValues.push_back(card->GetValue());

			m_HighCards.clear();
			for (std::vector<cPlayingCard>::iterator high_card = m_Cards.begin(); high_card != m_Cards.end(); high_card++)
				if (std::count(m_HandValues.begin(), m_HandValues.end(), high_card->GetValue()) == 0)
					m_HighCards.push_back(high_card->GetValue());
			std::sort(m_HighCards.begin(), m_HighCards.end());
			std::reverse(m_HighCards.begin(), m_HighCards.end());

			return true;
		}
	}

	return false;
}

void cPokerHand::PrintValue(cPlayingCard::eCardValue value)
{
	switch (value)
	{
	case cPlayingCard::TEN:
		std::printf("T");
		break;
	case cPlayingCard::JACK:
		std::printf("J");
		break;
	case cPlayingCard::QUEEN:
		std::printf("Q");
		break;
	case cPlayingCard::KING:
		std::printf("K");
		break;
	case cPlayingCard::ACE:
		std::printf("A");
		break;
	default:
		std::printf("%d", value);
	}
}