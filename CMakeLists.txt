cmake_minimum_required(VERSION 3.5)
project(tetris_rl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Piece.cpp Piece.h Field.cpp Field.h main.cpp BestActionAndUtility.cpp BestActionAndUtility.h Game.cpp Game.h QBrain.cpp QBrain.h)
add_executable(tetris_rl ${SOURCE_FILES})