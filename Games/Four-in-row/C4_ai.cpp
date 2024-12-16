//
// Created by Ahmed Mustafa on 12/15/2024.
//

#include "C4_ai.h"

#include "C4_Board.h"
#include "../Utils/GameTheory.h"

C4_ai::C4_ai(char symbol, C4_Board& board) : C4_Player(symbol), c4_board(&board) {}

void C4_ai::getmove(int &x, int &y) {
    C4_Board &v_board(*c4_board);

    auto move = max_move(v_board);
    x = move.second;
    cout << move.first << endl;
}

pair<int, int> C4_ai::max_move(C4_Board board, int c_score, int turn, int depth) {

    int max = -INT_MAX;
    int maxIdx = 0;

    for (int i = 0; i < 7; i++) {

        if (!board.update_board(i, -1, turn == 1 ? symbol : 'X')) continue;

        if (depth >= max_depth || board.is_draw()) return {0, i};
        if (board.is_win())
            return {16 * turn * (max_depth - depth), i};

        const int score = max_move(board, score, -turn, depth + 1).first;
        if (score > max) {
            max = score;
            maxIdx = i;
        }

    }

    return {max, maxIdx};
}
