cmake_minimum_required(VERSION 3.28)
project(Chapter_05_Hostname_Resolution_and_DNS C)

set(CMAKE_C_STANDARD 11)


add_executable(lookup lookup.c chap05.h)

add_executable(dns_query dns_query.c)