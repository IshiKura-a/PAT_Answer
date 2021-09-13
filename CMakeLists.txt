# cmake_minimum_required(VERSION <specify CMake version here>)
project(PAT_Answer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -g)
set(CMAKE_BUILD_TYPE Debug)


add_executable(PAT_Answer Advanced/1072.cpp)

target_link_libraries(PAT_Answer)