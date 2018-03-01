//
// Created by maesly on 28/02/18.
//

#include "ListaEnlazadaDoble.h"
#include <iostream>

using namespace std;
/*
ListaEnlazadaDoble::~ListaEnlazadaDoble() { //Destructor de la clase
    while (!esVacia()) eliminarAlInicio();
    delete cabeza;
    delete cola;
}*/

bool ListaEnlazadaDoble::esVacia() {  //Valida si la lista esta vacía
    return cabeza == NULL;
}
/**
 * @brief Inserta un nodo antes de v
 * @param valor Dato que se insertará en el nuevo nodo
 * @param v Nodo posterior al que se desea insertar
 * */
void ListaEnlazadaDoble::insertar(Dato valor,Dato posicion) {

    NodoDoble* tempAnterior = cabeza;
    NodoDoble* tempSiguiente = cabeza->siguienteNodo();

    NodoDoble* nuevo;
    nuevo = new NodoDoble(valor);
    int contPosicion = 0;

    if(esVacia()){          // Valida si la lista esta vacía
        cabeza = nuevo;
        cantidadNodos++;
    }else if(posicion == contPosicion){   /// Valida si la posicion a cambiar sea la primera
        insertarAlInicio(valor);            ///LLama insertar al inicio
        cout<<"Error de índice\n";
    } else{
        while (contPosicion != posicion-1){ // Ciclo que recorre la lista
            tempAnterior = tempAnterior->siguienteNodo();
            tempSiguiente = tempSiguiente->siguienteNodo();
            contPosicion++;
        }
        nuevo->ponerSiguiente(tempSiguiente);           // Asigna el siguiente de nuevo
        nuevo->ponerAnterior(tempAnterior);             // Asigna el anterior de nuevo
        tempAnterior->ponerSiguiente(nuevo);            // Reasigna el siguiente tempAnterior
        tempSiguiente->ponerAnterior(nuevo);            // Reasigna el anterior de tempSiguiente
        cantidadNodos++;
    }

}
/**
 * @brief Funcion que se encarga de insertar un nodo al inicio de una lista
 * @param valor Crea un nuevo nodo que contenga ese dato
 * */
void ListaEnlazadaDoble::insertarAlInicio(Dato valor) {

    NodoDoble* nuevo;
    nuevo = new NodoDoble(valor);

    if(esVacia() ){
        cabeza = nuevo;
        cantidadNodos++;
    }else{
        nuevo->ponerSiguiente(cabeza);
        nuevo->ponerAnterior(cabeza);
        cabeza = nuevo;
        cantidadNodos++;
    }
}
/**
 * @brief Funcion que se encarga de insertar un nodo al final de la lista
 * @param valor Crea un nuevo nodo que contenga ese dato
 * */
void ListaEnlazadaDoble::insertarAlFinal(Dato valor) {

    NodoDoble* temp = cabeza;

    NodoDoble* nuevo;
    nuevo = new NodoDoble(valor);

    if(esVacia()){              //Valida si la lista se encuentra vacia
        cabeza = nuevo;         //Crea el primer nodo
        cantidadNodos++;
    }
    else{
        while(temp->siguienteNodo() != NULL){ //Ciclo que recorre la lista
            temp = temp->siguienteNodo();
        }
        nuevo->ponerSiguiente(NULL);       //Asigna el siguiente de nuevo como Null
        nuevo->ponerAnterior(temp);        //Asigna el anterior de nuevo como temp
        temp->ponerSiguiente(nuevo);       //Reasigna el ultimo nodo como el penultimo
        cantidadNodos++;
    }
}

void ListaEnlazadaDoble::eliminar(NodoDoble* v) {
    NodoDoble* nuevo = v->anterior;
    NodoDoble* nuevo2 = v->siguiente;
    nuevo->ponerSiguiente(nuevo2);
    nuevo2->ponerAnterior(nuevo);
    delete v;

}

void ListaEnlazadaDoble::eliminarAlInicio() {
    eliminar(cabeza->siguiente);
}

void ListaEnlazadaDoble::eliminarAlFinal() {
    eliminar(cola->anterior);
}

void ListaEnlazadaDoble::imprimirLista() {
    NodoDoble* n1 = cabeza;

    if( esVacia()){                  // Valida si l lista esta vacía
        cout<< "Lo siento, la lista se encuentra vacía\n"<<endl;
    }
    while(n1 != NULL){ // Ciclo que recorre la lista e imprime cada elemento
        cout <<"->"<< n1->datoNodo()<<"\t";
        cout <<"->"<< n1<<"\n";
        n1 = n1->siguienteNodo();

    }
    //cout << "\nCantidad de nodos en la lista: "<< cantNodos<<endl;
}