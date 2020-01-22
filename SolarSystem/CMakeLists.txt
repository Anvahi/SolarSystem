cmake_minimum_required(VERSION 3.14)
project(SolarSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(SolarSystem main.cpp SolarSystemModel.h)

target_link_libraries(SolarSystem sfml-graphics sfml-window sfml-system)