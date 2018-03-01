//
// Created by maesly on 22/02/18.
//

#ifndef TAREAEXTRAXLASE_LISTA_H
#define TAREAEXTRAXLASE_LISTA_H

typedef int Dato;

#include <clocale>
#include "Nodo.h"
#include <iostream>

class ListaEnlazadaSimple{
protected:
    Nodo* cabeza;


public:
    //Constructor de la clase Lista
    ListaEnlazadaSimple(){
        cabeza = NULL;
    }
    int cantNodos = 0;

    //Insertar Nodos
    void insertarPrimero(Dato valor);
    void insertarFinal(Dato valor);
    void insertar(Dato valor, int posicion);

    //Eliminar Nodos
    void eliminarInicio();
    void eliminarFinal();
    void eliminarPosicion(int posicion);

    // Buscar nodo
    void obtenerPosicion(int dato);

    void editarPosicion(int dato,int posicion);

    void imprimir();
    bool esVacia();
    void instrucciones();


};
#endif //TAREAEXTRAXLASE_LISTA_H
