cmake_minimum_required(VERSION 3.1)
project(Aprendiendo_CPP)

add_subdirectory(Ejercicios)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES
#    Lecciones/curso.html.7z
#    Lecciones/Tema1.md
#    Lecciones/Tema2.md
#    Lecciones/Tema3.md
#    CMakeList.txt
#    README.md)

#add_executable(Aprendiendo_CPP ${SOURCE_FILES})