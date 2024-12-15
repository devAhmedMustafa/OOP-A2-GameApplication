//
// Created by Ahmed Mustafa on 12/15/2024.
//

#include "C4_ai.h"

#include "C4_Board.h"
#include "../Utils/GameTheory.h"

C4_ai::C4_ai(char symbol, C4_Board& board) : C4_Player(symbol), c4_board(&board) {}

void C4_ai::getmove(int &x, int &y) {

    C4_Board v_board(*c4_board);

    map<char, int> mapping = {{'X', 1}, {'O', -1}};

    x = max_move(v_board, 1);
}

int C4_ai::max_move(C4_Board board, int turn) {

    int max = -INFINITY;

    map<char, int> mapping = {{symbol, 1}, {'P', -1}};
    // auto normalized_board = GameTheory::normalizeBoard(board.board, 6, 7, mapping);


    for (int i = 0; i < 7; i++) {

        if (!board.update_board(i, -1, turn? symbol : 'P')) continue;

        if (board.is_win()) {
            return 16 * turn;
        }

        int score = max_move(board, -turn);
        if (score > max) {
            max = score;
        }

    }

    return max;
}