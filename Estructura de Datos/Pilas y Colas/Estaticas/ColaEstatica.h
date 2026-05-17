#ifndef COLA_DE_TELEM_H
#define COLA_DE_TELEM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANIO_DE_COLA_DE_TELEM 100
typedef int TElem;

/**
 * Definición del tipo ColaDeTElem estatica
 */
typedef struct ColaDeTElem{
	int primero;
    int ultimo;
    TElem t[TAMANIO_DE_COLA_DE_TELEM];
}ColaDeTElem;

/**
 * ACCION: ColaDeTElemNula
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola no está inicializada
 * SALIDA: Inicializa la cola como una cola de TElem sin elementos
 */
void ColaDeTElemNula  (ColaDeTElem *);

/**
 * FUNCION: ColaDeTElemVacia
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola está inicializada
 * SALIDA: Devuelve true si la cola está vacía
 */
bool ColaDeTElemVacia (ColaDeTElem);

/**
 * ACCION: AvanzarColaDeTElem
 * ENTRADA: una cola de Telem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más antiguo de la cola
 */
void AvanzarColaDeTElem (ColaDeTElem *);

/**
 * ACCION: PideTurnoColaDeTElem
 * ENTRADA: una cola de TElem y un TElem
 * REQUISITOS: la cola está inicializada y no está llena
 * MODIFICA: Añade el TElem a la cola
 */
void PideTurnoColaDeTElem (ColaDeTElem*,  TElem);

/**
 * ACCION: PrimeroColaDeTElem
 * ENTRADA: una cola de TElems y un TElem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Copia en el TElem,  el elemento más antiguo de la cola
 */
void PrimeroColaDeTElem (ColaDeTElem, TElem*);
#endif
