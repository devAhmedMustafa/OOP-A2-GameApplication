#pragma once

#include <vector>

using namespace std;

class Board
{
private:

	vector<int> sizes;
	vector<vector<int>> matrix;

public:

	Board(int size[2]);
	Board(vector<int> sizes);

	void print();
	bool placeSymbol(int x, int y, char symbol);
	virtual char checkForWinner()=0;


};

