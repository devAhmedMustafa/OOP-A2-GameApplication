#pragma once

#include "Board.h"
#include "Player.h"

template <typename T>
class GameManager {
private:
	Board<T>* boardPtr;
	Player<T>* players[2];
public:
	GameManager(Board<T>*, Player<T>* playerPtr[2]);

	void run();
};

