#include "Player.h"


Player::Player(string name, char symbol) : name(name), symbol(symbol) {}

void Player::move(int x, int y) {
	pos[0] += x;
	pos[1] += y;
}

char Player::getSymbol() {
	return symbol;
}