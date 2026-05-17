/**
 *	MODULO: operadores
 *	FICHERO: operadores.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 05/03/19.
 * DESCRIPCION: Este módulo exporta la funcionalidad necesaria para trabajar
 * 	con los conceptos de precedencia dentro de un parser de precedencia
 *		de operador que permite funciones de precedencia
 *
 *  Este fichero se crea sólo con intenciones de coordinación docente y como
 *	 ayuda a sus alumnos. El autor desautoriza expresamente su difusión, copia
 *  o exhibición pública (salvo entre los alumnos de la asignatura 240204 del
 *	 grado en Ingeniería Informática de la UPNA).
 */
// Este modulo se implementa definiendo dos variables globales. Va en contra de
// la correcta modularización pero permite ejemplificar las macros funcionales
// y la iniciación de tablas
char precizq []={2,2,4,4,0,6,0};
char precder []={1,1,3,3,5,0,0};
