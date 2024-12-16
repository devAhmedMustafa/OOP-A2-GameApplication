//
// Created by Ahmed Mustafa on 12/17/2024.
//

#ifndef TTT_H
#define TTT_H


#include "../Core/Board.h"
#include "../Inverse Tic-Tac-Toe/ITTT_Board.h"

class TTT : public Board<char> {
public:

    TTT();
    TTT(const ITTT_Board &);
    ~TTT();

    bool update_board(int x, int y, char symbol) override;
    bool is_draw() override;
    bool is_win() override;
    bool game_is_over() override;
    void display_board() override;

    void flip_board();

    friend class UTTT_Board;
};



#endif //TTT_H
