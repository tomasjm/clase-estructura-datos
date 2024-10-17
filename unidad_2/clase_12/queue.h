//
// Created by Tomás Jiménez on 17-10-24.
//

#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"
struct Queue {
    int internal_ptr = 0;
    int size = 0;
    LinkedList* head;
    bool isEmpty() {
        return (this->internal_ptr == 0);
    }
    bool isFull() {
        return (this->internal_ptr == this->size);
    }
    void enqueue(int valor) {
        if (this->isFull()) {
            return;
        }
        if (this->isEmpty()) {
            this->head = new LinkedList(valor);
        } else {
            this->head->insertar(valor);
        }
        this->internal_ptr++;
    }
    int dequeue() {
        if (this->isEmpty()) {
            return NULL;
        }
        Nodo* first_in = this->head;
        Nodo* following_node = this->head->obtener(1);
        this->head = (LinkedList*)following_node;
        this->internal_ptr--;
        return first_in->valor;
    }
    Queue(int size) {
        this->size = size;
    }
};
#endif //QUEUE_H
