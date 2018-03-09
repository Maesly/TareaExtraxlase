#include <iostream>
#include "ListaEnlazadaSimple/ListaEnlazadaSimple.h"
#include "ListaEnlazadaDoble/ListaEnlazadaDoble.h"
#include "ListaCircular/ListaCircular.h"
#include "ArbolBinario/ArbolBinario.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    //Dato d;
    //ListaEnlazadaDoble lista;
    //ListaEnlazadaSimple lista2;
    //ListaCircular lista3;
    ArbolBinario* arbolBinario;
    NodoArbol *arbol = nullptr;
    arbolBinario->insertarNodo(arbol,23,NULL);
    arbolBinario->insertarNodo(arbol,15,NULL);
    arbolBinario->insertarNodo(arbol,7,NULL);
    arbolBinario->insertarNodo(arbol,6,NULL);
    arbolBinario->insertarNodo(arbol,25,NULL);
    arbolBinario->insertarNodo(arbol,99,NULL);
    arbolBinario->mostrarArbol(arbol,0);
    //arbolBinario->menu();

    return 0;
}