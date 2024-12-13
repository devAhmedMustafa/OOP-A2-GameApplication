//
// Created by Ahmed Mustafa on 12/12/2024.
//

#include "GUI.h"

#include "../vendor/imgui/imgui.h"

template <typename T>
GUI<T>::GUI(Board<T>* board) : board(board) {}

template <typename T>
void GUI<T>::renderCell(const string& cell, int i, int j) {
    if (ImGui::Button(cell.c_str(), ImVec2(100, 100))) {

    }
}

template <typename T>
void GUI<T>::renderBoard(int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            renderCell(" ", i, j);
        }
    }

}
