//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef NUMERICALTTT_H
#define NUMERICALTTT_H
#include "../Core/Board.h"


class NTTT_Board : public Board<int> {
public:
    NTTT_Board();

    bool update_board(int x, int y, int symbol) override;
    void display_board() override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;

};



#endif //NUMERICALTTT_H
