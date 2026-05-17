/**
 *	MODULO: Cabinas
 *	FICHERO: cabinas.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Gestiona las cabinas y sus servicios.
 */
#include "cabinas.h"
#include <stdio.h>
#include "ruleta.h"
void iniciarCab(Cabina *cab, int tmin, int tmax){
    cab->nCoches = 0;
    cab->maxCoches = 0;
    cab->servidos = 0;
    cab->totalEsperado = 0;
    cab->proxServ = 0;
    cab->minServ = tmin;
    cab->maxServ = tmax;
    nuevaColaDeEnteros(&cab->colaCoches);
}
void contarCoche(Cabina *cab, Reloj r){
    if (cab->nCoches == 0){
        cab->proxServ = instante(r) + distribucionLineal(cab->minServ, cab->maxServ);
    }
    cab->nCoches++;
    if (cab->nCoches > cab->maxCoches){
        cab->maxCoches = cab->nCoches;
    }
}
void encolarCoche(Cabina *cab, Reloj r){
    contarCoche(cab, r);
    pideTurnoColaDeEnteros(&cab->colaCoches, instante(r));
}
int cuantosCoches(Cabina cab){
    return cab.nCoches;
}
void servCabina(Cabina *cab, Reloj r){
    int x;
    if (cab->proxServ == instante(r)){
        cab->servidos++;
        primeroColaDeEnteros(cab->colaCoches, &x);
        avanceColaDeEnteros(&cab->colaCoches);
        cab->totalEsperado = cab->totalEsperado + (instante(r) - x);
        cab->nCoches--;
        if (cab->nCoches == 0){
            cab->proxServ = 0;
        }else{
            cab->proxServ = instante(r) + distribucionLineal(cab->minServ, cab->maxServ);
        }
    }
}

void mostrarResultadosCabina(Cabina c, int *totalServidos, int *totalEsperado){
    float esperaMedia;
    printf("Coches Servidos: %d \n", c.servidos);
    printf("Tiempo Total de Espera: %d \n", c.totalEsperado);
    if(c.servidos == 0){
        esperaMedia = 0;
    }else{
        esperaMedia = (float) c.totalEsperado / c.servidos;
    }
    printf("Espera Media: %f \n", esperaMedia);
    printf("Maximo de Coches en Cola: %d \n", c.maxCoches);
    *totalServidos += c.servidos;
    *totalEsperado += c.totalEsperado;
}
