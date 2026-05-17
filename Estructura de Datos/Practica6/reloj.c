/**
 *	MODULO: Reloj
 *	FICHERO: reloj.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Implementa el reloj de simulacion.
 */
#include "reloj.h"

void aCero(Reloj *r){
    (*r) = 0;
}
void tic(Reloj *r){
    (*r) ++;
}
int instante(Reloj r){
    return r;
}
