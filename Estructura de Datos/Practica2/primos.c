#include <stdio.h>
#include <stdbool.h>
#define N  1008002

bool esPrimo(int n){
    bool b = false;
    int k;
    if(n == 2) b = true;
    else if(n == 3) b = true;
    else if(n > 3){
        if(n % 2 == 0) b = false;
        else{
            k = 3;
            while ((n > k * k) && (n % k != 0)){
                k = k + 2;
            }
            b = n % k != 0;
        }
    }
    return b;
}

void main() {
    FILE * f;
    int x;
    f=fopen("primos.int","wb");

    for(int i = 2; i < N; i++){
	    if(esPrimo(i)){
            fwrite(&i, sizeof(int), 1, f);
        }
    }

    fclose(f);
}
