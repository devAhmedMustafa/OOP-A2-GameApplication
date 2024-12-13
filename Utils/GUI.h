//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef GUI_H
#define GUI_H

#include "../Core/Board.h"

template<typename T>
class GUI {

    Board<T>* board;

public:

    GUI(Board<T>* board);

    void renderCell(const string& cell, int i, int j);
    void renderBoard(int rows, int cols);

};



#endif //GUI_H
