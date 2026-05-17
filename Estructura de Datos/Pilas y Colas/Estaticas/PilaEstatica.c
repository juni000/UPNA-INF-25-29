#include "PilaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * ACCION: nuevaPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de TElem sin elementos
 */
void nuevaPilaDeTElem(PilaDeTElem *p){
	p->cima=-1;
}
/**
 * ACCION: error
 *	REQUISITOS:
 * SALIDA: Para la ejecución tras informar de un error
 */
void errorPilaDeTElem(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
	while (true)
		exit(-1);
}
/**
 * ACCION: llena
 *	REQUISITOS:
 * SALIDA: Devuelve verdadero si la pila está llena
 */
bool llenaPilaDeTElem(PilaDeTElem p){
	return (p.cima == TAMANIO_PILA_DE_TElem -1);
}
/**
 * ACCION: apilarPilaDeTElem
 * ENTRADA: una pila de TElem y un entero
 *	REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el entero como la cima de la pila
 */
void apilarPilaDeTElem(PilaDeTElem *p, TElem x){
	if (llenaPilaDeTElem(*p))
		errorPilaDeTElem("Apilando en una pila de TElem llena.");
	p->cima++;
	p->valores[p->cima]=x;
}
/**
 * ACCION: desapilarPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeTElem(PilaDeTElem *p){
	if (esNulaPilaDeTElem(*p))
		errorPilaDeTElem("Desapilando en una pila de TElem vacia.");
	p->cima--;
}
/**
 * ACCION: cimaPilaDeTElem
 * ENTRADA: una pila de TElem y un entero
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en elentero el elemento más nuevo de la pila
 */
void cimaPilaDeTElem (PilaDeTElem p, TElem *x){
	if (esNulaPilaDeTElem(p))
	{
		errorPilaDeTElem("Cima en una pila de TElem vacia.");
	}
	*x = p.valores[p.cima];
}
/**
 * ACCION: esNulaPilaDeTElem
 * ENTRADA: una pila de TElem
 *	REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeTElem (PilaDeTElem p){
	return (p.cima == -1);
}

