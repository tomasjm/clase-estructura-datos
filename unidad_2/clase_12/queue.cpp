#include "queue.h"

int main() {
    Queue *queue = new Queue(3);
    queue->enqueue((5));
    queue->enqueue((4));
    queue->enqueue((3));
    int cinco  = queue->dequeue();
    int cuatro = queue->dequeue();
    int tres   = queue->dequeue();
    return 0;
}
