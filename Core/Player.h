#pragma once

#include <iostream>

using namespace std;

class Player
{

private:

	string name;
	char symbol;

	int pos[2];

public:

	Player(string, char);

	void move(int x, int y);
	char getSymbol();

};

