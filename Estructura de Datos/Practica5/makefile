calcular: calculadora
	./calculadora
calculadora: calculadora.c conversor.o evaluador.o expresion.o pilaDeSimbolos.o operadores.o simbolos.o pilaDeEnteros.o
	gcc calculadora.c conversor.o evaluador.o expresion.o pilaDeSimbolos.o operadores.o simbolos.o pilaDeEnteros.o -o calculadora
operadores.o: operadores.c
	gcc -c operadores.c
pilaDeEnteros.o: pilaDeEnteros.c
	gcc -c pilaDeEnteros.c
simbolos.o: simbolos.c
	gcc -c simbolos.c
pilaDeSimbolos.o: pilaDeSimbolos.c
	gcc -c pilaDeSimbolos.c
conversor.o: conversor.c
	gcc -c conversor.c
evaluador.o: evaluador.c
	gcc -c evaluador.c
expresion.o: expresion.c
	gcc -c expresion.c