#ifndef COLA_DE_TElem_H
#define COLA_DE_TElem_H
#include <stdbool.h> 
typedef char TElem; ///TElem es el elemento que se va a usar en la cola.

/**
 * Definición del tipo ColaDeTElem dinamica
 */
typedef struct nodoDeColaDeTElem {
	TElem	 e;
	struct nodoDeColaDeTElem *s;
} NodoDeColaDeTElem;
typedef struct colaDeTElem{
	NodoDeColaDeTElem *i;
	NodoDeColaDeTElem *f;
} ColaDeTElem;

/**
 * ACCION: nuevaColaDeTElem
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola no está inicializada
 * SALIDA: Inicializa la cola como una cola de TElem sin elementos
 */
void nuevaColaDeTElem(ColaDeTElem *);

/**
 * ACCION: pideTurnoColaDeTElem
 * ENTRADA: una cola de TElem y un TElem
 * REQUISITOS: la cola está inicializada y no está llena
 * MODIFICA: Añade el TElem a la cola
 */
void pideTurnoColaDeTElem(ColaDeTElem *, TElem);

/**
 * ACCION: avanceColaDeTElem
 * ENTRADA: una cola de Telem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más antiguo de la cola
 */
void avanceColaDeTElem(ColaDeTElem *);

/**
 * ACCION: primeroColaDeTElem
 * ENTRADA: una cola de TElems y un TElem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Copia en el TElem,  el elemento más antiguo de la cola
 */
void primeroColaDeTElem(ColaDeTElem, TElem *);

/**
 * FUNCION: esNulaColaDeTElem
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola está inicializada
 * SALIDA: Devuelve true si la cola está vacía
 */
bool esNulaColaDeTElem(ColaDeTElem);
#endif
