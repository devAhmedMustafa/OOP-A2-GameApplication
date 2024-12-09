#include <iostream>

#include "Four-in-row/Board_Four_In_Row.h"

using namespace std;
int main() {

    Board_Four_In_Row board;

    board.place(1, 'X');
    board.place(2, 'O');
    board.place(3, 'X');
    board.place(4, 'O');
    board.place(4, 'X');
    board.place(4, 'O');
    board.place(3, 'X');

    cout << board.is_win() << endl;
    board.display_board();

    return 0;
}
