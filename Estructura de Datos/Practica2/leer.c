#include <stdio.h>

void main() {
    FILE * f;
    int x;
    int opc;
    char *nombre;
    printf("Opcion :");
    scanf("%d", &opc);

    switch(opc){
        case 1: nombre = "primos.int";
        break;
        case 2: nombre = "priycap.int";
        break;
        case 3: nombre = "capicuas.int";
        break;
        case 4: nombre = "primo4n1.int";
        break;
    }
    f = fopen(nombre,"rb");
    fread(&x, sizeof(int), 1, f);
    while (!feof(f)) {
        printf("%d, ", x);
        fread(&x, sizeof(int), 1, f);
    }
    printf("\n");
    fclose(f);
}
