//
// Created by maesly on 22/02/18.
//

#include "Lista.h"
using namespace std;
#include <iostream>


void Lista::insertarPrimero(int dato) {

    Nodo* nuevo;                //Crea el nodo
    nuevo = new Nodo(dato);     //Le asigna al nodo el dato que se desea

    if(esVacia()){
        cabeza = nuevo  ;      //La nueva lista tiene un solo nodo
    }
    else{
        nuevo->siguiente(cabeza);  //Enlaza nuevo con siguiente
        cabeza = nuevo;              // mueve siguiente y apunta al nuevo nodo
    }
}

void Lista::insertarFinal(Dato valor) {

    Nodo* nuevo;
    nuevo = new Nodo(valor);

    if(esVacia()){
        cabeza = nuevo;
    }
    else{
        nuevo->siguiente(NULL);
        if(cabeza->enlaceNodo()== 0)
            cabeza->siguiente(nuevo);
        //cola->siguiente(nuevo);
        //cola = nuevo;

    }
}

bool Lista::eliminarFinal(Dato valor) {
    if(esVacia()){
        return false;
    }
    else{
        Nodo* temp = cola;
        if(cabeza == cola){
            cabeza = cola = 0;
        }
        else{
            Nodo* actual = cabeza;
            while(actual->enlaceNodo() != cola)
                actual = actual->enlaceNodo();
            cola = actual;
            actual->siguiente(0);
        }
        //valor = temp->datoNodo();
        delete temp;
        return true;
    }
}

bool Lista::eliminarInicio(Dato valor) {
    if(esVacia()){
        return false;
    }
    else{
        Nodo* temp = cabeza;

        if (cabeza == cola)
            cabeza= cola = 0;
        else
            cabeza = cabeza->enlaceNodo();
        delete temp;
        return true;
    }
}

bool Lista::esVacia()  {
    return cabeza == NULL;
}

void Lista::imprimir() {
    Nodo* n;
    n = cabeza;
    //cout << "Lista: \n "<< endl;
    if( n == NULL){
        cout<< "La lista se encuentra vacía\n"<<endl;
    }
    while(n != NULL){
        cout <<"->"<< n->datoNodo()<<"\t";
        cout << n<<endl;
        n = n->enlaceNodo();

    }
}

void Lista::instrucciones() {

    cout << "Escriba una de las siguientes opciones: \n"
         << " 1 para insertar al inicio de la lista\n"
         << " 2 para insertal al final de la lista\n"
         << " 3 para eliminar del principio de la lista\n"
         << " 4 para eliminar del final de la lista\n"
         << " 5 para finalizar la lista\n";
}

void Lista::probarLista() {
    int opcion;
    instrucciones();

    Dato d;
    Lista lista;
    do{
        cout << "?";
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Escriba ";
                int b;
                cin >> b;
                lista.insertarPrimero(b);
                lista.imprimir();
                break;
            case 2:
                cout << "Escriba ";
                cin >> d;
                lista.insertarFinal(d);
                lista.imprimir();
                break;
            case 3:
                if(lista.eliminarInicio(d))
                    cout << d << " se eliminó de la lista\n";
                lista.imprimir();
                break;
            case 4:
                if(lista.eliminarFinal(d))
                    cout << d << " se eliminó de la lista\n";
                lista.imprimir();
                break;
        }
    }while(opcion != 5);
}