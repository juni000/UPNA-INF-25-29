/**
 *	MODULO: Controles
 *	FICHERO: controles.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Define la interfaz del control.
 */
#ifndef CONTROLES_H
#define CONTROLES_H
#include "reloj.h"
#include "peajes.h"
typedef struct Frecuencia{
    int tLlegada;
    int tMedio;
} Frecuencia;

typedef struct Control{
    Peaje peaje;
    Frecuencia trafico;
} Control;

void iniciarControles(Control *c);
void llegaCoche(Control *c, Reloj r);
void marcharCoche(Control *c, Reloj r);
void mostrarResultados(Control c);
#endif
