cmake_minimum_required(VERSION 3.28)
project(Chapter_03_An_In_Depth_Overview_of_TCP_Connections C)

set(CMAKE_C_STANDARD 11)

add_executable(main tcp_client.c chap03.h)

add_executable(tcp_serve_toupper tcp_serve_toupper.c)
add_executable(tcp_serve_toupper_fork tcp_serve_toupper_fork.c)
add_executable(tcp_serve_chat tcp_serve_chat.c)