/**
 *	MODULO: Reloj
 *	FICHERO: reloj.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Define el tipo reloj y su interfaz.
 */
#ifndef RELOJ_H
#define RELOJ_H
typedef int Reloj;
void aCero(Reloj *r);
void tic(Reloj *r);
int instante(Reloj r);
#endif
