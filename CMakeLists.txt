cmake_minimum_required(VERSION 3.7)
project(test_c__11)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES c++11_test.cpp)
add_executable(c++11_test ${SOURCE_FILES})

find_package(Boost REQUIRED)
add_executable(boost_test boost_test.cpp)
target_link_libraries(boost_test ${Boost_LIBRARIES})