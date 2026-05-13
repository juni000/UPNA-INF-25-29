#include "controles.h"


void iniciarControles(Control *c, int tmedio){
    c->trafico.tMedio = tmedio;
    c->trafico.tLlegada = distribucionExponencial(c->trafico.tMedio);
    iniciarPeaje(&c->peaje);
}
void llegaCoche(Control *c, Reloj r){
    int n;
    if (instante(r) == c->trafico.tLlegada){
        n = eligeCabina(&c->peaje);
        guardaCola(&c->peaje, n, r);
        c->trafico.tLlegada = instante(r) + distribucionExponencial(c->trafico.tMedio);
    }
}
void marcharCoche(Control *c, Reloj r){
    rondaCabinas(&c->peaje, r);
}
