#ifndef FFF_COLA_DE_ENTEROS_H
#define FFF_COLA_DE_ENTEROS_H
#include <stdbool.h>
typedef struct nodoDeColaDeEnteros {
    struct nodoDeColaDeEnteros *s;
    int e;
} NodoDeColaDeEnteros;

typedef struct colaDeEnteros {
    NodoDeColaDeEnteros *i;
    NodoDeColaDeEnteros *f;
} ColaDeEnteros;

void nuevaColaDeEnteros(ColaDeEnteros *);
void pideTurnoColaDeEnteros(ColaDeEnteros *, int);
void avanceColaDeEnteros(ColaDeEnteros *);
void primeroColaDeEnteros(ColaDeEnteros, int *);
bool esNulaColaDeEnteros(ColaDeEnteros);
#endif