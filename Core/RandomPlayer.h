#pragma once

#include "Player.h"

/// This class represents a random computer player
/// that generates random positions x, y
/// If invalid, the game manager asks to regenerate
template <typename T>
class RandomPlayer : public Player<T> {
protected:
	int dimension;
public:
	// Take a symbol and pass it to the parent
	RandomPlayer(T symbol);
	// Generate a random move
	virtual void getmove(int& x, int& y) = 0;
};

template <typename T>
class GameManager {
private:
	Board<T>* boardPtr;
	Player<T>* players[2];
public:
	GameManager(Board<T>*, Player<T>* playerPtr[2]);

	void run();
};

