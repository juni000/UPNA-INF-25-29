#include <stdio.h>
#define N  1008002

void main() {
    FILE * f;
    FILE * fp;
    int x, n;

    f = fopen("primo4n1.int","wb");
    fp = fopen("primos.int","rb");

    fread(&x, sizeof(int), 1, fp);
    while (!feof(fp)) {
        if((x - 1) % 4  == 0) {
            fwrite(&x, sizeof(int), 1, f);
        }
        fread(&x, sizeof(int), 1, fp);
    }

    fclose(f);
}
