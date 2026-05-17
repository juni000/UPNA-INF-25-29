/**
 *	MODULO: Controles
 *	FICHERO: controles.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Coordina la simulacion del trafico.
 */
#include "controles.h"
#include <stdio.h>
#include "ruleta.h"
void iniciarControles(Control *c){
    int tmedio;
    tmedio = -1;
    //El tiempo medio entre llegadas de coches debe ser un numero positivo, por lo que se pide al usuario que introduzca un valor valido en caso de que el valor introducido sea menor o igual a 0.
    while (tmedio <= 0){
        printf("Introduce el tiempo medio entre llegadas de coches (debe ser un numero positivo): \n");
        scanf("%d", &tmedio);
        if (tmedio <= 0){
            printf("El tiempo medio entre llegadas de coches debe ser un numero positivo. Por favor, introduce un valor valido.\n");
        }
    }
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
void mostrarResultados(Control c){
    mostrarResultadosPeaje(c.peaje);
}
