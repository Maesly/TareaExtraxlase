//
// Created by maesly on 06/03/18.
//

#include <clocale>

#include <iostream>
using namespace std;
;
#ifndef TAREAEXTRAXLASE_ARBOLBINARIO_H
#define TAREAEXTRAXLASE_ARBOLBINARIO_H

struct NodoArbol{
    int dato;
    NodoArbol* padre;
    NodoArbol* der;
    NodoArbol* izq;
};

class ArbolBinario{

private:
    NodoArbol* crearNodo(int,NodoArbol*);
    NodoArbol* minimo(NodoArbol*);
    void reemplazar(NodoArbol*,NodoArbol*);
    void eliminarNodo(NodoArbol*);
    void destruirNodo(NodoArbol*);


public:
    NodoArbol* arbol = NULL;
    //ArbolBinario* arbolBinario;
    void menu();
    void insertarNodo(NodoArbol *&,int,NodoArbol*);
    void eliminar(NodoArbol*,int);
    void mostrarArbol(NodoArbol*, int);

};
#endif //TAREAEXTRAXLASE_ARBOLBINARIO_H
