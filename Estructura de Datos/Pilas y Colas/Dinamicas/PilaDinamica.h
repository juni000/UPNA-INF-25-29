#ifndef PILA_DE_TElem_H
#define PILA_DE_TElem_H
#include <stdbool.h>
/**
 * 
 */

/**
 * Definición del tipo PilaDeTElem dinamica
 */
typedef int TElem;
typedef struct nododeTElem{
	TElem e;
	struct nododeTElem *s;
}NodoDeTElem;

typedef NodoDeTElem *PilaDeTElem;

/**
 * ACCION: nuevaPilaDeTElem
 * ENTRADA: una pila de TElem
 * REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de TElem sin elementos
 */
void nuevaPilaDeTElem(PilaDeTElem *);

/**
 * ACCION: apilarPilaDeTElem
 * ENTRADA: una pila de TElem y un TElem
 * REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el TElem como la cima de la pila
 */
void apilarPilaDeTElem(PilaDeTElem *, TElem);

/**
 * ACCION: desapilarPilaDeTElem
 * ENTRADA: una pila de TElem
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeTElem(PilaDeTElem *);

/**
 * ACCION: cimaPilaDeTElem
 * ENTRADA: una pila de TElem y un TElem
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en el TElem el elemento más nuevo de la pila
 */
void cimaPilaDeTElem(PilaDeTElem , TElem *);


/**
 * ACCION: esNulaPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeTElem(PilaDeTElem );
#endif
