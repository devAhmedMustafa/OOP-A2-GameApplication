//
// Created by Nour on 2024-12-05.
//

#ifndef GAMEAPPLICATION_BOARD_PTTT_H
#define GAMEAPPLICATION_BOARD_PTTT_H
#include "../Core/Board.h"

class PTTT_Board : public Board<char> {
public:
    PTTT_Board();
    ~PTTT_Board();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

};


#endif //GAMEAPPLICATION_BOARD_PTTT_H
