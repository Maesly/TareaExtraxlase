//
// Created by maesly on 28/02/18.
//

#ifndef TAREAEXTRAXLASE_NODODOBLE_H
#define TAREAEXTRAXLASE_NODODOBLE_H

#include <clocale>

typedef int Dato;

class NodoDoble{

protected:
    NodoDoble* siguiente;
    NodoDoble* anterior;
    Dato dato;

public:
    NodoDoble(Dato t){
        dato = t;
        siguiente = anterior = NULL;
    }

    Dato datoNodo() const{
        return dato;
    }

    NodoDoble* siguienteNodo() const {
        return siguiente;
    }

    NodoDoble* anteriorNodo() const {
        return anterior;
    }

    void ponerSiguiente(NodoDoble* a){
        siguiente = a;
    }
    void ponerAnterior(NodoDoble* a){
        anterior = a;
    }

    friend class ListaEnlazadaDoble;
};

#endif //TAREAEXTRAXLASE_NODODOBLE_H
