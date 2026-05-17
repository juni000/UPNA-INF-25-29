#ifndef PILA_DE_SIMBOLOS_H
#define PILA_DE_SIMBOLOS_H
/**
 *	MODULO: pilaDeSimbolos
 *	FICHERO: pilaDeSimbolos.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 18/04/24.
 *  DESCRIPCION: Este modulo recoge todas las operaciones
 *  definidas sobre el tipo pilaDeSimbolos. Utiliza una 
 * 	implementación contigua. El tipo es asignable.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "simbolos.h"
#define TAMANIO_PILA_DE_SIMBOLOS 100

/**
 * Definición del tipo PilaDeSimbolos
 */
typedef struct PilaDeSimbolos{
	int cima; 
	Simbolo valores[TAMANIO_PILA_DE_SIMBOLOS];
} PilaDeSimbolos;


/**
 * ACCION: nuevaPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de simbolos sin elementos
 */
void nuevaPilaDeSimbolos(PilaDeSimbolos *);
/**
 * ACCION: apilarPilaDeSimbolos
 * ENTRADA: una pila de simbolos y un simbolo
 * REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el simbolo como la cima de la pila
 */
void apilarPilaDeSimbolos(PilaDeSimbolos *, Simbolo);
/**
 * ACCION: desapilarPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeSimbolos(PilaDeSimbolos *);
/**
 * ACCION: cimaPilaDeSimbolos
 * ENTRADA: una pila de simbolos y un simbolo
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en el simbolo,  el elemento más nuevo de la pila
 */
void cimaPilaDeSimbolos(PilaDeSimbolos, Simbolo *);
/**
 * ACCION: esNulaPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeSimbolos(PilaDeSimbolos);
#endif //PILA_DE_SIMBOLOS_H
