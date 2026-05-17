#ifndef PILA_DE_TElem_H
#define PILA_DE_TElem_H
#include <stdbool.h>
/* Dimensión máxima del array */
#define TAMANIO_PILA_DE_TElem 100


/**
 * Definición del tipo PilaDeTElem
 */
typedef int TElem;// Tipo de los elementos de la pila (Puede ser cualquier tipo de dato, esta puesto int como ejemplo)
typedef struct pilaDeTElem{
	int cima; /// Desplazamiento para alcanzar el elemento de la cima
	TElem valores[TAMANIO_PILA_DE_TElem];
} PilaDeTElem;

/**
 * ACCION: nuevaPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de TElem sin elementos
 */
void nuevaPilaDeTElem(PilaDeTElem *);
/**
 * ACCION: apilarPilaDeTElem
 * ENTRADA: una pila de TElem y un entero
 *	REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el entero como la cima de la pila
 */
void apilarPilaDeTElem(PilaDeTElem *, TElem);
/**
 * ACCION: desapilarPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeTElem(PilaDeTElem *);
/**
 * ACCION: cimaPilaDeTElem
 * ENTRADA: una pila de TElem y un entero
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en elentero el elemento más nuevo de la pila
 */
void cimaPilaDeTElem(PilaDeTElem, TElem *);
/**
 * ACCION: esNulaPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeTElem(PilaDeTElem);
#endif
