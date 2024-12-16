//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef UTTT_H
#define UTTT_H
#include "../Core/Board.h"

#include "../Tic-Tac-Toe/TTT.h"

class UTTT_Board : public Board<char> {

    TTT boards[9];

public:

    UTTT_Board();
    ~UTTT_Board();

    bool update_board(int x, int y, char symbol) override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;
    void display_board() override;
};



#endif //UTTT_H
