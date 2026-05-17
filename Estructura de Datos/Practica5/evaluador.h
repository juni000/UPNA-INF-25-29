#ifndef EVALUADOR_H
#define EVALUADOR_H
/**
 *	MODULO: Evaluador
 *	FICHERO: Evaluador.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 25/04/24.
 *  DESCRIPCION: Este modulo recoge todas las operaciones
 *  definidas sobre el tipo Evaluador.
 */
 
#include "expresion.h"
#include "pilaDeEnteros.h"
#include "operadores.h"
#include "simbolos.h"

/**
 * ACCION: evaluaPolonesa
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion debe estar bien escrita y no vacia
 * SALIDA: Evalua la expresion en notacion postfija
 */
int evaluaPolonesa(Expresion);

 #endif //EVALUADOR_H

