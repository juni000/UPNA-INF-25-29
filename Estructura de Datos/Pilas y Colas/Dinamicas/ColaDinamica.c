#include "ColaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Acción: muestra un mensaje de error y termina el programa
 * Entrada: una cadena de caracteres que representa el mensaje de error
 * Salida: imprime un mensaje de error y termina el programa
 */
void errorColaDeTelem(char s[])
{
	printf("\n\n\nERROR en el modulo colas: %s \n", s);
	while (true)
	{
		exit(-1);
	}
}

/**
 * Acción: inicializa una cola de TElem vacía
 * Entrada: una cola de TElem
 * Requisitos: la cola no está inicializada
 * Salida: la cola se inicializa sin elementos
 */
void nuevaColaDeTElem(ColaDeTElem *c)
{
	c->i = NULL;
	c->f = NULL;
}

/**
 * Acción: agrega un elemento al final de la cola
 * Entrada: una cola de TElem y un elemento TElem a agregar
 * Requisitos: la cola debe estar inicializada
 * Salida: añade un elemento al final de la cola
 */
void pideTurnoColaDeTElem(ColaDeTElem *c, TElem x)
{
	NodoDeColaDeTElem *q;
	if ((q = malloc(sizeof(NodoDeColaDeTElem)))==NULL)
	{
		errorColaDeTelem("no hay memoria para pideTurno");
	}
	q->e = x;
	q->s = NULL;
	if (c->f == NULL)
	{
		c->i = q;
	}
	else
	{
		c->f->s=q;
	}
	c->f=q;
}

/**
 * Función: verifica si la cola está vacía
 * Entrada: una cola de TElem
 * Salida: un valor booleano que indica si la cola está vacía (true) o no (false)
 */
bool esNulaColaDeTElem (ColaDeTElem c)
{
	return (c.i == NULL);
}

/**
 * Acción: avanza al siguiente elemento de la cola
 * Entrada: una cola de TElem
 * Requisitos: la cola no debe estar vacía
 * Salida: elimina un elemneto de la cola
 */
void avanceColaDeTElem(ColaDeTElem *c){
	NodoDeColaDeTElem * q;
	if (esNulaColaDeTElem(*c))
	{
		errorColaDeTElem("avanzando en cola nula");
	}
	q= c->i;
	c->i = c->i->s;
	if (c->i == NULL)
	{
		c->f = NULL;
	}
	free(q);
}

/**
 * Acción: obtiene el primer elemento de la cola
 * Entrada: una cola de TElem
 * Salida: el primer elemento de la cola
 */
void primeroColaDeTElem (ColaDeTElem c, TElem *x)
{
	if (esNulaColaDeTElem(c))
	{
		errorColaDeTElem("primero en cola nula");
	}
	*x = c.i->e;
}
