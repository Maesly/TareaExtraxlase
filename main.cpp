#include <iostream>
#include "ListaEnlazadaSimple/ListaEnlazadaSimple.h"
#include "ListaEnlazadaDoble/ListaEnlazadaDoble.h"
#include "ListaCircular/ListaCircular.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    //Dato d;
    //ListaEnlazadaDoble lista;
    //ListaEnlazadaSimple lista2;
    ListaCircular lista3;
    cout<< "Elementos de la lista: " <<endl;


    lista3.insertarAlfinal(1);
    lista3.insertarAlfinal(2);
    lista3.insertarAlfinal(3);
    lista3.insertarAlfinal(4);
    lista3.insertarAlfinal(5);
    lista3.editarPosicion(6,5);
    //lista3.buscar(3);
    //lista3.eliminar(1);
    //lista3.insertarAlinicio(2);
    //lista3.insertarAlinicio(1);
    //lista3.insertarAlfinal(6);
    //lista3.insertar(8,0);
    //lista3.eliminarAlinicio();
    //lista3.eliminarAlfinal();
    lista3.imprimirLista();

    return 0;
}