#pragma once

#include "Board.h"
#include "Player.h"

class GameManager
{

private:

	Board* board;

	Player* player1;
	Player* player2;

	int currentPlayer;

public:

	GameManager(Board& board);
	void swapPlayers();
	void run();

};

