#include "palabras.h"
#include <stdio.h>

void main() {
    FILE * f;
    char c = 'a';
    int cont = 0;
    Palabra p1, p2;
    f=fopen("text1.txt","rb");

    leerPalabra(f, &p1);
    while(!feof(f)){
        leerPalabra(f, &p2);
        if (sonPalabrasIguales(&p1, &p2)) cont = cont + 1;
    }
    printf("Contador = %d\n", cont);

    fclose(f);
}