cmake_minimum_required(VERSION 3.16)
project(Audio)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADER_FILES "${PROJECT_NAME}/*.h")
file(GLOB_RECURSE SOURCE_FILES "${PROJECT_NAME}/*.cpp")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_NAME})

add_library(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

