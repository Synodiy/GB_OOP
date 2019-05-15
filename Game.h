#ifndef _GAME_H
#define _GAME_H

#include <ctime>

#include "Player.h"
#include "House.h"
#include "Deck.h"

class Game
{
public:
	Game(const vector<string>& names);

	~Game();

	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};
#endif
