cmake_minimum_required(VERSION 3.0)

project(avoc)

add_executable(avoc main.cpp)

install(TARGETS avoc RUNTIME DESTINATION bin)
