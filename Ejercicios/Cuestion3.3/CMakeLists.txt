cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(COPY texto.txt DESTINATION ${Aprendiendo_CPP_BINARY_DIR}/Ejercicios/Cuestion3.3)

set(SOURCE_FILES main.cpp)
add_executable(Cuestion3.3 ${SOURCE_FILES} main.cpp)