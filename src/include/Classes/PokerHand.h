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
	cPokerHand();
	cPokerHand(std::vector<char> hand);
	~cPokerHand() {}

	void PrintHand();
	void AnalyseHand();

private:
	std::vector<cPlayingCard> m_Cards;
};

#endif