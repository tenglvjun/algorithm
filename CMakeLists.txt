project(algorithm)

cmake_minimum_required(VERSION 3.12)

#set C++ standard 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

include_directories(include)
aux_source_directory(src SRC_DIR)

add_executable(algorithm ${SRC_DIR})