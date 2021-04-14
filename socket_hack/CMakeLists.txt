cmake_minimum_required(VERSION 3.7)
project(socket_hack_proj)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES c++11_test.cpp)

add_executable(socket_server_hack socket_server_hack.cpp)
add_executable(socket_client_hack socket_client_hack.cpp)

