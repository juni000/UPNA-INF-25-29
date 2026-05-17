/**
 *	MODULO: Simulacion de peaje
 *	FICHERO: simPeaje.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Alberto Jimenez el 1/05/25
 *  DESCRIPCION: Ejecuta la simulacion principal del peaje.
 */
#define TSIM 10800
#include "controles.h"
#include "reloj.h"
#include "ruleta.h"
void iniciarSimulacion(Control *c){
    iniciarRuleta();
    iniciarControles(c);
}

void siguienteIteracion(Control *c, Reloj r){
    llegaCoche(c, r);
    marcharCoche(c, r);
}
void main(){
    Control c;
    Reloj r;
    aCero(&r);
    iniciarSimulacion(&c);
    while (instante(r) != TSIM){
        tic(&r);
        siguienteIteracion(&c, r);
    }
    mostrarResultados(c);
    
}
