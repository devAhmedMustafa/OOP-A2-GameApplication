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

}