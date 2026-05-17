/**
 *	MODULO: Ruleta
 *	FICHERO: ruleta.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Define la interfaz de funciones aleatorias.
 */
#ifndef RULETA_H
#define RULETA_H


void iniciarRuleta();
int distribucionExponencial(int media);
int distribucionLineal(int max, int min);
int eleccionCon3Probabilidades(float maxp, float medp, float minp);
#endif
