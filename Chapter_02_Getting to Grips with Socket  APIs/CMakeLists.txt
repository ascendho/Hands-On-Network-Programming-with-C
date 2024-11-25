cmake_minimum_required(VERSION 3.28)
project(Chapter_02_Getting_to_Grips_with_Socket__APIs C)

set(CMAKE_C_STANDARD 11)

add_executable(sock_init sock_init.c)
add_executable(time_console time_console.c)

add_executable(time_server time_server.c)