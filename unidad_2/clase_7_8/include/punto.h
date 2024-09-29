#pragma once

#include <stdio.h>

struct Punto {
    float x;
    float y;
    void ingresar() {
        printf("Ingrese la coordenada x: ");
        scanf("%f", &x);
        printf("Ingrese la coordenada y: ");
        scanf("%f", &y);
    }
    void mostrar() {
        printf("Coordenada x: %f\n", x);
        printf("Coordenada y: %f\n", y);
    }
};

float distancia(Punto p1, Punto p2);