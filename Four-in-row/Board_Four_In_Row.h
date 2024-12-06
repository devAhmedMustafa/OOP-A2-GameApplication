//
// Created by am180 on 12/5/2024.
//

#ifndef GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H
#define GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H

#include "../Core/Board.h"

class Board_Four_In_Row : public Board<char> {

private:
    int filled[7] = {5,5,5,5,5,5,5};

public:
    Board_Four_In_Row();

    bool place(int x, char symbol);
};


#endif //GAMEAPPLICATION_BOARD_FOUR_IN_ROW_H
