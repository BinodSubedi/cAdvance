cmake_minimum_required(VERSION 3.0)
project(cAdvanced)
include_directories(./src/include)

set(CMAKE_C_COMPILER /usr/bin/gcc)

set(Sources
  ./src/main.c
  ./src/ncurses/ncurses.c
  ./src/malloc/malloc.c
  ./src/linkedList/linkedList.c)

add_executable(${PROJECT_NAME} ${Sources})

