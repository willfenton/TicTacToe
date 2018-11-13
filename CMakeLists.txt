cmake_minimum_required(VERSION 3.12)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TicTacToe
        board.cpp
        board.h
        main.cpp
        minimax.cpp
        minimax.h
        playerFunctions.cpp
        playerFunctions.h)
