#ifndef _PLAYER_H
#define _PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	virtual ~Player();

	virtual bool IsHitting() const;

	void Win() const;

	void Lose() const;

	void Push() const;
};

#endif
