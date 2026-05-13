#include "palabras.h"
#include <stdio.h>


void prepararPalabra(Palabra *p){
    (*p).longitud = 0;
}
void agregarCaracter(Palabra *p, char c){
    if (longitudPalabra(p) < MAX){
        (*p).c[(*p).longitud] = c;
        (*p).longitud = (*p).longitud + 1;
    }
}

void modificarCaracter(Palabra *p,int i, char c){
    (*p).c[i] = c;
}
char consultarCaracter(Palabra *p,int i){
    char c;
    c = (*p).c[i];
    return c;
}
long longitudPalabra(Palabra *p){
    long l;
    l = (*p).longitud;
    return l;
}
bool esPalabraVacia(Palabra *p){
    bool b;
    b = (longitudPalabra(p) == 0);
    return b;
}
bool sonPalabrasIguales(Palabra *p1, Palabra *p2){
    bool b;
    int i = 0;
    if(longitudPalabra(p1) == longitudPalabra(p2)){
        while(i < longitudPalabra(p1) - 1 && consultarCaracter(p1, i) == consultarCaracter(p2, i)){
            i = i + 1;
        }
        b = consultarCaracter(p1, i ) == consultarCaracter(p2, i);
    }
    else{
        b = false;
    }
    return b;
}
void saltarBlancos(FILE *f, char *c){
    fread(c, sizeof(char), 1, f);
    while(!feof(f) && *c == ' '){
        fread(c, sizeof(char), 1, f);
    }
}
void copiarLetras(FILE *f, char *c, Palabra *p){
    prepararPalabra(p);
    while(!feof(f) && *c != ' '){
        agregarCaracter(p, *c);
        fread(c, sizeof(char), 1, f);
    }
    /*if(*c != ' '){
        agregarCaracter(p, *c);
    }*/
}
void leerPalabra(FILE *f, Palabra *p){
    char c;
    prepararPalabra(p);
    if(!feof(f)){
        saltarBlancos(f, &c);
        copiarLetras(f, &c, p);
    }
}