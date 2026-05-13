#ifndef PEAJE_H
#define PEAJE_H

#include "reloj.h"
#define NCAB 5 // Número de cabinas
#include "cabinas.h"

typedef struct Peaje{
    Cabina cabinas[NCAB];
}Peaje;

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
int eligeCabina(const Peaje *p);

/*
 * Simula una ronda de servicio de las cabinas
 */
void rondaCabinas(Peaje *p, Reloj r);

#endif