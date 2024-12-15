//
// Created by Ahmed Mustafa on 12/6/2024.
//

#include "GameTheory.h"

int GameTheory::kernelWinner(int **board, const std::vector<std::vector<int> > &kernel, const int rows,
                              const int columns, const int winLength) {

    const int kRows = kernel.size();
    const int kColumns = kernel[0].size();

    for (int row = 0; row <= rows - kRows; row++) {
        for (int col = 0; col <= columns - kColumns; col++) {

            int sum = 0;

            for (int i = 0; i < kRows; i++) {
                for (int j = 0; j < kColumns; j++) {
                    sum += kernel[i][j] * board[row + i][col + j];
                }
            }

            if (sum == winLength) {
                return 1;
            }
            if (sum == -winLength) {
                return -1;
            }

        }
    }

    return 0;

}

int GameTheory::checkWinner(int **board, const std::vector<std::vector<std::vector<int>>> &kernels, int rows, int columns, int winLength) {

    int winner = 0;

    for (auto &kernel : kernels) {
        winner = kernelWinner(board, kernel, rows, columns, winLength);
        if (winner) {
            break;
        }
    }


    return winner;
}

int** GameTheory::normalizeBoard(char **board, int rows, int columns, std::map<char, int> &mapping) {

    auto normalizedBoard = new int *[rows];
    for (int i = 0; i < rows; i++) {
        normalizedBoard[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            auto v = mapping.find(board[i][j]);
            if (v == mapping.end()) {
                normalizedBoard[i][j] = 0;
                continue;
            }
            normalizedBoard[i][j] = v->second;
        }
    }

    return normalizedBoard;
    
}
