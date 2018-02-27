#include <iostream>
#include "Lista.h"

using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    Dato d;
    Lista lista;
    cout<< "Elementos de la lista, termina con -1" <<endl;
    lista.insertarPrimero(1);
    lista.insertarPrimero(2);
    lista.insertarPrimero(3);
    lista.imprimir();


    return 0;
}