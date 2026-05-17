#ifndef FFF_OPERADORES_H
#define FFF_OPERADORES_H
/**
 *	MODULO: operadores
 *	FICHERO: operadores.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Federico Fariña Figueredo el 04/03/19.
 * DESCRIPCION: Este módulo exporta la funcionalidad necesaria para trabajar
 * 	con los conceptos de precedencia dentro de un parser de precedencia
 *		de operador que permite funciones de precedencia
 *
 *  Este fichero se crea sólo con intenciones de coordinación docente y como
 *	 ayuda a sus alumnos. El autor desautoriza expresamente su difusión, copia
 *  o exhibición pública (salvo entre los alumnos de la asignatura 240204 del
 *	 grado en Ingeniería Informática de la UPNA).
 */
// El tipo operador no es mas que un alias de un entero
typedef char Operador;
// Las funciones constantes se implementan mediante macros que devuelven
// el valor indicado
#define suma 0
#define resta 1
#define producto 2
#define division 3
#define parizqdo 4
#define pardcho 5
#define dolar 6
// Ejemplo de creación de macro funcional. Va bastante en contra de la correcta
// modularización pues exporta parte de la implementación, pero quería que lo
// vierais
#define precedenciaIzquierda(x) precizq[(x)]
#define precedenciaDerecha(x) precder[(x)]
// Ejemplo de declaración de una variable en un .h. Tampoco es muy correcto desde
// el punto de vista teórico. Informa de que en algún sitio (en el .c) se están
// definiendo estas dos variables. Las variables tienen que ser definidas como
// estáticas en donde se definan.
extern char precizq [];
extern char precder [];
#endif

