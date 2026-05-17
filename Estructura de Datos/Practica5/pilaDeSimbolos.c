/**
 *	MODULO: pilaDeSimbolos
 *	FICHERO: pilaDeSimbolos.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 18/04/24.
 *  DESCRIPCION: Este modulo recoge todas las implementaciones
 *  definidas sobre el tipo pilaDeSimbolos. Utiliza una 
 * 	implementación contigua. El tipo es asignable.
 */

#include "pilaDeSimbolos.h"

/**
 * ACCION: nuevaPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de simbolos sin elementos
 */
void nuevaPilaDeSimbolos(PilaDeSimbolos * p){
	p->cima=-1;
}

/**
 * ACCION: error
 * REQUISITOS:
 * SALIDA: Para la ejecución tras informar de un error
 */
void errorPilaDeSimbolos(char s[]){
	printf("\n\n\nERROR en el módulo pilas: %s \n", s);
	while (true){
		exit(-1);
	}
}
/**
 * ACCION: llena
 * REQUISITOS:
 * SALIDA: Devuelve verdadero si la pila está llena
 */
bool llenaPilaDeSimbolos(PilaDeSimbolos p){
	return (p.cima == TAMANIO_PILA_DE_SIMBOLOS -1);
}

/**
 * ACCION: apilarPilaDeSimbolos
 * ENTRADA: una pila de simbolos y un simbolo
 * REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el simbolo como la cima de la pila
 */
void apilarPilaDeSimbolos(PilaDeSimbolos * p, Simbolo x){
	if (llenaPilaDeSimbolos(*p)){
		errorPilaDeSimbolos("Apilando en una pila de simbolos llena.");
	}
	p->cima++;
	p->valores[p->cima] = x;
}

/**
 * ACCION: desapilarPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeSimbolos(PilaDeSimbolos * p){
	if (esNulaPilaDeSimbolos(*p)){
		errorPilaDeSimbolos("Desapilando en una pila de simbolos vacia.");
	}
	p->cima--;
}

/**
 * ACCION: cimaPilaDeSimbolos
 * ENTRADA: una pila de simbolos y un simbolo
 * REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en el simbolo,  el elemento más nuevo de la pila
 */
void cimaPilaDeSimbolos(PilaDeSimbolos p, Simbolo * x){
	if (esNulaPilaDeSimbolos(p)){
		errorPilaDeSimbolos("Cima en una pila de simbolos vacia.");
	}
	*x = p.valores[p.cima];
}

/**
 * ACCION: esNulaPilaDeSimbolos
 * ENTRADA: una pila de simbolos
 * REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeSimbolos(PilaDeSimbolos p){
	return (p.cima == -1);
}
