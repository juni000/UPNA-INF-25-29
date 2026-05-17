/**
 *	MODULO: simbolos
 *	FICHERO: simbolos.h
 *	VERSION: 1.1.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 04/03/19.
 * DESCRIPCION: Este módulo crea el concepto de simbolo. Un simbolo permite
 *		almacenar un dato entero junto con su valor o un operador
 * HISTORICO: Mayo 2020-> se pone de acuerdo con el código de la práctica. La
 *				función operando pasa a ser valor
 *
 *  Este fichero se crea sólo con intenciones de coordinación docente y como
 *	 ayuda a sus alumnos. El autor desautoriza expresamente su difusión, copia
 *  o exhibición pública (salvo entre los alumnos de la asignatura 240204 del
 *	 grado en Ingeniería Informática de la UPNA).
 */
#ifndef FFF_SIMBOLOS_H
#define FFF_SIMBOLOS_H
//Headers necesarios para la compilación
#include <stdbool.h>
#include "operadores.h"
/**
 * Definición del tipo simbolo
 */
typedef struct simbolo {
	int valor;
	int esOperador;
} Simbolo;
// Prototipos de la funcionalidad exportada
/**
 * ACCION: hazOperador
 * ENTRADA: un entero
 * SALIDA: Devuelve un simbolo que representa el operador representado por el
 * 	entero que se recibe de entrada
 */
void hazOperador(Operador, Simbolo *);
/**
 * ACCION: hazOperando
 * ENTRADA: un entero
 * SALIDA: Devuelve un simbolo que representa el operando representado por el
 * 	entero que se recibe de entrada
 */
void hazOperando(int, Simbolo *);
/**
 * ACCION: esOperador
 * ENTRADA: un simbolo
 * SALIDA: Devuelve verdadero si y sólo si el simbolo representa un operador
 */
bool esOperador(Simbolo);
/**
 * ACCION: operador
 * ENTRADA: un simbolo
 * SALIDA: Devuelve el operador almacenado en el símbolo
 */
char operador(Simbolo);
/**
 * ACCION: operando
 * ENTRADA: un simbolo
 * SALIDA: Devuelve el operando almacenado en el símbolo
 */
int valor(Simbolo);
#endif // FFF_SIMBOLOS_H
