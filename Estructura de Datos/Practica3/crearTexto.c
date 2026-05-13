#include <stdio.h>

typedef struct Palabra{
    char c[100];
    int longitud;
} Palabra;

void escribirPalabra(FILE *f,Palabra p){
    char c = ' ';
    for(int i = 0; i < p.longitud; i++){
        //printf("P : %c, L : %d\n", p.c[i], p.longitud);
	    fwrite(&p.c[i], sizeof(char), 1, f);
    }
    fwrite(&c, sizeof(char), 1, f);
}
void main() {
    FILE * f;
    f=fopen("text1.txt","wr");
    Palabra p1 = {{'H','O','L','A'}, 4};
    Palabra p2 = {{'P','A','R','A'}, 4};
    escribirPalabra(f, p1);
    escribirPalabra(f, p2);
    escribirPalabra(f, p1);
    escribirPalabra(f, p1);
    escribirPalabra(f, p2);
    escribirPalabra(f, p1);
    escribirPalabra(f, p1);
    escribirPalabra(f, p2);
    escribirPalabra(f, p1);
    fclose(f);
}

