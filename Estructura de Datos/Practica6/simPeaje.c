#define TSIM 10800
#include <stdio.h>
#include "controles.h"
#include "peajes.h"
#include "cabinas.h"
#include "reloj.h"
void iniciarSimulacion(Control *c, int tmedio){
    iniciarRuleta();
    iniciarControles(c, tmedio);
}

void siguienteIteracion(Control *c, Reloj r){
    llegaCoche(c, r);
    marcharCoche(c, r);
}
void main(){
    Control c;
    Reloj r;
    int tmedio;
    printf("Introduce el tiempo medio entre llegadas de coches: \n");
    tmedio = 60;
    //scanf("%d", &tmedio);
    aCero(&r);
    iniciarSimulacion(&c, tmedio);
    while (instante(r) != TSIM){
        tic(&r);
        siguienteIteracion(&c, r);
    }
    mostrarResultados(c.peaje);
    
}
