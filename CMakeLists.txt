cmake_minimum_required(VERSION 3.8)
project(TareaExtraxlase)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "ListaEnlazadaSimple/Nodo.h" ListaEnlazadaSimple/ListaEnlazadaSimple.h ListaEnlazadaSimple/ListaEnlazadaSimple.cpp ListaEnlazadaDoble/ListaEnlazadaDoble.cpp ListaEnlazadaDoble/ListaEnlazadaDoble.h ListaEnlazadaDoble/NodoDoble.h ListaCircular/NodoCircular.h ListaCircular/ListaCircular.h ListaCircular/ListaCircular.cpp )
add_executable(TareaExtraxlase ${SOURCE_FILES})