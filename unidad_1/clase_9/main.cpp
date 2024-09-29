#include <stdio.h>
#include "search.h"
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000000
void rellenar_lista(int *lista, int size) {
    for (int i = 1; i<=size; i++) {
        lista[i-1] = i;
    }
}

int main() {
    int *lista =(int*) malloc(sizeof(int)*ARRAY_SIZE);
    rellenar_lista(lista, ARRAY_SIZE);
    clock_t start = clock();
    linear_search(lista, ARRAY_SIZE, ARRAY_SIZE);
    clock_t stop = clock();
    double elapsed = (double) (stop-start)/CLOCKS_PER_SEC;
    printf("Tiempo que tomó linear search: %.5f\n", elapsed);
    clock_t start2 = clock();
    binary_search(lista, ARRAY_SIZE, ARRAY_SIZE);
    clock_t stop2 = clock();
    double elapsed2 = (double) (stop2-start2)/CLOCKS_PER_SEC;
    printf("Tiempo que tomó binary search: %.5f\n", elapsed2);
    free(lista);
    return 0;
}