#ifndef FFF_PILA_DE_ENTEROS_H
#define FFF_PILA_DE_ENTEROS_H
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
	//Headers necesarios para la compilación
#include <stdbool.h>
/* Dimensión máxima del array */
#define TAMANIO_PILA_DE_ENTEROS 100
/**
 * Definición del tipo PilaDeEnteros
 */
typedef struct pilaDeEnteros{
	int cima; // Desplazamiento para alcanzar el elemento de la cima
	int valores[TAMANIO_PILA_DE_ENTEROS];
} PilaDeEnteros;
	// Prototipos de la funcionalidad exportada
/**
 * ACCION: nuevaPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila no está inicializada
 * SALIDA: Inicializa la pila como una pila de enteros sin elementos
 */
void nuevaPilaDeEnteros(PilaDeEnteros *);
/**
 * ACCION: apilarPilaDeEnteros
 * ENTRADA: una pila de enteros y un entero
 *	REQUISITOS: la pila está inicializada y no está llena
 * MODIFICA: Añade el entero como la cima de la pila
 */
void apilarPilaDeEnteros(PilaDeEnteros *, int);
/**
 * ACCION: desapilarPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más nuevo de la pila
 */
void desapilarPilaDeEnteros(PilaDeEnteros *);
/**
 * ACCION: cimaPilaDeEnteros
 * ENTRADA: una pila de enteros y un entero
 *	REQUISITOS: la pila está inicializada y no está vacía
 * MODIFICA: Copia en elentero el elemento más nuevo de la pila
 */
void cimaPilaDeEnteros(PilaDeEnteros, int *);
/**
 * ACCION: esNulaPilaDeEnteros
 * ENTRADA: una pila de enteros
 *	REQUISITOS: la pila está inicializada
 * SALIDA: Devuelve true si la pila está vacía
 */
bool esNulaPilaDeEnteros(PilaDeEnteros);
#endif //FFF_PILA_DE_ENTEROS_H
