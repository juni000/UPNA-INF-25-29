#ifndef RULETA_H
#define RULETA_H
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void iniciarRuleta();
int distribucionExponencial(int media);
int distribucionLineal(int max, int min);
int eleccionCon3Probabilidades(float maxp, float medp, float minp);
#endif