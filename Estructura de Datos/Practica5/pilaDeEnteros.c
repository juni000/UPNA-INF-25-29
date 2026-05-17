/**
 *	MODULO: pilaDeEnteros
 *	FICHERO: pilaDeEnteros.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 04/03/19.
 * DESCRIPCION: Este módulo exporta la funcionalidad necesaria para implementar
 * 	una pila ints. Utiliza una implementacion estática contigua. El tipo es
 * 	asignable
 *
 *  Este fichero se crea sólo con intenciones de coordinación docente y como
 *	 ayuda a sus alumnos. El autor desautoriza expresamente su difusión, copia
 *  o exhibición pública (salvo entre los alumnos de la asignatura 240204 del
 *	 grado en Ingeniería Informática de la UPNA).
 */
#include "pilaDeEnteros.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * ACCION: nuevaPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de enteros sin elementos
 */
void nuevaPilaDeEnteros(PilaDeEnteros *p){
	p->cima=-1;
}
/**
 * ACCION: error
 *	REQUISITOS:
 * SALIDA: Para la ejecución tras informar de un error
 */
void errorPilaDeEnteros(char s[]){
	printf("\n\n\nERROR en el módulo pilas: %s \n", s);
	while (true)
		exit(-1);
}
/**
 * ACCION: llena
 *	REQUISITOS:
 * SALIDA: Devuelve verdadero si la pila está llena
 */
bool llenaPilaDeEnteros(PilaDeEnteros p){
	return (p.cima == TAMANIO_PILA_DE_ENTEROS -1);
}
/**
 * ACCION: apilarPilaDeEnteros
 * ENTRADA: una pila de enteros y un entero
 *	REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el entero como la cima de la pila
 */
void apilarPilaDeEnteros(PilaDeEnteros *p, int x){
	if (llenaPilaDeEnteros(*p))
		errorPilaDeEnteros("Apilando en una pila de enteros llena.");
	p->cima++;
	p->valores[p->cima]=x;
}
/**
 * ACCION: desapilarPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeEnteros(PilaDeEnteros *p){
	if (esNulaPilaDeEnteros(*p))
		errorPilaDeEnteros("Desapilando en una pila de enteros vacia.");
	p->cima--;
}
/**
 * ACCION: cimaPilaDeEnteros
 * ENTRADA: una pila de enteros y un entero
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en elentero el elemento más nuevo de la pila
 */
void cimaPilaDeEnteros (PilaDeEnteros p, int *x){
	if (esNulaPilaDeEnteros(p))
		errorPilaDeEnteros("Cima en una pila de enteros vacia.");
	*x = p.valores[p.cima];
}
/**
 * ACCION: esNulaPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeEnteros (PilaDeEnteros p){
	return (p.cima == -1);
}

