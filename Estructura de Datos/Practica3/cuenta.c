#include <stdio.h>
#include <stdbool.h>

typedef struct Palabra{
    char c[100];
    int longitud;
} Palabra;

void saltarBlancos(FILE *f, char *c){
    fread(&(*c), sizeof(char), 1, f);
    while(!feof(f) && *c == ' '){
        fread(&(*c), sizeof(char), 1, f);
    }
}
void prepararPalabra(Palabra *p){
    (*p).longitud = 0;
}
void copiarLetras(FILE *f, char *c, Palabra *p){
    prepararPalabra(&(*p));
    while(!feof(f) && *c != ' '){
        (*p).c[(*p).longitud] = *c;
        (*p).longitud = (*p).longitud + 1;
        fread(&(*c), sizeof(char), 1, f);
    }
}
void leerPalabra(FILE *f, Palabra *p){
    char c;
    saltarBlancos(f, &c);
    copiarLetras(f, &c, &(*p));
}

void printPalabra(Palabra p){
    for(int i = 0; i < p.longitud; i++){
        printf("%c", p.c[i]);
    }
    printf("  L: %d", p.longitud);
    printf("\n");
}

bool sonPalabrasIguales(Palabra p1,Palabra p2){
    bool b;
    int i = 0;
    if(p1.longitud == p2.longitud){
        while(i < p1.longitud - 1 && p1.c[i] == p2.c[i]){
            i = i + 1;
        }
        b = p1.c[i ] == p2.c[i];
    }
    else{
        b = false;
    }
    return b;
}

void main() {
    FILE * f;
    char c = 'a';
    int cont = 0;
    Palabra p1, p2;
    f=fopen("text1.txt","rb");

    leerPalabra(f, &p1);
    printPalabra(p1);
    while(!feof(f)){
        leerPalabra(f, &p2);
        printPalabra(p2);
        if (sonPalabrasIguales(p1, p2)) cont = cont + 1;
    }
    printf("Contador = %d\n", cont);

    fclose(f);
}