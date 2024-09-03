
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n_elementos = 0;
    printf("Ingrese el número de elementos:\n");
    scanf("%d", &n_elementos);
    int *lista_ptr = (int *)malloc(n_elementos * sizeof(int));
    for (int i = 0, *apuntador = lista_ptr; apuntador < lista_ptr + n_elementos; i++, apuntador++){
        printf("Ingrese un número %d\n", i+1);
        scanf("%d", apuntador);
    }
    for (int *apuntador = lista_ptr; apuntador < lista_ptr + n_elementos; apuntador++){
        printf("%d\n", *i);
    }
    free(lista_ptr);
}
