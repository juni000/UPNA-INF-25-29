/**
 *	PROGRAMA PRINCIPAL: Calculadora
 *	FICHERO: Calculadora.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Juan Pablo Jimenez el 25/04/24.
 *  DESCRIPCION: Este programa hace de calculadora con pilas
 */

#include "conversor.h"
#include "evaluador.h"

int main(){
	printf("PROGRAMA: Calculadora \n");
	printf("Creado por Juan Pablo Jimenez el 01/05/24. \n");
	printf("Este programa funciona como una calculadora.\n");
	
	char ent[100];
	Expresion e;
	int n;
	char res;
	do{
		printf("Escriba la expresion que desee calcular (maximo 100 caracteres y sin espacios): \n");
		scanf("%[^\n]", ent);
		transformaPolonesa(ent, &e);
		n = evaluaPolonesa(e);
		printf("El resultado es: %d\n", n);
		
		printf("Deseas continuar? s/n \n");
		scanf(" %c", &res);
		getchar();
	}while(res == 's' || res == 'S');
	return 0;
}
