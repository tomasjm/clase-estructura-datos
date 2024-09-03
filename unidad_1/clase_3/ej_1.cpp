#include <stdio.h>
#include <stdlib.h>
int main(){
    int n_elementos = 0;
    printf("Ingrese el número de elementos:\n");
    scanf("%d", &n_elementos);
    int *lista_ptr = (int *)malloc(n_elementos * sizeof(int));
    int *inicio_lista = lista_ptr;
    for(int i = 0; i < n_elementos; i++){
        printf("Ingrese el elemento %d:\n", i);
        scanf("%d", lista_ptr);
        lista_ptr++; // CAMBIAMOS LA DIRECCION DE MEMORIA
    }
    lista_ptr = inicio_lista; // DEVOLVEMOS EL PUNTERO AL INICIO
    for(int i = 0; i < n_elementos; i++){
        printf("Elemento %d: %d\n", i+1, *lista_ptr);
        lista_ptr++;
    }
    free(inicio_lista); // hay que darle la direccion de memoria de inicio
}
