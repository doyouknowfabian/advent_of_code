cmake_minimum_required(VERSION 3.18)
project(aoc)

option(BUILD_UTILS "Build utils project" OFF)
option(BUILD_2024 "Build 2024 project" ON)

if(BUILD_UTILS)
  add_subdirectory(utils)
endif()

if(BUILD_2024)
  add_subdirectory(2024)
endif()



