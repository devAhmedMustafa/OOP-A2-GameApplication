#pragma once

#include "Board.h"
#include "Player.h"
#include "GameState.h"

template <typename T>
class GameManager {
private:
	Board<T>* boardPtr;
	Player<T>* players[2];

	GameState currentState = GameState::PlayerTurn;
	int currentPlayer = 0;
public:
	GameManager(Board<T>*, Player<T>* playerPtr[2]);
	void restartGame();

	void run();
};



