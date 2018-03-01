//
// Created by maesly on 28/02/18.
//

#ifndef TAREAEXTRAXLASE_LISTAENLAZADADOBLE_H
#define TAREAEXTRAXLASE_LISTAENLAZADADOBLE_H

typedef int Dato;

#include <clocale>
#include "NodoDoble.h"
#include <iostream>

class ListaEnlazadaDoble{  // Lista Doblemente enlazada

private:
    NodoDoble* cabeza;
    NodoDoble* cola;

public:
    ListaEnlazadaDoble(){
        cabeza = NULL;
        cola = NULL;
    }
    //~ListaEnlazadaDoble();
    int cantidadNodos = 0;
    bool esVacia();

    void insertarAlInicio(Dato valor);
    void insertarAlFinal(Dato valor);
    void insertar(Dato valor,Dato posicion);

    void eliminarAlInicio();
    void eliminarAlFinal();
    void eliminar(NodoDoble* v);

    void obtenerPosicion(int posicion);

    void editarNodo(Dato valor, int posicion);

    void imprimirLista();
};
#endif //TAREAEXTRAXLASE_LISTAENLAZADADOBLE_H
