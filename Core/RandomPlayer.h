#pragma once

#include "Player.h"

class RandomPlayer : private Player
{

public:

	RandomPlayer(char symbol);
	void move();

};

