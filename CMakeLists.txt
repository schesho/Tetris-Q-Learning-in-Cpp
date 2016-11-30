cmake_minimum_required(VERSION 3.5)
project(tetris_rl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Field.cpp Field.h Piece.cpp Piece.h)
add_executable(tetris_rl ${SOURCE_FILES})