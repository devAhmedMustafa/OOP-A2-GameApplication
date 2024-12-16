//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef SUS_BOARD_H
#define SUS_BOARD_H
#include "../Core/Board.h"


class SUS_Board : public Board<char> {
public:
    SUS_Board();
    ~SUS_Board();
    void display_board() override;
    bool update_board(int x, int y, char symbol) override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;
};



#endif //SUS_BOARD_H
