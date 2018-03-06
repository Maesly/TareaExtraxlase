//
// Created by maesly on 01/03/18.
//
#include "ListaCircular.h"
using namespace std;
/**
 * @brief Funcion que se encarga de validar si la lista se encuentra vacía
 * */
bool ListaCircular::esVacia() {
    return cabeza == NULL;
}

/**
 * @brief Funcion que inserta un nodo al inicio de la lista
 * @param entrada Dato que llevará el nodo insertado
 * */
void ListaCircular::insertarAlinicio(Dato entrada) {
    NodoCircular* nuevo;
    nuevo = new NodoCircular(entrada);

    if(esVacia()){
        cabeza = nuevo;
        cabeza->ponerSiguiente(nuevo);
        final = nuevo;
        cantidadNodos++;
    }else{
        nuevo->ponerSiguiente(cabeza);
        cabeza = nuevo;
        final->ponerSiguiente(cabeza);
        cantidadNodos++;
    }
}
/**
 * @brief Funcion que inserta nodos al final de la lista
 * @param entrada Dato que llevará el nodo que se inserte
 * */
void ListaCircular::insertarAlfinal(Dato entrada) {

    NodoCircular* nuevo;
    nuevo = new NodoCircular(entrada);

    if(esVacia()){
        cabeza = nuevo;
        cabeza->ponerSiguiente(nuevo);
        final = nuevo;
        cantidadNodos++;
    }else{
        final->ponerSiguiente(nuevo);
        nuevo->ponerSiguiente(cabeza);
        final = nuevo;
        cantidadNodos++;
    }
}
/**
 * @brief Funcion que inserta un nodo en cualquier posicion de la lista
 * @param entrada Dato que llevará el nodo que se insertará
 * @param posicion Posicion en la lista en la que se insertará el nodo
 * */
void ListaCircular::insertar(Dato entrada, int posicion) {


    NodoCircular* nuevo;
    nuevo = new NodoCircular(entrada);

    int cont = 0;

    if(esVacia()){
        cabeza = nuevo;
        cabeza->ponerSiguiente(nuevo);
        final = nuevo;
        cantidadNodos++;

    }else if (cont == posicion){
        insertarAlinicio(entrada);

    } else if(posicion == cantidadNodos){
        insertarAlfinal(entrada);

    }else if(posicion > cantidadNodos){
        cout <<"Error de indice\n";

    }else{
        NodoCircular* temp = cabeza;
        NodoCircular* temp2 = cabeza->siguiente();
        while(cont != posicion-1){
            cont++;
            temp = temp->siguiente();
            temp2 = temp2->siguiente();
        }
        nuevo->ponerSiguiente(temp2);
        temp->ponerSiguiente(nuevo);
        cantidadNodos++;

    }

}
/**
 * @brief Funcion que se encarga de eliminar el primer nodo de la lista
 * */
void ListaCircular::eliminarAlinicio() {

    if (esVacia()) {
        cout << "Error, no hay nodos en la lista";

    } else {
        NodoCircular *temp = cabeza;     //Crea el puntero temp y lo posiciona al inicio de la lista
        cabeza = temp->siguiente();    //Elimina el primer nodo
        final->ponerSiguiente(cabeza);
        cantidadNodos--;
        delete (temp);

    }
}
/**
 * @brief Funcion que elimina un nodo al final de la lista
 * */
void ListaCircular::eliminarAlfinal() {
    NodoCircular* temp= cabeza;
    NodoCircular* temp2= cabeza->siguiente();

    if(esVacia()){
        cout << "Error, la lista se encuentra vacía";
    }else{

        while(temp->siguiente() != final){
            temp = temp->siguiente();
            temp2 = temp2->siguiente();
        }
        temp->ponerSiguiente(temp2->siguiente());
        final = temp;
        cantidadNodos--;

    }delete(temp2);

}

/**
 * @brief Funcion que se encarga de eliminar un nodo en cualquier posicion
 * @param posicion Con este dato la funcion elimina el elemento en la posicion ingresada
 * */
void ListaCircular::eliminar(Dato posicion) {

    NodoCircular* temp = cabeza;
    NodoCircular* temp2 = cabeza->siguiente();
    int cont = 0;

    if(esVacia()){
        cout << "Error, la lista se encuentra vacía\n";

    }else if(cont == posicion){
        eliminarAlinicio();
    }else if( posicion == cantidadNodos){
        eliminarAlfinal();
    }else if(posicion > cantidadNodos-1){
        cout << "Error de índice\n";
    } else{
        while (cont != posicion-1){
            cont++;
            temp = temp->siguiente();
            temp2 = temp2->siguiente();
        }
        temp->ponerSiguiente(temp2->siguiente());
        cantidadNodos--;
        delete(temp2);
    }
}
/**
 * @brief Funcion que se encarga de buscar un nodo en la lista
 * @param dato El dato que se busca en la lista
 * */
void ListaCircular::buscar(int dato) {

    NodoCircular* temp = cabeza;

    int i = 0;

    if(esVacia()){
        cout << "Lo sentimos, el elemento no se encuentra en la lista\n";
    }else{

        while (temp->siguiente() != final->siguiente() && temp->datoNodo() != dato){
            temp= temp->siguiente();
            i++;
        }
        if(temp->datoNodo() == dato){
            cout << "\nEl elemento "<< dato<< " esta en la posición: "<<i<< "\n";
        }
        else{
            cout<<"\nLo sentimos, el elemento no se encuentra en la lista\n";
        }
    }
}
/**
 * @brief Funcion que cambia el dato de un nodo en la lista
 * @param dato Dato por el cual se cambiará un nodo
 * @param posicion Nodo en el cual se editará el dato
 * */
void ListaCircular::editarPosicion(Dato dato, int posicion) {

    NodoCircular* temp = cabeza;
    int c = 0;

    if(esVacia()){
        cout<< "Error, no hay elementos en la lista.\n";

    }else if(posicion > cantidadNodos-1){
        cout<< "No existe elemento en esa posicion\n";
    }
    else{

        while ((temp->siguiente() != final->siguiente()) && (c < posicion)){
            temp = temp->siguiente();
            c++;
        }
        temp->dato = dato;
        cout << "El nodo en la posicion: "<<posicion<<", se cambio por: " << dato<< " con exito\n";

    }

}
/**
 * @brief Funcion que se encarga de visitar todos los nodos e imprimirlos en consola
 * */
void ListaCircular::imprimirLista() {

    NodoCircular* temp = cabeza;
    int nodos = 0;

    if(esVacia()){
        cout <<"Lo siento la lista esta vacía\n";
    }else{
        while (nodos != cantidadNodos){

            cout <<"->"<< temp->datoNodo()<<"\t";
            cout <<"-> Apunta a: "<< temp->siguiente()<<"\t";
            cout <<"-> Esta en: "<< temp<<"\n";

            temp = temp->siguiente();
            nodos++;
        }
        cout << "Cabeza "<<cabeza<<"\n";
        cout << "final "<< final<< "\n";
        cout <<"Cantidad de nodos en la lista: " <<cantidadNodos<< "\n";
    }
}