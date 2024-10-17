#include "stack.h"


struct QueueByStacks {
    Stack *s1 = new Stack(5);
    Stack *s2 = new Stack(5);
    void enqueue(int x) {
        while(!this->s1->isEmpty()) {
            this->s2->push(this->s1->pop());
        }
        this->s1->push(x);
        while(!this->s2->isEmpty()) {
            this->s1->push(this->s2->pop());
        }
    }
    int dequeue() {
        return this->s1->pop();
    }

};

int main() {
    QueueByStacks *queue = new QueueByStacks;
    queue->enqueue((5));
    queue->enqueue((4));
    queue->enqueue((3));
    int cinco  = queue->dequeue();
    int cuatro = queue->dequeue();
    int tres   = queue->dequeue();
    return 0;
}
