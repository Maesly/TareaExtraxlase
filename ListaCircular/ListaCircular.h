//
// Created by maesly on 01/03/18.
//

#ifndef TAREAEXTRAXLASE_LISTACIRCULAR_H
#define TAREAEXTRAXLASE_LISTACIRCULAR_H

#include <clocale>
#include "NodoCircular.h"
#include <iostream>

class ListaCircular{

private:
    NodoCircular* cabeza;
    NodoCircular* final;

public:

    ListaCircular(){
        cabeza = NULL;
        final = cabeza;
    }
    int cantidadNodos = 0;
    bool esVacia();

    void insertarAlinicio(Dato entrada);        //Funciones que insertan un elemento en la lista
    void insertarAlfinal(Dato entrada);
    void insertar(Dato entrada,int posicion);

    void eliminarAlinicio();        //Funciones que eliminan un elemento de la lista
    void eliminarAlfinal();
    void eliminar(Dato posicion);

    void buscar(int dato);                      //Funcion que busca un elemento en la lista

    void editarPosicion(Dato dato, int posicion);   //Funcion que edita un nodo de la lista

    void imprimirLista();
};
#endif //TAREAEXTRAXLASE_LISTACIRCULAR_H
