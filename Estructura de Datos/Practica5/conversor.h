#ifndef CONVERSOR_H
#define CONVERSOR_H
/**
 *	MODULO: Conversor
 *	FICHERO: Conversor.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 25/04/24.
 *  DESCRIPCION: Este modulo recoge todas las operaciones
 *  definidas sobre el tipo Conversor.
 */
 

#include <string.h>
#include "expresion.h"
#include "pilaDeSimbolos.h"
#include "operadores.h"
#include "simbolos.h"

typedef char Cadena[100];

/**
 * ACCION: trasformaPolonesa
 * ENTRADA: Una cadena
 * REQUISITOS: La cadena debe estar bien escrita y no vacia
 * SALIDA: Devuelve la expresion en postfija
 */
void transformaPolonesa(Cadena, Expresion *);
 #endif //CONVERSOR_H


