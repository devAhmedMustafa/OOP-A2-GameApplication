#include "Player.h"


using namespace std;
// Constructor for Player with a name and symbol
template <typename T>
Player<T>::Player(std::string n, T symbol) {
	this->name = n;
	this->symbol = symbol;
}

// Constructor for Player with only a symbol (e.g., for computer players)
template <typename T>
Player<T>::Player(T symbol) {
	this->name = "Computer";
	this->symbol = symbol;
}

// Getter for player's name
template <typename T>
std::string Player<T>::getname() {
	return this->name;
}

// Getter for player's symbol
template <typename T>
T Player<T>::getsymbol() {
	return this->symbol;
}

// Method to set the board pointer in the Player class
template <typename T>
void Player<T>::setBoard(Board<T>* b) {
	this->boardPtr = b;
}

template class Player<int>;
template class Player<char>;
