#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(char symbol) : Player("random", symbol) {}

void RandomPlayer::move() {
	int x_rand = rand() % 10;
	int y_rand = rand() % 10;

	Player::move(x_rand, y_rand);
}
