cmake_minimum_required(VERSION 3.10)

project(hello)

add_subdirectory(libhello)

add_executable(hello main.cc)

target_link_libraries(hello libhello)
