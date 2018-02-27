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

    void insertarPrimero(Dato valor);
    void insertarFinal(Dato valor);
    bool eliminarInicio(Dato valor);
    bool eliminarFinal(Dato valor);
    void imprimir();
    bool esVacia();
    void instrucciones();
    void probarLista();
    void menu();


};
#endif //TAREAEXTRAXLASE_LISTA_H
