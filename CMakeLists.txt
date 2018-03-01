cmake_minimum_required(VERSION 3.8)
project(TareaExtraxlase)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "Nodo.h" ListaEnlazadaSimple.h ListaEnlazadaSimple.cpp ListaEnlazadaDoble.cpp ListaEnlazadaDoble.h NodoDoble.h)
add_executable(TareaExtraxlase ${SOURCE_FILES})