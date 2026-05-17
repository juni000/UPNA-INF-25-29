simPeaje.exe: simPeaje.c controles.o peajes.o cabinas.o colaDeEnteros.o ruleta.o reloj.o
	gcc -g -o simPeaje.exe simPeaje.c controles.o peajes.o cabinas.o colaDeEnteros.o ruleta.o reloj.o
controles.o: controles.c controles.h
	gcc -g -c controles.c
peajes.o: peajes.c peajes.h
	gcc -g -c peajes.c
cabinas.o: cabinas.c cabinas.h
	gcc -g -c cabinas.c
colaDeEnteros.o: colaDeEnteros.c colaDeEnteros.h
	gcc -g -c colaDeEnteros.c
ruleta.o: ruleta.c ruleta.h
	gcc -g -c ruleta.c
reloj.o: reloj.c reloj.h
	gcc -g -c reloj.c
clean:
	del *.o simPeaje.exe