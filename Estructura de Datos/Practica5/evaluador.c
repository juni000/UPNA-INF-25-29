/**
 *	MODULO: Evaluador
 *	FICHERO: Evaluador.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 25/04/24.
 *  DESCRIPCION: Este modulo recoge todas las implementaciones
 *  definidas sobre el tipo Evaluador.
 */
 
#include "evaluador.h"


/**
 * ACCION: eval
 * ENTRADA: Una pila de enteros y un operador
 * REQUISITOS: La pila esta inicializada y no vacia
 * SALIDA: la pila evaluada
 */
void eval(PilaDeEnteros * p, Operador op){
	int v1, v2;
	
	cimaPilaDeEnteros(*p, &v1);
	desapilarPilaDeEnteros(p);
	cimaPilaDeEnteros(*p, &v2);
	desapilarPilaDeEnteros(p);
	if (op == suma){
		v1 = v2+v1;
	}
	else if (op == resta){
		v1 = v2-v1;
	}
	else if (op == producto){
		v1 = v2*v1;
	}
	else if (op == division){
		v1 = v2/v1;
	}
	apilarPilaDeEnteros(p, v1);
	
}

/**
 * ACCION: evaluaPolonesa
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion debe estar bien escrita y no vacia
 * SALIDA: Evalua la expresion en notacion postfija
 */
int evaluaPolonesa(Expresion e){
	Simbolo x;
	int v;
	PilaDeEnteros p;
	nuevaPilaDeEnteros(&p);
	while(!expresionVacia(e)){
		primerSimbolo(e, &x);
		if (esOperador(x)){
			eval(&p, operador(x));
		}
		else{
			apilarPilaDeEnteros(&p, valor(x));
		}
		eliminaSimbolo(&e);
	}
	cimaPilaDeEnteros(p, &v);
	return v;
}
