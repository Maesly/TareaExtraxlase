//
// Created by maesly on 01/03/18.
//

#ifndef TAREAEXTRAXLASE_NODOCIRCULAR_H
#define TAREAEXTRAXLASE_NODOCIRCULAR_H

typedef int Dato;
class NodoCircular{

private:

    Dato dato;
    NodoCircular* enlace;

public:

    NodoCircular(Dato entrada){
        dato = entrada;
        enlace = NULL;
    }

    NodoCircular (Dato p, NodoCircular* n){
        dato = p;
        enlace = n;
    }

    Dato datoNodo() const {
        return dato;

    }

    NodoCircular* siguiente() const{
        return enlace;

    }

    void ponerSiguiente(NodoCircular* sgte){
        enlace = sgte;
    }

    friend class ListaCircular;

};
#endif //TAREAEXTRAXLASE_NODOCIRCULAR_H
