//Juan Alberto Jimenez
#include <stdio.h>
#include <stdbool.h>
#define N 3

int reverso(int n){
    int m = 0;
    while(n > 0){
         m = (10 * m) + (n % 10);
         n = n / 10;
    }
    return m;
}
bool esCapicua(int n){
    bool b = false;
    b = (n == reverso(n));
    return b;
}

int main() {
	char res;
    int n;
	do {
        do{
            printf("Introduce un número positivo menor que 100.000 \n");
            scanf("%d", &n);
        }while(n >= 100000 || n < 0);
        printf("El número %d reverso \n", reverso(n));
        if(esCapicua(n)){
            printf("El número %d es capicua \n", n);
        }else{
            printf("El número %d NO es capicua \n", n);
        }


        printf ("Deseas continuar? s/n: ");
        scanf(" %c",&res);
    }while(res == 'S' || res == 's');
    return 0;
}
