#ifndef PALABRAS_H
#define PALABRAS_H
#include <stdio.h>
#include <stdbool.h>
#define MAX 100
typedef struct Palabra{
    char c[MAX];
    long longitud;
} Palabra;
/**
 * @brief Prepara una palabra para ser utilizada.
 * @param p Puntero a la palabra a preparar.
 */
void prepararPalabra(Palabra *p);
void agregarCaracter(Palabra *p, char c);
void modificarCaracter(Palabra *p,int i, char c);
char consultarCaracter(Palabra *p,int i);
long longitudPalabra(Palabra *p);
bool esPalabraVacia(Palabra *p);
bool sonPalabrasIguales(Palabra *p1, Palabra *p2);
void leerPalabra(FILE *f, Palabra *p);
#endif