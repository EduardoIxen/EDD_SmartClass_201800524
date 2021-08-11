cmake_minimum_required(VERSION 3.20)
project(EDD_SmartClass_201800524)

set(CMAKE_CXX_STANDARD 20)

add_executable(EDD_SmartClass_201800524 main.cpp Objetos/Estudiante.cpp Objetos/Estudiante.h ReadFile/ReadCsv.cpp ReadFile/ReadCsv.h)
