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
} Cabina;;
void iniciarCabina(Cabina *c, int tmin, int tmax);
void encolarCoche(Cabina *c, Reloj r);
int cuantosCoches(Cabina c);
void servCabina(Cabina *c, Reloj r);
#endif