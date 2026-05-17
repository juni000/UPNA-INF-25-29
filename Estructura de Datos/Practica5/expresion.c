/**
 *	MODULO: Expresion
 *	FICHERO: Expresion.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 18/04/24.
 *  DESCRIPCION: Este modulo recoge todas las implementaciones
 *  definidas sobre el tipo Expresion.
 */
 
 #include "expresion.h"
 
 /**
 * ACCION: expresionNula
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion no esta inicializada
 * SALIDA: Crea una expresion e sin elementos
 */
void expresionNula(Expresion * e){
	e->i = 0;
	e->f = 0;
}

/**
 * ACCION: error
 * REQUISITOS:
 * SALIDA: Para la ejecución tras informar de un error
 */
void errorExpresion(char s[]){
	printf("\n\n\nERROR en el módulo expresion: %s \n", s);
	while (true){
		exit(-1);
	}
}

/**
 * ACCION: llena
 * REQUISITOS:
 * SALIDA: Devuelve verdadero si la expresion está llena
 */
bool llenaExpresion(Expresion e){
	return (e.i == (e.f + 1) % TAMANIO_EXPRESION);
}

/**
 * ACCION: aniadeSimbolo
 * ENTRADA: Una expresion y un simbolo
 * REQUISITOS: La expresion esta inicializada y no esta llena
 * SALIDA: Añade el simbolo a la expresion
 */
void aniadeSimbolo(Expresion * e, Simbolo a){
	if (llenaExpresion(*e)){
		errorExpresion("Apilando en una expresion llena.");
	}
	e->valores[e->f] = a;
	e->f = e->f % TAMANIO_EXPRESION + 1;
}

/**
 * ACCION: eliminaSimbolo
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada y no esta vacia
 * SALIDA: Elimina el primer simbolo de la expresion
 */
void eliminaSimbolo(Expresion * e){
	if (expresionVacia(*e)){
		errorExpresion("Desapilando en una expresion vacia.");
	}
	e->i = e->i % TAMANIO_EXPRESION + 1;
}

/**
 * ACCION: primerSimbolo
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada y no esta vacia
 * SALIDA: x, el primer simbolo de la expresion
 */
void primerSimbolo(Expresion e, Simbolo * a){
	*a = e.valores[e.i];
}

/**
 * ACCION: expresionVacia
 * ENTRADA: Una expresion
 * REQUISITOS: La expresion esta inicializada
 * SALIDA: un booleano que devuelve true si la expresion esta vacia
 */
bool expresionVacia(Expresion e){
	bool b;
	b = (e.i == e.f);
	return b ;
}

 
