cmake_minimum_required(VERSION 3.21)
project(Maze_Labirint)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maze_Labirint
        src/file.txt
        src/cave.cc
        src/s21_cave.cc)
