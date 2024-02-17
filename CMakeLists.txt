cmake_minimum_required(VERSION 3.26)
project(lab1_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

include_directories(include)
add_executable(lab1_cpp ${SOURCES})