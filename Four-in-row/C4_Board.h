//
// Created by am180 on 12/5/2024.
//

#ifndef GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H
#define GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H

#include <iostream>
#include "../Core/Board.h"

class C4_Board : public Board<char> {

private:
    int filled[7] = {5,5,5,5,5,5,5};

public:
    C4_Board();
    C4_Board(const C4_Board &board);
    ~C4_Board();

    vector<float> flatten_board() const;
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

    friend class C4_ai;
};


#endif //GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H
