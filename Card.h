#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card
{
public:
	enum rank
	{
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit
	{
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	int GetValue() const;
	void Flip();
	friend ostream& operator<<(ostream& os, const Card& aCard);

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

#endif
