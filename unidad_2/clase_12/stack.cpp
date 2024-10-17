#include "stack.h"

int main()
{
    Stack *stack = new Stack(3);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    int tres = stack->pop();
    int dos = stack->pop();
    int uno = stack->pop();


    return 0;
}
