#include "Board.h"

using namespace std;

Board::Board(int size[2]) {
	for (int i = 0; i < size[1]; i++) {
		this->sizes.push_back(size[0]);
	}
}

Board::Board(vector<int> sizes) {
	this->sizes = sizes;
}

void Board::print() {
	for (int i = 0; i < this->sizes[1]; i++) {
		for (int j = 0; j < this->sizes[0]; j++) {
			cout << this->matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool Board::isOver() {

	for (int i = 0; i < this->sizes[1]; i++) {
		for (int j = 0; j < this->sizes[0]; j++) {
			if (this->matrix[i][j] == 0) {
				return true;
			}
		}
	}

	return false;

}
