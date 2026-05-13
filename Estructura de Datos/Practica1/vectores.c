//Juan Alberto Jimenez
#include <stdio.h>
#define N 10
typedef float Vector[N];

int productoEscalar(Vector v1, Vector v2){
    int prod = 0;
    for(int i = 0; i < N; i++){
           prod += v1[i] * v2[i];
    }
    return prod;
}
void copVector(Vector v1, Vector v2){
    for(int i = 0; i < N; i++){
           v2[i] = v1[i];
    }
}
void intercambio(float *a, float *b) {
	float aux;
	aux = *b;
	*b = *a;
	*a = aux;
}
int posicionMaximoEnPrefijo(int m, Vector v){
    int pmax = 0;
    for(int i = 0; i <= m; i++){
        if(v[pmax] < v[i]){
            pmax = i;
        }
    }
    return pmax;
}
void ordenarVec(Vector v){
    int pmax;
    for(int i = N - 1 ; i > 0; i--){
        intercambio(&v[posicionMaximoEnPrefijo(i, v)], &v[i]);
    }
}
void printVect(Vector v){
    for(int i = 0; i < 10; i++){
           printf("[%.2f]", v[i]);
    }
    printf("\n");
}

int main(){
    Vector v1,v2;
    float prod, prod2;
    char res;
    do{
        for(int i = 0; i < N; i++){
           printf("Introduce la posiciÃ³n nÃºmero %d del vector: \n", i);
           scanf("%f", &v1[i]);
        }
        copVector(v1, v2);
        prod = productoEscalar(v1, v1);
        printf("Producto escalar de v1 con v1 es: %.2f: \n", prod);

        ordenarVec(v1);
        printf("Vector v1 Ordenado: \n");
        printVect(v1);

        prod2 = prod - productoEscalar(v1, v2);
        if ( prod2 < 0){
            prod2 = -prod2;
        }
        printf("Diferencia de producto escalar de v1 con v2 es: %.2f: \n", prod2);

        printf ("Deseas continuar? s/n: ");
        scanf(" %c",&res);
    }while(res == 'S' || res == 's');
    return 0;
}
