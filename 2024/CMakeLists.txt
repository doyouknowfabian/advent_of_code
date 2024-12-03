cmake_minimum_required(VERSION 3.18)
project(2024 LANGUAGES CXX C)

add_executable(2024)
include(Sources.cmake)

target_include_directories(2024 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(2024 PRIVATE utils)
