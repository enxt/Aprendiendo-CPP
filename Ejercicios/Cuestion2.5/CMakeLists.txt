cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp carticulo.cpp cordenador.cpp cportatil.cpp)
add_executable(Cuestion2.5 ${SOURCE_FILES} main.cpp csobremesa.h cimpresora.h cimpresora.cpp csobremesa.cpp carticulo.h)