//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef ITTT_BOARD_H
#define ITTT_BOARD_H
#include "../Core/Board.h"


class ITTT_Board : public Board<char> {

    char last_symbol;

public:

    ITTT_Board();
    ~ITTT_Board();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;

    friend class TTT;

};



#endif //ITTT_BOARD_H
