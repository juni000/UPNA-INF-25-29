#ifndef EXPRESION_H
#define EXPRESION_H
/**
 *	MODULO: Expresion
 *	FICHERO: Expresion.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 18/04/24.
 *  DESCRIPCION: Este modulo recoge todas las operaciones
 *  definidas sobre el tipo Expresion.
 */
 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "simbolos.h"
#define TAMANIO_EXPRESION 100

/**
 * Definición del tipo expresion
 */
typedef struct expresion{
	int i, f;
	Simbolo valores[TAMANIO_EXPRESION];
}Expresion;

/**
 * ACCION: expresionNula
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion no esta inicializada
 * SALIDA: Crea una expresion e sin elementos
 */
 void expresionNula(Expresion *);
 
/**
 * ACCION: aniadeSimbolo
 * ENTRADA: Una expresion y un simbolo
 * REQUISITOS: La expresion esta inicializada y no esta llena
 * SALIDA: Añade el simbolo a la expresion
 */
 void aniadeSimbolo(Expresion *, Simbolo);
 
/**
 * ACCION: eliminaSimbolo
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada y no esta vacia
 * SALIDA: Elimina el primer simbolo de la expresion
 */
 void eliminaSimbolo(Expresion *);
 
/**
 * ACCION: primerSimbolo
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada y no esta vacia
 * SALIDA: x, el primer simbolo de la expresion
 */
void primerSimbolo(Expresion, Simbolo *);

/**
 * ACCION: expresionVacia
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada
 * SALIDA: un booleano que devuelve true si la expresion esta vacia
 */
 bool expresionVacia(Expresion);
 #endif //EXPRESION_H
