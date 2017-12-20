cmake_minimum_required(VERSION 3.9)
project(game)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(BirchEngine/)