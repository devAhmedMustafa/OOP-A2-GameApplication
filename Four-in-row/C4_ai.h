//
// Created by Ahmed Mustafa on 12/15/2024.
//

#ifndef C4_AI_H
#define C4_AI_H
#include "C4_Board.h"
#include "C4_Player.h"
#include "../Core/Player.h"


class C4_ai : public C4_Player {

    C4_Board* c4_board;
    const int max_depth = 3;

public:
    C4_ai(char symbol, C4_Board&);

    void getmove(int &x, int &y) override;
    int max_move(C4_Board board, int turn=1, int depth = 0);
};



#endif //C4_AI_H
