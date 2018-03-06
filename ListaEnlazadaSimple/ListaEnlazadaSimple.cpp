//
// Created by maesly on 22/02/18.
//

#include "ListaEnlazadaSimple.h"
using namespace std;
#include <iostream>


/**
 * @brief Verifica que la lista se encuentre vacía
 * */
bool ListaEnlazadaSimple::esVacia()  {
    return cabeza == NULL; //Verifica que la lista este vacía
}

/**
 *@brief Crea un nuevo nodo con el dato que se desea insertar
 * y lo añade de primero en la lista
 *@param dato Elemento a insertar en la lista
 *
 * */
void ListaEnlazadaSimple::insertarPrimero(int dato) {

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
 * @param valor Elemento a insertar en la lista
 * */
void ListaEnlazadaSimple::insertarFinal(Dato valor) {

    Nodo* temp = cabeza;
    Nodo* nuevo = new Nodo(valor);      //Crea el nuevo nodo a insertar en la lista

    if(temp == NULL){
        cabeza = nuevo;
        cantNodos++;
    }
    else{
        while(temp->enlaceNodo() != NULL){      //Ciclo que recorre la lista
            temp = temp->enlaceNodo();
        }
        temp->siguiente(nuevo);
        nuevo->siguiente(NULL);
        cantNodos++;
    }
}
/**
 * @brief funcion que inserta un elemento en cualquier posición de la lista
 * @param valor  Elemento a insertar en la lista
 * @param posicion Posición en la que se desea insertar el valor
 * */
void ListaEnlazadaSimple::insertar(Dato valor, int posicion) {

    Nodo* anterior = cabeza;
    Nodo* siguiente = cabeza->enlaceNodo();

    Nodo* nuevo;                //Crea el nuevo nodo
    nuevo = new Nodo(valor);    //Asigna el valor al nodo

    int c = 0;

    if(esVacia()){
        cabeza = nuevo;             // Asigno nuevo como la nueva cabeza
        cantNodos++;                // Aumenta en una unidad el numero de nodos
    }
    else if(posicion > cantNodos){
        cout<<"Error de indice"<<endl;
    }
    else if(c == posicion) {        //Realiza una validacion
        insertarPrimero(valor);     //Llama a la funcion insertarPrimero
        cantNodos++;                //Aumenta en una unidad el numero de nodos
    }
    else{
        while(c != posicion-1){        //Ciclo que recorre la lista hasta llegar a la posicion a insertar
            anterior = anterior->enlaceNodo();
            siguiente = siguiente->enlaceNodo();
            c++;
        }
        nuevo->siguiente(siguiente);     // Nuevo apunta al nodo siguiente
        anterior->siguiente(nuevo);      // anterior apunta al nodo nuevo
        cantNodos++;
    }
}

/**
 * @brief Funcion que elimina elemento al final de la lista
 *
 * */
void ListaEnlazadaSimple::eliminarFinal() {

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
        cantNodos--;
        delete(final2);                         //Libera memoria
    }
}
/**
 * @brief Funcion que elimina elementos al inicio de la lista
 * */
void ListaEnlazadaSimple::eliminarInicio() {

    if(esVacia()){          //Valida si la lista se encuentra vacia
        cout<< " Error, la lista se encuentra vacía.";
    }
    else{
        Nodo* temp= cabeza;     //Crea el puntero temp y lo posiciona al inicio de la lista
        cabeza = temp->enlaceNodo();    //Elimina el primer nodo
        cantNodos--;
        delete(temp);            //Libera memoria
    }
}

/**
 * @brief Funcion que elimina un elemento en cualquier posicion
 * @param posicion La posicion de la lista que se desea eliminar
 * */

void ListaEnlazadaSimple::eliminarPosicion(int posicion) {

    Nodo* anterior = cabeza;
    Nodo* siguiente = cabeza->enlaceNodo();

    int cont = 0;

    if(esVacia()){              // Valida si la lista se encuentra vacía
        cout << "Error, la lista se encuentra vacía ";
    }
    else if(posicion == cont){  //Valida si se quiere eliminar el primer elemento
        eliminarInicio();
        cantNodos--;
    }else if(posicion > cantNodos-1){   //Valida que el nodo que se quiera eliminar realmente este en la lista
        cout<<"Error de indice"<<endl;
    }
    else{
        while(cont < posicion-1){   // Ciclo que recorre la lista
            anterior = anterior->enlaceNodo();
            siguiente = siguiente->enlaceNodo();
            cont++;
        }
        anterior->siguiente(siguiente->enlaceNodo());   //Elimina el nodo deseado
        cantNodos--;
        delete(siguiente);  //Libera memoria
    }
}

void ListaEnlazadaSimple::obtenerPosicion(int dato) {

    Nodo* temp = cabeza;
    int c = 0 ;

    if(esVacia()){
        cout <<"No hay elementos en la lista";
    }
    else {
        while((temp->enlaceNodo() != NULL)&&(temp->datoNodo()!= dato)){
            temp = temp->enlaceNodo();
            c++;
        }
        if(temp->datoNodo() == dato){
            //cout<< temp->datoNodo();
            cout << "\nEl elemento "<< dato<< " esta en la posición: "<<c<< "\n";
        }
        else{
            cout<<"\nLo sentimos, el elemento no se encuentra en la lista\n";
        }
    }
}

/**
 * @brief Funcion que se encarga de editar un elmento en cierta posicion
 * @param posicion Posicion que se desea editar
 * @param dato Elemento por el cual se desea cambiar
 * */

void ListaEnlazadaSimple::editarPosicion(int dato, int posicion) {
    Nodo* temp = cabeza;
    int c = 0;

    if(esVacia()){
        cout<< "Error, no hay elementos en la lista.\n";

    }else if(posicion > cantNodos-1){
        cout<< "No existe elemento en esa posicion\n";
    }
    else{

        while ((temp->enlaceNodo() != NULL) && (c != posicion-1)){
            temp = temp->enlaceNodo();
            c++;
        }
        temp->dato = dato;
        cout << "El nodo en la posicion: "<<posicion<<", se cambio por: " << dato<< " con exito\n";

    }
}



/**
 * @brief Funcion que se encarga de recorrer la lista e imprimir
 * cada nodo
 *
 * */

void ListaEnlazadaSimple::imprimir() {

    Nodo* n = cabeza;      //Crea un puntero y lo posiciona en la cabeza de la lista

    if( esVacia()){    // Valida si l lista esta vacía
        cout<< "La lista se encuentra vacía\n"<<endl;
    }
    while(n != NULL){ // Ciclo que recorre la lista e imprime cada elemento
        cout <<"->"<< n->datoNodo()<<"\t";

        n = n->enlaceNodo();

    }
    cout << "\nCantidad de nodos en la lista: "<< cantNodos<<endl;
}

void ListaEnlazadaSimple::instrucciones() {

    cout << "Escriba una de las siguientes opciones: \n"
         << " 1 para insertar al inicio de la lista\n"
         << " 2 para insertal al final de la lista\n"
         << " 3 para eliminar del principio de la lista\n"
         << " 4 para eliminar del final de la lista\n"
         << " 5 para finalizar la lista\n";
}
