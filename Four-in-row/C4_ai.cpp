//
// Created by Ahmed Mustafa on 12/15/2024.
//

#include "C4_ai.h"

#include "C4_Board.h"
#include "../Utils/GameTheory.h"

C4_ai::C4_ai(char symbol, C4_Board& board) : C4_Player(symbol), c4_board(&board) {}

void C4_ai::getmove(int &x, int &y) {
    C4_Board &v_board(*c4_board);

    x = max_move(v_board);
}

int C4_ai::max_move(C4_Board board, int turn, int depth) {

    if (depth >= max_depth || board.is_draw()) return 0;

    int max = -INT_MAX;

    for (int i = 0; i < 7; i++) {


        cout << "i: " << i << " Depth: " << depth << endl;

        if (!board.update_board(i, -1, turn == 1 ? symbol : 'X')) continue;


        if (board.is_win()) {
            return 16 * turn;
        }

        if (const int score = max_move(board, -turn, depth + 1); score > max) {
            max = score;
        }

    }

    return max;
}
