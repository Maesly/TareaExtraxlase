//
// Created by maesly on 22/02/18.
//

#include "Lista.h"
using namespace std;
#include <iostream>

/**
 *@brief Crea un nuevo nodo con el dato que se desea insertar
 * y lo añade de primero en la lista
 *@param dato Elemento a insertar en la lista
 *
 * */
void Lista::insertarPrimero(int dato) {

    Nodo* nuevo;                //Crea el nodo
    nuevo = new Nodo(dato);     //Le asigna al nodo el dato que se desea

    if(esVacia()){
        cabeza = nuevo  ;      //La nueva lista tiene un solo nodo
        cantNodos++;
    }

    else{
        nuevo->siguiente(cabeza);  //Enlaza nuevo con siguiente
        cabeza = nuevo;             // mueve siguiente y apunta al nuevo nodo
        cantNodos++;
    }
}

/**
 * @brief Inserta un elemento al final de la lista
 * @param valor
 * */
void Lista::insertarFinal(Dato valor) {

    Nodo* temp = cabeza;
    Nodo* nuevo = new Nodo(valor);

    if(temp == NULL){
        cabeza = nuevo;
        cantNodos++;
    }
    else{
        while(temp->enlaceNodo() != NULL){
            temp = temp->enlaceNodo();
        }
        temp->siguiente(nuevo);
        nuevo->siguiente(NULL);
        cantNodos++;
    }
}

void Lista::insertar(Dato valor, int posicion) {
    Nodo* anterior = cabeza;
    Nodo* siguiente = cabeza->enlaceNodo();
    Nodo* nuevo;
    nuevo = new Nodo(valor);

    int c = 0;

    if(esVacia()){
        cabeza = nuevo;             // Asigno nuevo como la nueva cabeza
        cantNodos++;                // Aumenta en una unidad el numero de nodos
    }
    else if(posicion > cantNodos){
        cout<<"Error de indice"<<endl;
    }
    else if(c == posicion) {        //Realiza una validacion
        insertarPrimero(valor);
        cantNodos++;
    }
    else{
        while(c != posicion-1){
            anterior = anterior->enlaceNodo();
            siguiente = siguiente->enlaceNodo();
            c++;
        }
        nuevo->siguiente(siguiente);
        anterior->siguiente(nuevo);
        cantNodos++;
    }
}

void Lista::eliminarFinal() {

    Nodo* final2 = cabeza->enlaceNodo();        //Crea dos nodos temporales
    Nodo* final = cabeza;

    if(esVacia()){                              //Validacion en caso de que la lista este vacía
        cout << "Error, la lista esta vacía.";
    }
    else{
        while(final2->enlaceNodo() != NULL){    //Ciclo que recorre la lista hasta el ultimo elemento
            final2 = final2->enlaceNodo();
            final = final->enlaceNodo();
        }
        final->siguiente(NULL);                 //Elimina el ultimo nodo
        delete(final2);                         //Libera memoria
    }
}

void Lista::eliminarInicio() {

    if(esVacia()){
        cout<< " Error, la lista se encuentra vacía.";
    }
    else{
        Nodo* temp= cabeza;
        cabeza = temp->enlaceNodo();
        delete(temp);
    }
}

bool Lista::esVacia()  {
    return cabeza == NULL;
}
/**
 * */

void Lista::imprimir() {

    Nodo* n = cabeza;

    if( n == NULL){
        cout<< "La lista se encuentra vacía\n"<<endl;
    }
    while(n != NULL){
        cout <<"->"<< n->datoNodo()<<"\t";

        n = n->enlaceNodo();

    }
    cout << "\nCantidad de nodos en la lista: "<< cantNodos<<endl;
}

void Lista::instrucciones() {

    cout << "Escriba una de las siguientes opciones: \n"
         << " 1 para insertar al inicio de la lista\n"
         << " 2 para insertal al final de la lista\n"
         << " 3 para eliminar del principio de la lista\n"
         << " 4 para eliminar del final de la lista\n"
         << " 5 para finalizar la lista\n";
}
/*
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
}*/