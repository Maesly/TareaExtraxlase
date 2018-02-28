#include <iostream>
#include "Lista.h"

using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    Dato d;
    Lista lista;
    cout<< "Elementos de la lista: " <<endl;
    lista.insertarPrimero(1);
    lista.insertarPrimero(2);
    lista.insertarPrimero(3);
    lista.insertarPrimero(4);
    lista.insertarPrimero(5);
    lista.insertarPrimero(6);
    lista.eliminarPosicion(5);
    lista.imprimir();


    return 0;
}