#include <stdio.h>

void main() {
    FILE * f;
    FILE * f1;
    FILE * f2;
    int x, x1, x2;
    char nombre[30];

    /*printf("Introduzca el nombre del primer fichero a tratar\n");
    scanf("%s", nombre);*/
    f1 = fopen("primos.int","rb");

    /*printf("Introduzca el nombre del segundo fichero a tratar\n");
    scanf("%s", nombre);*/
    f2 = fopen("capicuas.int","rb");

    f = fopen("priycap.int","wb");
	fread(&x1, sizeof(int), 1, f1);
	fread(&x2, sizeof(int), 1, f2);
	while (!feof(f2) && !feof(f1)) {
		if(x1 == x2) {
			fwrite(&x1, sizeof(int), 1, f);
			fread(&x1, sizeof(int), 1, f1);
			fread(&x2, sizeof(int), 1, f2);
		} else if (x1 > x2) {
			fread(&x2, sizeof(int), 1, f2);
		} else if (x1 < x2) {
			fread(&x1, sizeof(int), 1, f1);
		}
	}

    fclose(f1);
	fclose(f2);
    fclose(f);
}
