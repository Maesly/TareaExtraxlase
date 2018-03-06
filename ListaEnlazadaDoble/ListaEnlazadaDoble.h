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
    NodoDoble* cabeza;          //Puntero tipo nodo que apunta a la cabeza de la lista
    NodoDoble* cola;            //Puntero tipo nodo que apunta a la cola de la lista

public:
    ListaEnlazadaDoble(){       //Constructor de la clase Lista Enlazada Doble
        cabeza = cola = NULL;

    }

    int cantidadNodos = 0;      //Variable que que lleva la cantidad de nodos
    bool esVacia();

    void insertarAlInicio(Dato valor);      //Inserta un nodo al inicio de la lista
    void insertarAlFinal(Dato valor);       //Inserta un nodo al final de la lista
    void insertar(Dato valor,Dato posicion);//Inserta un nodo en cualquier posicion de la lista

    void eliminarAlInicio();                //Elimina el primer nodo de la lista
    void eliminarUltimo();                  //Elimina el ultimo nodo de la lista
    void eliminar(int posicion);            //Elimina un nodo en cualquier posicion

    void obtenerPosicion(int dato);     //

    void editarNodo(Dato valor, int posicion); //

    void imprimirLista();
};
#endif //TAREAEXTRAXLASE_LISTAENLAZADADOBLE_H
