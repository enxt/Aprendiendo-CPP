cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp rectangulo.cpp vrectangulo.cpp)
add_executable(Cuestion2.2 ${SOURCE_FILES})