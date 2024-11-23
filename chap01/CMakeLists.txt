cmake_minimum_required(VERSION 3.28)
project(chap01 C)

set(CMAKE_C_STANDARD 11)

add_executable(win_list
        win_init.c win_list.c
)


add_executable(unix_list
        unix_list.c
)

