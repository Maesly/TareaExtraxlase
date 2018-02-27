//
// Created by maesly on 22/02/18.
//
typedef int Dato;
//archivo de cabecera Nodo.h

#ifndef TAREAEXTRAXLASE_NODO_H
#define TAREAEXTRAXLASE_NODO_H

class Nodo{

protected:
    Dato dato;
    Nodo* enlace;
public:
    Nodo(Dato t){
        dato = t;
        enlace = 0;
    }
    Nodo(Dato p, Nodo* n){
        dato = p;
        enlace = n;
    }
    Dato datoNodo() const {
        return dato;

    }

    Nodo* enlaceNodo() const{
        return enlace;

    }

    void ponerEnlace(Nodo* sgte){
        enlace = sgte;
    }

};

#endif //TAREAEXTRAXLASE_NODO_H
