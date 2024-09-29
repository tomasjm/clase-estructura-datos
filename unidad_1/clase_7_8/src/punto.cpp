#include "punto.h"
#include <math.h>

float distancia(Punto p1, Punto p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
