//
// Created by Ahmed Mustafa on 12/6/2024.
//

#ifndef GAMETHEORY_H
#define GAMETHEORY_H
#include <map>
#include <vector>
#include <iostream>

class GameTheory {

public:
    static int kernelWinner(int** board, const std::vector<std::vector<int>> &kernel, int rows, int columns, int winLength);
    static int checkWinner(int** board, const std::vector<std::vector<std::vector<int>>> &kernels, int rows, int columns, int winLength);

    static int** normalizeBoard(char** board, int rows, int columns, std::map<char, int> &mapping);

};



#endif //GAMETHEORY_H
