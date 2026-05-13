#include "peajes.h"
#include <stdio.h>
#define NCAB 5
#define PROB_MAX 0.6
#define PROB_MEDIA 0.3
#define PROB_MIN 0.1

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
    for ( int i = NCAB - 1; i >= 0; i--){
       intercambio(&t->taux[posicionMaximoEnPrefijo(i, *t)], &t->taux[i]);
    }
    
}
void guardaCola(Peaje *p, int ncab, Reloj r){
    encolarCoche(&p->cabinas[ncab], r);
}

void iniciarPeaje(Peaje *p){
    for(int i = 0; i < NCAB; i++){
        iniciarCab(&p->cabinas[i], tipoCobro[i].min, tipoCobro[i].max);
    }
}
int eligeCabina(const Peaje *p){
    int i, x, n;
    taux t;
    for(i = 0; i < NCAB; i++){
        t.taux[i].can = cuantosCoches(p->cabinas[i]);
        t.taux[i].cab = i;
    }
    ordenar(&t);
    x = eleccionCon3Probabilidades(PROB_MAX, PROB_MEDIA, PROB_MIN);
    n = t.taux[x].cab;
    return n;
}
void rondaCabinas(Peaje *p, Reloj r){
    for(int i = 0; i < NCAB; i++){
        servCabina(&p->cabinas[i], r);
    }
}

void mostrarResultados(Peaje p){
    float esperaMedia;
    int totalServidos = 0;
    int totalEsperado = 0;

    for(int i = 0; i < NCAB; i++){
        if(p.cabinas[i].servidos == 0){
            esperaMedia = 0;
        }else{
            esperaMedia = (float) p.cabinas[i].totalEsperado / p.cabinas[i].servidos;
        }
        printf("Cabina %d: tiempo medio de espera = %.2f segundos, longitud maxima de cola = %d coches\n",
               i + 1, esperaMedia, p.cabinas[i].maxCoches);
        totalServidos = totalServidos + p.cabinas[i].servidos;
        totalEsperado = totalEsperado + p.cabinas[i].totalEsperado;
    }

    if(totalServidos == 0){
        esperaMedia = 0;
    }else{
        esperaMedia = (float) totalEsperado / totalServidos;
    }
    printf("Tiempo medio de espera en el peaje = %.2f segundos\n", esperaMedia);
    printf("Numero total de coches servidos = %d\n", totalServidos);
}
