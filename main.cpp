#include <iostream>
#include "Lista.h"

using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    Dato d;
    Lista lista;
    cout<< "Elementos de la lista, termina con -1" <<endl;
    //cin >> d;
    lista.probarLista();
/*/
    do{
        cin >> d;

        if(d != -1){
        //lista.insertarPrimero(d);
            lista.insertarFinal(d);
            //lista.eliminarFinal(d);
        }

    }
    while(d != -1);


    cout << "\t Elementos de la lista generados al azar" << endl;

    //lista.crearLista();
    lista.eliminarInicio(4);
    lista.imprimir();

    /*/

    return 0;
}