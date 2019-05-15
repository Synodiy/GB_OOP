#ifndef _HOUSE_H
#define _HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const string& name = "House");

	virtual ~House();

	virtual bool IsHitting() const;

	void FlipFirstCard();
};

#endif
