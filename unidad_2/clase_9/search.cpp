#include "search.h"
#include <stdio.h>

int linear_search(int *lista, int size, int n) {
    for (unsigned long i=0; i<size; i++) {
        if (lista[i] == n) {
            printf("Linear search tomó %d ejecuciones\n", i+1);
            return n;
        }
    }
    return NULL;
}

int binary_search(int *lista, int size, int n) {
    int lim_inf = 0;
    int lim_sup = size-1;
    unsigned long i = 0 ;
    while (1) {
        i++;
        int pivote = lim_inf + (lim_sup - lim_inf)/2;
        int num_pivote = lista[pivote];
        if (num_pivote == n) {
            printf("Binary search tomó %d ejecuciones\n", i);
            return pivote;
        }
        if (num_pivote < n) {
            lim_inf = pivote+1;
        } else {
            lim_sup = pivote-1;
        }

    }
}
