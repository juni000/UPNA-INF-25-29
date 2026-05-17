#include "PilaDinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * ACCION: nuevaPilaDeTElem
 * ENTRADA: una pila de TElem
 * REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de TElem sin elementos
 */
void nuevaPilaDeTElem(PilaDeTElem *p){
	p=NULL;
}

/**
 * ACCION: errorPilaDeTElem
 * ENTRADA: una cadena de caracteres s[]
 * REQUISITOS: ninguno
 * SALIDA: Imprime un mensaje de error y termina el programa
 */
void errorPilaDeTElem(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
	while (true)
		exit(-1);
}

/**
 * ACCION: apilarPilaDeTElem
 * ENTRADA: una pila de TElem y un elemento x
 * REQUISITOS: ninguno
 * SALIDA: Añade el elemento x a la pila
 */
void apilarPilaDeTElem(PilaDeTElem *p, TElem x){
	NodoDeTElem * q;
	q = malloc(sizeof(TElem));
	q->e = x;
	q->s = *p;
	*p = q;
}

/**
 * ACCION: desapilarPilaDeTElem
 * ENTRADA: una pila de TElem
 * REQUISITOS: la pila no está vacía
 * SALIDA: Elimina el elemento en la cima de la pila
 */
void desapilarPilaDeTElem(PilaDeTElem *p){
	if (esNulaPilaDeTElem(*p))
	{
		errorPilaDeTElem("Desapilando en una pila de TElem vacia.");
	}
	NodoDeTElem * q;
	q = *p;
	*p = (*p)->s;
	free(q);
}

/**
 * ACCION: cimaPilaDeTElem
 * ENTRADA: una pila de TElem y un puntero a TElem x
 * REQUISITOS: la pila no está vacía
 * SALIDA: Asigna el valor del elemento en la cima de la pila a x
 */
void cimaPilaDeTElem (PilaDeTElem p, TElem *x){
	if (esNulaPilaDeTElem(p))
	{
		errorPilaDeTElem("Cima en una pila de TElem vacia.");
	}
	*x = p->e;
}

/**
 * FUNCION: esNulaPilaDeTElem
 * ENTRADA: una pila de TElem
 * REQUISITOS: ninguno
 * SALIDA: Devuelve true si la pila está vacía, false en caso contrario
 */
bool esNulaPilaDeTElem (PilaDeTElem p)
{
	return (p == NULL);
}
