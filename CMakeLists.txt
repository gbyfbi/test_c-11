cmake_minimum_required(VERSION 3.7)
project(test_c__11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES c++11_test.cpp)
add_executable(c++11_test ${SOURCE_FILES})

find_package(Boost REQUIRED)
add_executable(boost_test boost_test.cpp)
target_link_libraries(boost_test ${Boost_LIBRARIES})

#set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /home/gao/Downloads/cpp-netlib/install )
#find_package ( cppnetlib 0.13.0 REQUIRED )
find_package(cppnetlib CONFIG REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CPPNETLIB_INCLUDE_DIRS})
add_executable(cpp_netlib_hack cpp_netlib_hack.cpp)
target_link_libraries(cpp_netlib_hack PRIVATE cppnetlib-uri cppnetlib-server-parsers cppnetlib-client-connections)

add_subdirectory(socket_hack)
