cmake_minimum_required(VERSION 3.18)
project(utils LANGUAGES CXX C)

add_library(utils)
include(Sources.cmake)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(tests)
