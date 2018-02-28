//
// Created by maesly on 22/02/18.
//

#ifndef TAREAEXTRAXLASE_LISTA_H
#define TAREAEXTRAXLASE_LISTA_H

typedef int Dato;

#include <clocale>
#include "Nodo.h"
#include <iostream>

class Lista{
protected:
    Nodo* cabeza;
    Nodo* cola;

public:
    //Constructor de la clase Lista
    Lista(){
        cabeza = NULL;

        cola = NULL;
    }
    int cantNodos = 0;

    void insertarPrimero(Dato valor);
    void insertarFinal(Dato valor);
    void insertar(Dato valor, int posicion);
    void eliminarInicio();
    void eliminarFinal();
    void imprimir();
    bool esVacia();
    void instrucciones();
    void probarLista();
    void menu();

    Nodo* ultimo();
};
#endif //TAREAEXTRAXLASE_LISTA_H
