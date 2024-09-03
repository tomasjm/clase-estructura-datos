#include <stdio.h>

int main() {
    char texto[1024];
    printf("Ingrese un texto\n");
    scanf("%[^\n]", texto);
    int l;
    for (l =0; texto[l] != '\0'; l++);
    printf("Largo del texto es %d caracteres\n", l);

    char texto2[1024];
    fflush(stdin);
    printf("Ingrese otro texto\n");
    scanf("%[^\n]", texto2);
    int l2; // largo de texto 2
    for (l2 =0; texto2[l2] != '\0'; l2++);
    int diff = 0;
    for (int i = 0; texto[i] != 0; i++) {
        for (int j = 0; texto[j] != 0; j++) {
            diff += (int)texto[i] - (int)texto[j];
        }
    }
    if (diff == 0 && l == l2) {
        printf("Los textos son iguales \n");
    } else {
        printf("Los textos no son iguales \n");
    }

    // capitalizar el 2do string
    texto2[0] = (int)texto2[0] - 32;
    printf("capitalizado: %s\n", texto2);
    return 0;
}
