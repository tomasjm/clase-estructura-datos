#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divisores(int n, int lista[n]);
void divisor(int n, int d, int lista[n]);
void divisor_2(int n, int d, int* pContador);
bool es_primo(int n);
void vocales_a_mayusculas(char* texto, int indice);
void cadena_inversa(char* texto, char* buffer_inverso, int indice);

int main() {
    int lista[10] = {0};
    int cantidad_divisores = divisores(10, lista);
    int *pCant_div = new int;
    *pCant_div = 0;
    divisor_2(10,10, pCant_div);
    bool res  = es_primo(2);
    bool res1 = es_primo(3);
    bool res2 = es_primo(5);
    bool res3 = es_primo(7);
    bool res4 = es_primo(11);
    bool res5 = es_primo(13);
    const char* texto_const = "hola\0";
    char texto[1024] = {0}, texto_inverso[1024] = {0};
    strcpy(texto, texto_const);
    strcpy(texto_inverso, texto_const);
    vocales_a_mayusculas(texto, 0);
    cadena_inversa(texto, texto_inverso, 0);
    return 0;
}

void divisor(int n, int d, int lista[n]) {
    if (n%d == 0) {
        printf("%d es divisor de %d\n", d, n);
        lista[d-1] = d;
    }
    if (d == 1) {
        return; // caso base
    } else {
        divisor(n, d-1, lista); // caso recursivo
    }
}

void divisor_2(int n, int d, int *pContador) {
    if (n%d == 0) {
        printf("%d es divisor de %d\n", d, n);
        *pContador = *pContador + 1;
    }
    if (d == 1) {
        return; // caso base
    } else {
        divisor_2(n, d-1, pContador); // caso recursivo
    }
}
int divisores(int n, int lista[n]) {
    divisor(n,n, lista);
    int contador = 0;
    for (int i=0; i<n; i++) {
        if (lista[i] != 0) {
            contador++;
        }
    }
    return contador;
}

bool es_primo(int n) {
    //int lista[n] = {0}; // funcionará?
    int *lista = (int*)malloc(sizeof(int)*n);
    if (divisores(n, lista) == 2) {
        return true;
    } else {
        return false;
    }
    // se puede simplificar lo anterior a:
    return (divisores(n, lista) == 2);
}


void vocales_a_mayusculas(char *texto, int indice) {
    if (texto[indice] == 'a' ||
        texto[indice] == 'e' ||
        texto[indice] == 'i' ||
        texto[indice] == 'o' ||
        texto[indice] == 'u') {
            texto[indice] = texto[indice]-32;
        }
    if (texto[indice] == '\0') {
        return;
    } else {
        vocales_a_mayusculas(texto, indice+1);
    }
}

void cadena_inversa(char *texto, char* buffer_inverso, int indice) {
    int largo_texto = 0;
    for (; texto[largo_texto] != '\0'; largo_texto++);
    buffer_inverso[largo_texto-indice-1] = texto[indice];
    if (indice == largo_texto) {
        buffer_inverso[largo_texto+1] = '\0';
        return;
    }
    cadena_inversa(texto, buffer_inverso, indice+1);
}

