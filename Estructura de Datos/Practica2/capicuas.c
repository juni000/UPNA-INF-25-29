#include <stdio.h>
#include <stdbool.h>
#define N  1008002

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

void main() {
    FILE * f;
    int x;
    f=fopen("capicuas.int","wb");

    for(int i = 1; i < N; i++){
	    if(esCapicua(i)){
            fwrite(&i, sizeof(int), 1, f);
        }
    }

    fclose(f);
}
