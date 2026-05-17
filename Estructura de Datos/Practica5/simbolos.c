/**
 *	MODULO: simbolos
 *	FICHERO: simbolos.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 04/03/19.
 * DESCRIPCION: Este módulo crea el concepto de simbolo. Un simbolo permite
 *		almacenar un dato entero junto con su valor o un operador
 *
 *  Este fichero se crea sólo con intenciones de coordinación docente y como
 *	 ayuda a sus alumnos. El autor desautoriza expresamente su difusión, copia
 *  o exhibición pública (salvo entre los alumnos de la asignatura 240204 del
 *	 grado en Ingeniería Informática de la UPNA).
 */
#include "simbolos.h"
/**
 * ACCION: hazOperando
 * ENTRADA: un entero
 * SALIDA: Devuelve un simbolo que representa el operando representado por el
 * 	entero que se recibe de entrada
 */
void hazOperador(Operador x, Simbolo *s){
	s->esOperador= true;
	s->valor = (int) x;
}
/**
 * ACCION: esOperador
 * ENTRADA: un simbolo
 * SALIDA: Devuelve verdadero si y sólo si el simbolo representa un operador
 */
void hazOperando(int x, Simbolo *s){
	s->esOperador= false;
	s->valor = x;
}
/**
 * ACCION: operador
 * ENTRADA: un simbolo
 * SALIDA: Devuelve el operador almacenado en el símbolo
 */
bool esOperador(Simbolo s){
	return s.esOperador;
}
/**
 * ACCION: operador
 * ENTRADA: un simbolo
 * SALIDA: Devuelve el operador almacenado en el símbolo
 */
char operador(Simbolo s){
	return (char) s.valor;
}
/**
 * ACCION: operando
 * ENTRADA: un simbolo
 * SALIDA: Devuelve el operando almacenado en el símbolo
 */
int valor(Simbolo s){
	return s.valor;
}
