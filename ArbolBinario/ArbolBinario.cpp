//
// Created by maesly on 06/03/18.
//
#include <cstdio>
#include "ArbolBinario.h"
/**
 * @brief Funcion para crear un nuevo nodo
 * @param n Dato que llevará el nodo creado
 * */
NodoArbol* ArbolBinario::crearNodo(int n,NodoArbol* padre) {
    NodoArbol* nuevo_nodo = new NodoArbol();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}
/**
 * @brief Funcion para insertar elementos en el arbol
 * @param
 * */
void ArbolBinario::insertarNodo(NodoArbol *& arbol, int n,NodoArbol* padre) {
    if(arbol == nullptr){ //Si el arbol esta vacio
        NodoArbol* nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    }else{ //Si el arbol tiene un nodo o mas
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq,n,arbol);
        }else{
            insertarNodo(arbol->der,n,arbol);
        }

    }
}

void ArbolBinario::eliminar(NodoArbol *arbol, int n) {
    if (arbol == NULL) {
        return;
    } else if (n < arbol->dato) {
        eliminar(arbol->izq, n);
    } else if (n > arbol->dato) {
        eliminar(arbol->der, n);
    }else{
        eliminarNodo(arbol);
    }
}
NodoArbol* ArbolBinario::minimo(NodoArbol *arbol) {

    if(arbol == NULL){
        return NULL;
    }
    if(arbol->izq){
        return minimo(arbol->izq);
    } else{
        return arbol;
    }
}

void ArbolBinario::reemplazar(NodoArbol *arbol, NodoArbol *nuevoNodo) {
    if(arbol->padre){
        if(arbol->dato == arbol->padre->izq->dato){
            arbol->padre->izq = nuevoNodo;
        } else if(arbol->dato == arbol->padre->der->dato){
            arbol->padre->der = nuevoNodo;
        }
    }
    if(nuevoNodo){
        nuevoNodo->padre = arbol->padre;
    }
}

void ArbolBinario::destruirNodo(NodoArbol *nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;

    delete nodo;
}

void ArbolBinario::eliminarNodo(NodoArbol *nodoEliminar) {

    if(nodoEliminar->izq && nodoEliminar->der){ ///Saber si el nodo tiene hijo izquierdo y derecho
        NodoArbol* menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    } else if(nodoEliminar->izq){ ///Si tiene hijo izquierdo
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    } else if(nodoEliminar->der){ ///Si tiene hijo derecho
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }else{ ///Si no tiene hijos
        reemplazar(nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
}



void ArbolBinario::mostrarArbol(NodoArbol *arbol, int cont) {
    if(arbol == NULL){
        return;
    }else{
        mostrarArbol(arbol->der,cont+1);
        for(int i = 0; i < cont;i++){
            cout << "   ";
        }
        cout << arbol->dato<< endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}
/*
void ArbolBinario::menu() {
    int dato,opcion;

    do{
        cout <<"\t.:MENU:."<<endl;
        cout <<"1. Insertar un nuevo nodo"<<endl;
        cout <<"2. Eliminar un nodo"<<endl;
        cout <<"3. Salir"<<endl;
        cout <<"Opcion: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Digite un numero: ";
                cin >> dato;
                insertarNodo(arbol,dato,NULL);
                cout << "\n";
                system("pause");
                break;
        }
        system("cls");
    }while (opcion!=3);
}*/