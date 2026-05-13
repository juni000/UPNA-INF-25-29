#include <stdio.h>
#include <stdbool.h>

#define N 1000

bool esPrimo(int n) {
	bool b = false;
	int k;
	if(n == 2) b = true;
	else if(n == 3) b = true;
	else if(n > 3) {
		if(n % 2 == 0) b = false;
		else {
			k = 3;
			while ((n > k * k) && (n % k != 0)) {
				k = k + 2;
			}
			b = n % k != 0;
		}
	}
	return b;
}
int reverso(int n) {
	int m = 0;
	while(n > 0) {
		m = (10 * m) + (n % 10);
		n = n / 10;
	}
	return m;
}

bool esCapicua(int n) {
	bool b = false;
	b = (n == reverso(n));
	return b;
}

int absoulto(int n) {
	if (n < 0) {
		n = - n;
	}
	return n;
}
void main() {

	FILE * f;
	int x;
	printf("Numeros primos:\n ");
	f=fopen("f1.int","wb");
	for(int i = 0; i < N; i++) {
		if(esPrimo(i)) {
			fwrite(&i, sizeof(int), 1, f);
		}
	}
	fclose(f);
	f=fopen("f1.int","rb");
	x = 0;
	fread(&x, sizeof(int), 1, f);
	printf("%d, ", x);
	while (!feof(f)) {
		fread(&x, sizeof(int), 1, f);
		printf("%d, ", x);
	}
	fclose(f);


	printf("\nNumeros Capicua:\n ");
	f=fopen("f2.int","wb");
	x = 0;

	for(int i = 0; i < N; i++) {
		if(esCapicua(i)) {
			fwrite(&i, sizeof(int), 1, f);
		}
	}
	fclose(f);
	f=fopen("f2.int","rb");
	x = 0;
	fread(&x, sizeof(int), 1, f);
	printf("%d, ", x);
	while (!feof(f)) {
		fread(&x, sizeof(int), 1, f);
		printf("%d, ", x);
	}

	fclose(f);

	
	FILE * f1;
	FILE * f2;
	int dist, x1, x2;
	
	printf("\nNumeros ordenados:\n ");
	f1 = fopen("f1.int","rb");

	f2 = fopen("f2.int","rb");

	f = fopen("f.int","wb");
	/*
	x1 = 0;
	x2 = 0;
	fread(&x1, sizeof(int), 1, f1);
	fread(&x2, sizeof(int), 1, f2);
	dist = absoulto(x1 - x2);
	while (!feof(f2) && !feof(f1) && dist != 0) {
		if(dist >= absoulto(x1 - x2)){
	        dist = absoulto(x1 - x2);
	    }
        if (x1 < x2){
            fread(&x1, sizeof(int), 1, f1);
        }else if(x2 < x1){
            fread(&x2, sizeof(int), 1, f2);
        }
	   
	}
	printf("distancia min %d y %d: %d" , x1, x2, dist);
	fclose(f);
	fclose(f1);
	fclose(f2);*/
	
	fread(&x1, sizeof(int), 1, f1);
	fread(&x2, sizeof(int), 1, f2);
	while (!feof(f2) && !feof(f1)) {
		if(x1 == x2) {
			fwrite(&x1, sizeof(int), 1, f);
			fread(&x1, sizeof(int), 1, f1);
			fread(&x2, sizeof(int), 1, f2);
		} else if (x1 > x2) {
			fwrite(&x2, sizeof(int), 1, f);
			fread(&x2, sizeof(int), 1, f2);
		} else if (x1 < x2) {
			fwrite(&x1, sizeof(int), 1, f);
			fread(&x1, sizeof(int), 1, f1);
		}
	}
	if(!feof(f2)) {
		while(!feof(f2) && x2 < x1) {
			fwrite(&x2, sizeof(int), 1, f);
			fread(&x2, sizeof(int), 1, f2);
		}
		if(x2 >= x1) {
			fwrite(&x2, sizeof(int), 1, f);
		}
		while(!feof(f2)) {
			fread(&x2, sizeof(int), 1, f2);
			fwrite(&x2, sizeof(int), 1, f);
		}
		if(x2 < x1) {
			fwrite(&x2, sizeof(int), 1, f);
			fwrite(&x1, sizeof(int), 1, f);
		}
	} else if(!feof(f1)) {
		while(!feof(f1) && x1 < x2) {
			fwrite(&x1, sizeof(int), 1, f);
			fread(&x1, sizeof(int), 1, f1);
		}
		if(x1 >= x2) {
			fwrite(&x1, sizeof(int), 1, f);
		}
		while(!feof(f1)) {
			fread(&x1, sizeof(int), 1, f1);
			fwrite(&x1, sizeof(int), 1, f);
		}
		if(x1 < x2) {
		    fwrite(&x1, sizeof(int), 1, f);
			fwrite(&x2, sizeof(int), 1, f);
		}
	} else if(feof(f1) && feof(f2)) {
		if(x1 == x2) {
			fwrite(&x1, sizeof(int), 1, f);
		} else if (x1 > x2) {
			fwrite(&x2, sizeof(int), 1, f);
			fwrite(&x1, sizeof(int), 1, f);
		} else if (x1 < x2) {
			fwrite(&x1, sizeof(int), 1, f);
			fwrite(&x2, sizeof(int), 1, f);
		}
	}
	fclose(f);
	printf("Numeros ordenado:");
	x1 = 0;
	f=fopen("f.int","rb");
	fread(&x1, sizeof(int), 1, f);
	printf("%d, ", x1);

	while (!feof(f)) {
		fread(&x1, sizeof(int), 1, f);
		printf("%d,", x1);
	}

	fclose(f);
	fclose(f1);
	fclose(f2);
    


}