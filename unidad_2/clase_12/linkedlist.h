//
// Created by Tomás Jiménez on 16-10-24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>

struct Nodo {
    int valor;
    Nodo *next;
    Nodo(int valor) {
        this->valor = valor;
        this->next = nullptr;
    }
};

struct LinkedList : Nodo {
    // devuelve el valor si lo encuentra o null
    Nodo* obtener(int indice) {
        int i = 0;
        Nodo *nodo=this; // head
        while (nodo != nullptr) {
            if (indice == i) {
                return nodo;
            }
            nodo = nodo->next;
            i++;
        }
        return nullptr;
    }
    // devuelve el indice en donde se encuentra el valor
    int encontrar(int valor) {
        int i = 0;
        Nodo *nodo=this;
        while (nodo != nullptr) {
            if (valor == nodo->valor) {
                return i;
            }
            nodo = nodo->next;
            i++;
        }
        return -1;
    }
    // elimina el nodo en el indice respectivo
    bool eliminar(int indice) {
        Nodo* antes = this->obtener(indice-1);
        Nodo* despues = this->obtener(indice+1);
        if (antes == NULL) {
            return false;
        }
        antes->next = despues;
        return true;
    }
    // ... resto
    void imprimir() {
        int i = 0;
        for(Nodo *nodo=this; nodo != nullptr; nodo = nodo->next, i++) {
            printf("El valor del nodo %d es %d \n", i, nodo->valor);
        }
    }
    void insertar(int valor) {
        Nodo* ptr = this;
        for (; ptr->next != nullptr; ptr=ptr->next);
        Nodo* nodo_nuevo = new Nodo(valor);
        ptr-> next = nodo_nuevo;
    }
    LinkedList(int valor) : Nodo(valor){}
};

#endif //LINKEDLIST_H
