/**
 *	MODULO: Ruleta
 *	FICHERO: ruleta.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Genera valores aleatorios para la simulacion.
 */
#include "ruleta.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
void iniciarRuleta(){
    srand(time(NULL));
}
int distribucionExponencial(int media){
    float x;
    int t;
    x = (float) rand() /  RAND_MAX ;
    t = (int) (-log(1 - x) * (media));
    while (t == 0){
        x = (float) rand() /  RAND_MAX ;
        t = (int) (-log(1 - x) * (media));
    }
    return t;
}
int distribucionLineal(int max, int min){
    int t;
    float x;
    x = (float) rand() /  RAND_MAX ;
    t = (int) ((max - min) * x + min);
    return t;
}
int eleccionCon3Probabilidades(float maxp, float medp, float minp){
    int n;
    float x;
    float elec[3] = {maxp, maxp + medp, 1};
    x = (float) rand() / RAND_MAX ;
    n = 0;
    while (elec[n] < x && n < 2){
        n = n + 1;
    }
    return n;
}
