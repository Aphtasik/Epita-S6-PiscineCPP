cmake_minimum_required(VERSION 3.0)
project(libhello)

add_library(libhello STATIC hello.hh hello.cc)
set_target_properties(libhello PROPERTIES PREFIX "")
