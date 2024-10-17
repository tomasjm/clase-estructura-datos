//
// Created by Tomás Jiménez on 17-10-24.
//

#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"
struct Stack {
    int internal_ptr = 0;
    int size;
    LinkedList *head;
    void push(int valor) {
        if (this->isFull()) {
            return;
        }
        if (this->isEmpty()) {
            this->head = new LinkedList(valor);
        } else {
            this->head->insertar(valor);
        }
        this->internal_ptr++;
    };
    int pop() {
        if (this->isEmpty()) {
            return NULL;
        }
        Nodo* last_node = this->head->obtener(this->internal_ptr-1);
        if (this->internal_ptr == 1) {
            this->head = NULL;
        } else {
            this->head->eliminar(this->internal_ptr-1);
        }
        this->internal_ptr--;
        return last_node->valor;
    }
    bool isFull() {
        return (this->internal_ptr == this->size);
    }
    bool isEmpty() {
        return (this->internal_ptr == 0);
    }
    Stack(int size) {
        if (size <= 0) {
            this->size = 1;
        } else {
            this->size = size;
        }

    }
};
#endif //STACK_H
