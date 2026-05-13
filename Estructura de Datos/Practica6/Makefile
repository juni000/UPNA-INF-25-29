simPeaje: simPeaje.c controles.o peajes.o cabinas.o colaDeEnteros.o ruleta.o reloj.o
	gcc -o simPeaje simPeaje.c controles.o peajes.o cabinas.o colaDeEnteros.o ruleta.o reloj.o
controles.o: controles.c controles.h
	gcc -c controles.c
peajes.o: peajes.c peajes.h
	gcc -c peajes.c
cabinas.o: cabinas.c cabinas.h
	gcc -c cabinas.c
colaDeEnteros.o: colaDeEnteros.c colaDeEnteros.h
	gcc -c colaDeEnteros.c
ruleta.o: ruleta.c ruleta.h
	gcc -c ruleta.c
reloj.o: reloj.c reloj.h
	gcc -c reloj.c
clean:
	rm *.o simPeaje
