#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Board
{
private:

	vector<int> sizes;
	vector<vector<int>> matrix;

    char symbols[2];

public:

	Board(int size[2]);
	Board(vector<int> sizes);

	void print();
	bool isOver();
    char* getSymbols();
	bool placeSymbol(int x, int y, char symbol);
	virtual char checkForWinner()=0;


};

