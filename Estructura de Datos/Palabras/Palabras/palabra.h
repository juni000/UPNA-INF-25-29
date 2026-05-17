#ifndef palabras
#define palabras
#include <stdbool.h>
#include <stdio.h>
#define MAX 100

typedef char TablaDeCaracteres[MAX];

typedef struct palabra {
    int longi;
    TablaDeCaracteres letras;
} palabra;

/**
 * ACCIÓN: prepararPalabra
 * ENTRADA: p, una palabra inicializada a 0 letras
 * REQUISITOS: -
 * SALIDA: -
 * DESCRIPCIÓN: Esta acción inicializa una palabra con 0 letras.
 */
void prepararPalabra(palabra *p);

/**
 * ACCIÓN: agregarCaracter
 * ENTRADA: p, un puntero a una palabra; c, un caracter a agregar
 * REQUISITOS: p debe ser una palabra válida
 * SALIDA: -
 * DESCRIPCIÓN: Esta acción agrega un caracter a una palabra existente.
 */
void agregarCaracter(palabra *p, char c);

/**
 * FUNCIÓN: modificarCaracter
 * ENTRADA: p, un puntero a una palabra; i, la posición del caracter a modificar; c, el nuevo caracter
 * REQUISITOS: p debe ser una palabra válida; i debe ser una posición válida en la palabra
 * SALIDA: -
 * DESCRIPCIÓN: Esta función modifica un caracter en una palabra existente en la posición especificada.
 */
void modificarCaracter(palabra *p, int i, char c);

/**
 * FUNCIÓN: consultarCaracter
 * ENTRADA: p, una palabra; i, la posición del caracter a consultar
 * REQUISITOS: p debe ser una palabra válida; i debe ser una posición válida en la palabra
 * SALIDA: el caracter en la posición especificada de la palabra
 * DESCRIPCIÓN: Esta función devuelve el caracter en la posición especificada de una palabra.
 */
char consultarCaracter(palabra p, int i);

/**
 * FUNCIÓN: longitudPalabra
 * ENTRADA: p, una palabra
 * REQUISITOS: p debe ser una palabra válida
 * SALIDA: la longitud de la palabra
 * DESCRIPCIÓN: Esta función devuelve la longitud de una palabra.
 */
int longitudPalabra(palabra p);

/**
 * FUNCIÓN: esPalabraVacia
 * ENTRADA: p, una palabra
 * REQUISITOS: p debe ser una palabra válida
 * SALIDA: true si la palabra está vacía, false de lo contrario
 * DESCRIPCIÓN: Esta función verifica si una palabra está vacía.
 */
bool esPalabraVacia(palabra p);

/**
 * FUNCIÓN: sonPalabrasIguales
 * ENTRADA: p1, una palabra; p2, otra palabra
 * REQUISITOS: p1 y p2 deben ser palabras válidas
 * SALIDA: true si las palabras son iguales, false de lo contrario
 * DESCRIPCIÓN: Esta función verifica si dos palabras son iguales.
 */
bool sonPalabrasIguales(palabra p1, palabra p2);

/**
 * ACCIÓN: leerPalabra
 * ENTRADA: f, un puntero a un archivo; p, un puntero a una palabra
 * REQUISITOS: f debe ser un archivo válido; p debe ser una palabra válida
 * SALIDA: -
 * DESCRIPCIÓN: Esta acción lee una palabra desde un archivo y la guarda en la variable p.
 */
void leerPalabra(FILE *f, palabra *p);

/*
 *  FUNCION: escribirPalabra
 *	ENTRADA: f, fichero de caracter y p, una palabra
 *  REQUISITOS:
 *  MODIFICA: f, añadiendo la palabra p al final de f
 */
void escribirPalabra(FILE * f, palabra p);

/*
 * ACCION: infoPalabra
 * ENTRADA: p, una palabra
 * REQUISITOS:
 * SALIDA: Escribe en pantalla la palabra p
 */
void muestraPalabra(palabra p);

/*
 * ACCION: copiarPalabra
 * ENTRADA: p, una palabra
 * REQUISITOS:
 * SALIDA: q, una palabra que es copia de p
 */
void copiarPalabra(palabra p, palabra * q);
#endif