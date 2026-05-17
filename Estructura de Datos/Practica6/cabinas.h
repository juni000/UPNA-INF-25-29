/**
 *	MODULO: Cabinas
 *	FICHERO: cabinas.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Define la interfaz de las cabinas.
 */
#ifndef CABINAS_H
#define CABINAS_H
#include "colaDeEnteros.h"
#include "reloj.h"
typedef struct Cabina {
    int nCoches; // coches esperando en la cabina
    int maxCoches; // maximo de coches esperando
    int servidos; // coches servidos
    int totalEsperado; // tiempo total de esperas
    int proxServ; // instante proximo servicio
    int minServ; // tiempo mínimo del servicio
    int maxServ; // tiempo máximo del servicio
    ColaDeEnteros colaCoches; // cola de coches
} Cabina;
void iniciarCab(Cabina *c, int tmin, int tmax);
void encolarCoche(Cabina *c, Reloj r);
int cuantosCoches(Cabina c);
void servCabina(Cabina *c, Reloj r);
void mostrarResultadosCabina(Cabina c, int *totalServidos, int *totalEsperado);
#endif
