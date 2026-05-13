#include "reloj.h"

void aCero(Reloj *r){
    (*r) = 0;
}
void tic(Reloj *r){
    (*r) ++;
}
int instante(Reloj r){
    return r;
}