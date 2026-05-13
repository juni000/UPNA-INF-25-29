#ifndef CONTROLES_H
#define CONTROLES_H
#include "reloj.h"
#include "peajes.h"
#include "cabinas.h"
#include "ruleta.h"
typedef struct Frecuencia{
    int tLlegada;
    int tMedio;
} Frecuencia;

typedef struct Control{
    Peaje peaje;
    Frecuencia trafico;
} Control;

void iniciarControles(Control *c, int tmedio);
void llegaCoche(Control *c, Reloj r);
void marcharCoche(Control *c, Reloj r);
#endif
