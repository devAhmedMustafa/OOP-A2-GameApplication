//
// Created by Nour on 2024-12-15.
//

#ifndef GAMEAPPLICATION_WTTT_BOARD_H
#define GAMEAPPLICATION_WTTT_BOARD_H
#include "../Core/Board.h"


class WTTT_Board : public Board<char> {
public:
    WTTT_Board();
    ~WTTT_Board();

    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;
};


#endif //GAMEAPPLICATION_WTTT_BOARD_H
