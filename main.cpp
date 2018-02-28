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
    lista.insertar(78,3);

    lista.imprimir();


    return 0;
}