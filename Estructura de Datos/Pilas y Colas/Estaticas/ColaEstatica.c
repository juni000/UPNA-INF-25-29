#include "ColaEstatica.h"
#include <stdbool.h>

/**
 * ACCION: ColaDeTElemNula
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola no está inicializada
 * SALIDA: Inicializa la cola como una cola de TElem sin elementos
 */
void ColaDeTElemNula (ColaDeTElem *e)
{
    e->primero=0;
    e->ultimo=0;
}

/**
 * FUNCION: ColaDeTElemVacia
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola está inicializada
 * SALIDA: Devuelve true si la cola está vacía
 */
bool ColaDeTElemVacia (ColaDeTElem e)
{
    return(e.primero==e.ultimo);
}

/**
 * ACCION: errorColaDeTElem
 * ENTRADA: un mensaje de error
 * REQUISITOS: -
 * SALIDA: Imprime un mensaje de error y termina el programa
 */
void errorColaDeTElem(char s[]){
	printf("\n\n\nERROR en el módulo TElem: %s \n", s);
	while (true)
		exit(-1);
}

/**
 * FUNCION: llenaColaDeTElem
 * ENTRADA: una cola de TElem
 * REQUISITOS: la cola está inicializada
 * SALIDA: Devuelve true si la cola está llena
 */
bool llenaColaDeTElem(ColaDeTElem p)
{
	return ((p.primero)== (p.ultimo % TAMANIO_DE_COLA_DE_TELEM) + 1);
}

/**
 * ACCION: PideTurnoColaDeTElem
 * ENTRADA: una cola de TElem y un TElem
 * REQUISITOS: la cola está inicializada y no está llena
 * MODIFICA: Añade el TElem a la cola
 */
void PideTurnoColaDeTElem (ColaDeTElem *e, TElem s)
{
    if(llenaColaDeTElem(*e))
    {
        errorColaDeTElem("Cola llena");
    }
    e->t[e->ultimo] = s;
    e->ultimo=(e->ultimo % TAMANIO_DE_COLA_DE_TELEM) + 1;
}

/**
 * ACCION: AvanzarColaDeTElem
 * ENTRADA: una cola de Telem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Elimina el elemento más antiguo de la cola
 */
void AvanzarColaDeTElem (ColaDeTElem *e)
{

    if(ColaDeTElemVacia(*e))
    {
        errorColaDeTElem("cola Vacia");
    }
    e->primero= (e->primero % TAMANIO_DE_COLA_DE_TELEM)+1;
}

/**
 * ACCION: PrimeroColaDeTElem
 * ENTRADA: una cola de TElems y un TElem
 * REQUISITOS: la cola está inicializada y no está vacía
 * MODIFICA: Copia en el TElem,  el elemento más antiguo de la cola
 */
void PrimeroColaDeTElem (ColaDeTElem e, TElem *s)
{
    if(ColaDeTElemVacia(e))
    {
        errorColaDeTElem("cola Vacia");
    }
    *s = e.t[e.primero];
}
