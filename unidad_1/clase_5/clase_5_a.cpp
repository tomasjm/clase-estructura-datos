#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototipos
int sumar(int a, int b);
bool es_par(int a);
int max(int *numeros, int tam); // pueden hacerlo con 3
int sum(int *numeros, int tam);
void divisores(int n, int *buffer_lista_divisores);
bool es_primo(int n);
char upper(char c);
void to_uppercase(char *texto);

int main() {
  int lista[3] = {5, 6, 7};
  int res = sumar(1, 2);         // res = 3
  bool res1 = es_par(2);         // true
  int max_lista = max(lista, 3); // 7
  int sum_lista = sum(lista, 3); // 18
  int lista_divisores[24];
  divisores(24, lista_divisores); // [1, 0, 3];
  bool primo = es_primo(18);      // true
  char *texto = (char *)malloc(5 * sizeof(char));
  char *texto_constante = "hola\0";
  strcpy(texto,
         texto_constante); // (dest, source), C no deja mutar la linea 24, por
                           // lo tanto hay que hacer un "workaround" para mover
                           // la constante a la variable texto, otra alternativa
                           // es usar scanf directamente
  to_uppercase(
      texto);  // prueba pasando como argumento la variable text_constante
  free(texto); // siempre hay que liberar la memoria cuando se llama malloc
               // "buena práctica"
  return 0;
}
int sumar(int a, int b) { return a + b; }
bool es_par(int a) {
  int resto = a % 2;
  bool es_par_b = resto == 0; // qué valores toma?
  // es_par_b toma true o false
  return (a % 2 == 0); // directo: true o false
}

int max(int numeros[], int tam) {
  int max_numero = numeros[0];
  for (int i = 1; i < tam; i++) {
    if (numeros[i] > max_numero)
      max_numero = numeros[i];
  }
  return max_numero;
}
int sum(int *numeros, int tam) {
  int a_sum = 0;
  for (int i = 0; i < tam; i++) {
    a_sum += numeros[i];
  }
  return a_sum;
}
/* devuelve una lista de n elementos,
 * en donde las casillas
 * distinto de 0, son sus divisores */
void divisores(int n, int *buffer_lista_divisores) {
  for (int i = n - 1; i >= 0;
       i--) {               // itero desde n-1 hasta 0 para acceder al array
    if (n % (i + 1) == 0) { // i+1 ya que quiero comprobar los numeros desde n
                            // hasta 1 (descendente){
      buffer_lista_divisores[i] = i + 1;
    } else {
      buffer_lista_divisores[i] = 0;
    }
  }
  // devuelve una lista con los divisores cuando el elemento es distinto de 0
}

bool es_primo(int n) {
  int lista_divisores[n];
  divisores(n, lista_divisores);
  int n_divisores = 0;
  for (int i = 0; i < n; i++) {
    if (lista_divisores[i] != 0) {
      n_divisores++;
    }
  }
  // es primo solo si es divisible por 1 y por si mismo
  return (n_divisores <= 2);
}

char upper(char c) {
  return (char)((int)c - 32); // casting!
}

void to_uppercase(char *texto) {
  if (texto == NULL) {
    printf("Error: puntero nulo.\n");
    return;
  }
  for (int i = 0; texto[i] != '\0'; i++) {
    texto[i] = upper(texto[i]);
  }
}
