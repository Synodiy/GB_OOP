#ifndef _DECK_H
#define _DECK_H

#include <algorithm>

#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& aHand);

	void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif
