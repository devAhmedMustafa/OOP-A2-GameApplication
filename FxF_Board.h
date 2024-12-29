//
// Created by am180 on 12/16/2024.
//

#ifndef GAMEAPPLICATION_FXF_BOARD_H
#define GAMEAPPLICATION_FXF_BOARD_H

#include "../Core/Board.h"


class FxF_Board : public Board<char> {
private:
    int scores[2] = {0,0};


public:
    FxF_Board();
    ~FxF_Board();

    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};


#endif //GAMEAPPLICATION_FXF_BOARD_H
