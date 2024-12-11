cmake_minimum_required(VERSION 3.29)
project(GameApplication)

set(CMAKE_CXX_STANDARD 20)

set(GLEW_PATH "C:\\libs\\glew")
set(GLFW_PATH "C:/glfw-3.4.bin.WIN64")
set(GLEW_STATIC ON)

include_directories(${GLEW_PATH}/include ${GLFW_PATH}/include)

find_library(GLEW_LIB glew32s HINTS ${GLEW_PATH}/lib/Release/x64)
find_library(GLFW_LIB glfw3 HINTS ${GLFW_PATH}/lib-vc2015)

find_package(OpenGL REQUIRED)

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

target_compile_definitions(GameApplication PUBLIC GLEW_STATIC)
target_link_libraries(GameApplication PRIVATE ${GLEW_LIB} ${GLFW_PATH}/lib-vc2015/glfw3.lib ${OPENGL_LIBRARIES})