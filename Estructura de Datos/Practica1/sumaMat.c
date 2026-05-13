//Juan Alberto Jimenez
#include <stdio.h>
#define N 3
typedef float Matriz[N][N]; //float

void sumaMatrices(Matriz sumaMat, Matriz m1, Matriz m2){
    for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++) {
	        sumaMat[i][j] = m1[i][j] + m2[i][j];
	    }
    }
}

void intercambio(float *a, float *b) { // intercambio(float *a, float *b)
	float aux;
	aux = *b;
	*b = *a;
	*a = aux;
}

void matrizTraspuesta(Matriz m) {
    for(int i = 0; i < N - 1; i++) {
		for(int j = i + 1; j < N; j++) {
			intercambio(&m[i][j], &m[j][i]); //&m[i][j],
		}
	}
}
void printMatriz(Matriz m){
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf(" [%.2f]", m[i][j]);
		}
		printf("\n");
	}
}
int main() {
	Matriz m1, m2, sumaMat;
	char res;
	do {
    	printf("Matriz 1.\n");
    	for(int i = 0; i < N; i++){
    	    for(int j = 0; j < N; j++) {
               printf("Introduce la posición número [%d][%d] del vector: \n", i, j);
               scanf("%f", &m1[i][j]);
    	    }
        }
    	printf("Matriz 2.\n");
        for(int i = 0; i < N; i++){
    	    for(int j = 0; j < N; j++) {
               printf("Introduce la posición número [%d][%d] del vector: \n", i, j);
               scanf("%f", &m2[i][j]);
    	    }
        }
    	sumaMatrices(sumaMat, m1, m2);
        printf("Matriz suma.\n");
		printMatriz(sumaMat);

    	printf("Matriz suma tranpuesta.\n");
    	matrizTraspuesta(sumaMat);
		printMatriz(sumaMat);
    	
    	printf("Matriz 1 tranpuesta.\n");
    	matrizTraspuesta(m1);
		printMatriz(m1);
    	
    	printf("Matriz 2 tranpuesta.\n");
    	matrizTraspuesta(m2);
		printMatriz(m2);

		printf ("Deseas continuar? s/n: ");
        scanf(" %c",&res);
	} while(res == 'S' || res == 's');
	return 0;
}
