#include <stdio.h>
#include <math.h>
void leerCaracter(FILE *f, char *c){
    int i = 0, j = 0;
    for(i = 0; i < 8; i++){
        fread(c, sizeof(char), 1, f);
        if (*c == '1'){
            j = pow(2, 7 - i) + j;
        }
    }
    *c = (char)j;
}
void main() {
    FILE * f;
    char c ;
    int i = 0, j;
    char frase[1000];
    f=fopen("text1.txt","rb");

    while(!feof(f)){
        leerCaracter(f, &c);
        printf("Caracter leido : %c\n", c);
        frase[i] = c;
        i = i + 1;
    }
    for (j = 0 ; j < i; j++){
        printf("%c", frase[j]);
    }
    fclose(f);
}