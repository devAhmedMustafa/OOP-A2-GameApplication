#pragma once

#include <string>
#include <vector>
using namespace std;

template <typename T>
class Board {
protected:
	int rows, columns;
	T** board;
	int n_moves = 0;

public:


	/// Return true if move is valid and put it on the board
	/// within board boundaries in an empty cell
	/// Return false otherwise
	virtual bool update_board(int x, int y, T symbol) = 0;

	/// Display the board and the pieces on it
	virtual void display_board() = 0;

	/// Returns true if there is any winner
	virtual bool is_win() = 0;

	/// Return true if all moves are done and no winner
	virtual bool is_draw() = 0;

	/// Return true if the game is over
	virtual bool game_is_over() = 0;
};
