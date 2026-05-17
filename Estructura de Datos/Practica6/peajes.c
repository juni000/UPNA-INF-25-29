/**
 *	MODULO: Peajes
 *	FICHERO: peajes.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Implementa la gestion del peaje.
 */
#include "peajes.h"
#include <stdio.h>
#include "ruleta.h"
#define PROB_MAX 0.6 // Probabilidad de elegir la cabina más ocupada
#define PROB_MEDIA 0.3 // Probabilidad de elegir la cabina con ocupación media
#define PROB_MIN 0.1 // Probabilidad de elegir la cabina menos ocupada

typedef struct intervalo{
    int min;
    int max;
} intervalo;

intervalo tipoCobro[NCAB] = {{15, 30}, {15, 30}, {15, 45}, {15, 45}, {30, 60}};

typedef struct pareja{
    int can;
    int cab;
} pareja;

typedef struct taux{
    pareja taux[NCAB];
}taux;
void intercambio(pareja *a, pareja *b) {
	pareja aux;
	aux = *b;
	*b = *a;
	*a = aux;
}
int posicionMaximoEnPrefijo(int m, taux t){
    int pmax = 0;
    for(int i = 0; i <= m; i++){
        if(t.taux[pmax].can < t.taux[i].can){
            pmax = i;
        }
    }
    return pmax;
}
void ordenar(taux *t){
    printf("Desordendas\n");
    for(int i = 0; i < NCAB; i++){
        printf("Cabina = %d , Cantidad = %d \n", t->taux[i].cab, t->taux[i].can);
    }
    for ( int i = NCAB - 1; i >= 0; i--){
       intercambio(&t->taux[posicionMaximoEnPrefijo(i, *t)], &t->taux[i]);
    }
    printf("Ordendas\n");
    for(int i = 0; i < NCAB; i++){
        printf("Cabina = %d , Cantidad = %d \n", t->taux[i].cab, t->taux[i].can);
    }
}
void guardaCola(Peaje *p, int ncab, Reloj r){
    encolarCoche(&(*p)[ncab], r);
}

void iniciarPeaje(Peaje *p){
    for(int i = 0; i < NCAB; i++){
        iniciarCab(&(*p)[i], tipoCobro[i].min, tipoCobro[i].max);
    }
}
int eligeCabina(Peaje p){
    int i, x, n;
    taux t;
    for(i = 0; i < NCAB; i++){
        t.taux[i].can = cuantosCoches(p[i]);
        t.taux[i].cab = i;
    }
    ordenar(&t);
    x = eleccionCon3Probabilidades(PROB_MAX, PROB_MEDIA, PROB_MIN);
    n = t.taux[x].cab;
    return n;
}
void rondaCabinas(Peaje *p, Reloj r){
    for(int i = 0; i < NCAB; i++){
        servCabina(&(*p)[i], r);
    }
}

//A Cambiar
void mostrarResultadosPeaje(Peaje p){
    float esperaMedia;
    int totalServidos = 0;
    int totalEsperado = 0;

    for(int i = 0; i < NCAB; i++){
        mostrarResultadosCabina(p[i], &totalServidos, &totalEsperado);
    }
    if(totalServidos == 0){
        esperaMedia = 0;
    }else{
        esperaMedia = (float) totalEsperado / totalServidos;
    }
    printf("Tiempo medio de espera en el peaje = %.2f segundos\n", esperaMedia);
    printf("Numero total de coches servidos = %d\n", totalServidos);
}
