//
// Created by maesly on 28/02/18.
//

#include "ListaEnlazadaDoble.h"
#include <iostream>

using namespace std;
/**
 * @brief Valida si la lista se encuentra vacia
 * */
bool ListaEnlazadaDoble::esVacia() {  //Valida si la lista esta vacía
    return cabeza == NULL;
}
/**
 * @brief Inserta un nodo antes de v
 * @param valor Dato que se insertará en el nuevo nodo
 * @param v Nodo posterior al que se desea insertar
 * */
void ListaEnlazadaDoble::insertar(Dato valor,Dato posicion) {

    NodoDoble* tempAnterior = cabeza;       //Posiciona puntero en la cabeza de la lista
    NodoDoble* tempSiguiente = cabeza->siguienteNodo(); //Posiciona puntero en el siguiente de la cabeza de la lista

    NodoDoble* nuevo;               //Crea el nodo a insertar
    nuevo = new NodoDoble(valor);

    int contPosicion = 0;

    if(esVacia()){          // Valida si la lista esta vacía
        cabeza = nuevo;
        nuevo->ponerAnterior(cabeza);
        nuevo->ponerSiguiente(cola);
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

    NodoDoble* nuevo;       //Crea el nuevo nodo a insertar en la lista
    nuevo = new NodoDoble(valor);

    if(esVacia() ){         //Valida si la lista se encuentra vacía
        cabeza = nuevo;
        nuevo->ponerAnterior(cabeza);
        nuevo->ponerSiguiente(cola);
        cantidadNodos++;
    }else{
        nuevo->ponerSiguiente(cabeza); //Inserta el nodo al inicio de la lista
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
        nuevo->ponerSiguiente(cola);       //Asigna el siguiente de nuevo como Null
        nuevo->ponerAnterior(temp);        //Asigna el anterior de nuevo como temp
        temp->ponerSiguiente(nuevo);       //Reasigna el ultimo nodo como el penultimo
        cantidadNodos++;
    }
}

/**
 * @brief Funcion que elimina un nodo en cualquier posicion de la lista
 * @param posicion Posicion de la lista que se desea eliminar
 *
 * */
void ListaEnlazadaDoble::eliminar(int posicion) {

    NodoDoble* nuevo = cabeza;          //Posiciona un puntero en la cabeza de la lista
    NodoDoble* nuevo2 = cabeza->siguiente;

    int cont = 0;

    if(esVacia()){          //Valida si la lista se encuentra vacia
        cout<<"Error, no hay elementos en la lista";

    }else if(posicion == cont){     //Si el nodo a eliminar es el primero
        eliminarAlInicio();
        cantidadNodos--;

    }else if(posicion > cantidadNodos-1){   //Valida si el nodo que se desea eliminar no existe en la lista
        cout <<"Error, no existe un nodo en esa posicion\n";

    }else if(posicion == cantidadNodos-1){ //Valida si el nodo a eliminar es el ultimo
        eliminarUltimo();

    }
    else{

        while(cont != posicion-1){      // Ciclo que recorre la lista hasta el nodo en la posicion a eliminar
            nuevo= nuevo->siguienteNodo();
            nuevo2 = nuevo2->siguienteNodo();
            cont++;
        }

        nuevo->ponerSiguiente(nuevo2->siguienteNodo());
        nuevo2->siguienteNodo()->ponerAnterior(nuevo);
        cout << "El nodo "<< cont +1 <<" que se eliminó exitosamente.\n";
        delete nuevo2;
    }
}

/**
 * @brief Funcion que elimina nodo al inicio de la lista
 *
 * */
void ListaEnlazadaDoble::eliminarAlInicio() {

    NodoDoble* temp = cabeza;       //Posiciona un puntero en la cabeza de la lista

    if(esVacia()){      //Valida si la lista se encuentra vacia
        cout << "Error, no hay nodos en la lista";
    } else{

        cabeza = temp->siguienteNodo();     //Cambia la cabeza al segundo nodo
        temp->ponerAnterior(cabeza);
        cantidadNodos--;

        cout << "El nodo 0 se eliminó exitosamente.\n";
        delete(temp);
    }
}
/**
 * @brief Funcion que elimina el ultimo nodo de la lista
 * */
void ListaEnlazadaDoble::eliminarUltimo() {

    NodoDoble* temp = cabeza;       //Posiciona un puntero en la cabeza de la lista
    NodoDoble* temp2 = cabeza->siguienteNodo();

    if(esVacia()){      //Valida si la lista se encuentra vacia
        cout << "Error, no hay nodos en la lista.";
    }else{

        while(temp2->siguienteNodo() != NULL){ //Ciclo que recorre la lista
            temp2 = temp2->siguienteNodo();
            temp = temp->siguienteNodo();

        }

        temp->ponerSiguiente(cola);
        cola = temp;
        delete temp2;
        cout << "El nodo "<< cantidadNodos <<" que se eliminó exitosamente.\n";
    }
}

/**
 * @brief Funcion que retorna la posicion en la que encuentra el dato buscado
 * @param dato Dato a buscar en la lista
 * */
void ListaEnlazadaDoble::obtenerPosicion(int dato) {

    NodoDoble* temp = cabeza;       //Posiciona un puntero en la cabeza de la lista
    int c = 0;

    if(esVacia()){                  //Valida si la lista se encuentra vacia
        cout <<"No hay elementos en la lista";
    }else{

        while ((temp->siguienteNodo()!= NULL) && (temp->datoNodo() != dato)){ //Ciclo que recorre la lista y valida si en caso de que no este en la lista
            temp = temp->siguienteNodo();
            c++;

        }if(temp->datoNodo() == dato){ //Encontró el elemento y retorna la posicion en la lista
            cout << "El elemento: "<< dato<< ", se encuentra en la posicion: "<< c <<"\n";

        }else{
            cout << "El elemento: " << dato<< " no se encuentra en la lista\n";
        }
    }

}

/**
 * @brief Funcion que cambia el dato que tiene un nodo
 * @param posicion Nodo que se desea editar
 * @param valor Dato por el que se va a editar el nodo
 * */
void ListaEnlazadaDoble::editarNodo(Dato valor, int posicion) {

    NodoDoble* temp = cabeza;
    int cont = 0;

    if(esVacia()){
        cout << "Lo sentimos, la lista se encuentra vacía.";
    } else if(posicion > cantidadNodos -1){
        cout << "No se encontró el nodo deseado";
    }else{
        while ((temp->siguienteNodo() != NULL) && (cont != posicion-1)){
            temp = temp->siguienteNodo();
            cont++;
        }
        temp->dato = valor;
        cout << "El nodo en la posicion: "<<posicion<<", se cambio por: " << valor<< " con exito\n";

    }

}
void ListaEnlazadaDoble::imprimirLista() {
    NodoDoble* n1 = cabeza;

    if( esVacia()){                  // Valida si l lista esta vacía
        cout<< "Lo siento, la lista se encuentra vacía\n"<<endl;
    }
    while(n1 != NULL){ // Ciclo que recorre la lista e imprime cada elemento
        cout <<"->"<< n1->datoNodo()<<"\t";
        //cout <<"->"<< n1<<"\n";
        n1 = n1->siguienteNodo();

    }
    //cout << "\nCantidad de nodos en la lista: "<< cantNodos<<endl;
}