cmake_minimum_required(VERSION 3.0)

project(avoc)

set(SRC_DIR src/)
set(LIBS_DIR src/libs/)

set(SOURCES
${SRC_DIR}main.cpp
${SRC_DIR}token.cpp
)
add_executable(avoc ${SOURCES})

target_link_directories(avoc PRIVATE ${LIBS_DIR})

install(TARGETS avoc RUNTIME DESTINATION bin)
