#include <stdio.h>

int main() {
    int n, suma;
    printf("Ingrese cantidad N elementos a ingresar\n");
    scanf("%d", &n);
    int lista[n];
    for (int i = 0; i<n; i++) {
        int aux;
        printf("Ingrese numero %d\n", i);
        scanf("%d", &aux);
        lista[i] = aux;
        suma += aux;
    }
    printf("Suma: %d | Promedio: %.2f\n", suma, (float)suma/n);
    for (int i =0; i<n; i++) {
        int contador = 1;
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            if (lista[i] == lista[j]) {
                contador++;
            }
        }
        if (contador == 1) {
            printf("%d es unico\n", lista[i]);
        } else {
            printf("%d se repite %d veces\n", lista[i], contador);
        }
    }
    return 0;
}
