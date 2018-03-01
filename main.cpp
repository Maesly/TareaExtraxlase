#include <iostream>
#include "ListaEnlazadaSimple.h"
#include "ListaEnlazadaDoble.h"

using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    //Dato d;
    ListaEnlazadaDoble lista;
    cout<< "Elementos de la lista: " <<endl;

    lista.insertarAlInicio(1);
    lista.insertarAlInicio(2);
    lista.insertarAlInicio(3);
    lista.insertarAlInicio(4);
    lista.insertarAlInicio(5);
    lista.insertarAlFinal(96);
    lista.insertar(78,3);
    lista.imprimirLista();



   /* lista.insertarPrimero(1);
    lista.insertarPrimero(2);
    lista.insertarPrimero(3);
    lista.insertarPrimero(4);
    lista.insertarPrimero(5);
    lista.insertarPrimero(6);
    //lista.editarPosicion(69,8);
    lista.buscar(1);
   // lista.eliminarPosicion(5);
    lista.imprimir();
*/



    return 0;
}