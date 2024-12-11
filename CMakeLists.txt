cmake_minimum_required(VERSION 3.29)
project(GameApplication)

set(CMAKE_PREFIX_PATH C:\\libtorch)

find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
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
        AI/Network.h
        AI/ReplayBuffer.h
        AI/Connect4Agent.h
        AI/Connect4Agent.cpp

)

target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")

set_property(TARGET GameApplication PROPERTY CXX_STANDARD 20)