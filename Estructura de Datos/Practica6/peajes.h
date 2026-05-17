/**
 *	MODULO: Peajes
 *	FICHERO: peajes.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Define la interfaz del peaje.
 */
#ifndef PEAJE_H
#define PEAJE_H

#include "reloj.h"
#define NCAB 5 // Número de cabinas
#include "cabinas.h"

typedef Cabina Peaje[NCAB];

/*
 * Inicia el peaje
 */
void iniciarPeaje(Peaje *p);

/*
 * Encola un nuevo coche en una cabina
 */
void guardaCola(Peaje *p, int ncab, Reloj r);

/*
 * Elige cabina entre las tres menos ocupadas
 */
int eligeCabina(Peaje p);

/*
 * Simula una ronda de servicio de las cabinas
 */
void rondaCabinas(Peaje *p, Reloj r);

/*
 * Muestra los resultados de cada cabina
 */
void mostrarResultadosPeaje(Peaje p);

#endif
