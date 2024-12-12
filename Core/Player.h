#pragma once

#include <iostream>
#include "Board.h"

using namespace std;

template <typename T>
class Player {
protected:
	string name;
	T symbol;
	Board<T>* boardPtr;  // Pointer to the board
public:
	/// Two constructors to initiate players
	/// Give the player a symbol to use in playing
	/// It can be X, O, or others
	/// Optionally, you can give them a name
	Player(string n, T symbol);
	Player(T symbol); // For computer players

	virtual void getmove(int& x, int& y) = 0;
	T getsymbol();
	string getname();
	void setBoard(Board<T>* b);
};

