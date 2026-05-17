/**
 *	MODULO: Conversor
 *	FICHERO: Conversor.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 25/04/24.
 *  DESCRIPCION: Este modulo recoge todas las implementaciones
 *  definidas sobre el tipo Conversor.
 */
 #include <stdlib.h>
 #include "operadores.h"
 #include "conversor.h"
 
 
/**
 * ACCION: decbin
 * ENTRADA: Una cadena y un entero
 * REQUISITOS: La cadena debe estar bien escrita y no vacia
 * SALIDA: Devuelve el numero entero de la cadena en binario
 */
void decbin(Cadena s, int * i, int * n){
	*n = 0;
	while ((s[*i] >= '0') && (s[*i] <= '9') && (*i <= strlen(s))){
		*n = *n * 10 + (s[*i] - '0');
		*i = *i + 1;
	}
}


/**
 * ACCION: colocaSimbolo
 * ENTRADA: Un simbolo, una expresion y una pila de simbolos
 * REQUISITOS: La pila no debe estar vacia
 * SALIDA: Coloca el simbolo en la expresion o en la pila
 */
void colocaSimbolo(Simbolo y, Expresion * e, PilaDeSimbolos *p){
	
	Simbolo x;
	Operador a, b;
	
	if (!esOperador(y)){
		aniadeSimbolo(e, y);
	}
	else{
		cimaPilaDeSimbolos(*p, &x);
		a = operador(x);
		b = operador(y);
		
		if((a != dolar) || (b != dolar)){
			if (precedenciaIzquierda(a) < precedenciaDerecha(b)){
				apilarPilaDeSimbolos(&*p, y);
			}
			else{
				while (precedenciaIzquierda(a) > precedenciaDerecha(b)){
					aniadeSimbolo(e, x);
					desapilarPilaDeSimbolos(&*p);
					cimaPilaDeSimbolos(*p, &x);
					a = operador(x);
				}
				if (precedenciaIzquierda(a) == precedenciaDerecha(b)){
					desapilarPilaDeSimbolos(p);
				}
				else{
					apilarPilaDeSimbolos(p, y);
				}
			}
		}
		else{
			desapilarPilaDeSimbolos(&*p);
		}
	}
}


/**
 * ACCION: trasformaPolonesa
 * ENTRADA: Una cadena
 * REQUISITOS: La cadena debe estar bien escrita y no vacia
 * SALIDA: Devuelve la expresion en postfija
 */
void transformaPolonesa(Cadena ein, Expresion * eout){
	PilaDeSimbolos p;
	Simbolo a;
	int x, i;
	
	expresionNula(eout);
	nuevaPilaDeSimbolos(&p);
	hazOperador(dolar, &a);
	apilarPilaDeSimbolos(&p, a);
	i = 0;
	while(i <= strlen(ein)){
		if (ein[i] == ' '){
			i = i + 1;
		}
		else if(ein[i] == '+'){
			hazOperador(suma, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if(ein[i] == '-'){
			hazOperador(resta, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if(ein[i] == '*'){
			hazOperador(producto, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if(ein[i] == '/'){
			hazOperador(division, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if(ein[i] == '('){
			hazOperador(parizqdo, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if(ein[i] == ')'){
			hazOperador(pardcho, &a);
			colocaSimbolo(a, eout, &p);
			i = i + 1;
		}
		else if ((ein[i] >= '0') && (ein[i] <= '9')){
			decbin(ein, &i, &x);
			hazOperando(x, &a);
			colocaSimbolo(a, eout, &p);
		}
		else{
			i = i + 1;
		}
	}
	hazOperador(dolar, &a);
	colocaSimbolo(a, eout, &p);
}
