cmake_minimum_required(VERSION 3.29)
project(GameApplication)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameApplication
        main.cpp

        Core/Board.h
        Core/GameManager.h
        Core/GameManager.cpp
        Core/Player.h
        Core/Player.cpp
        Core/RandomPlayer.h
        Core/RandomPlayer.cpp
        Utils/GameTheory.cpp
        Utils/GameTheory.h
        Four-in-row/Board_Four_In_Row.h
        Four-in-row/Board_Four_In_Row.cpp

)
