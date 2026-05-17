#include "palabra.h"

typedef FILE FicheroDeCaracteres;

// ACCION: prepararPalabra
// ENTRADA: p, una palabra
// REQUISITOS:
// MODIFICA: p, estableciendo la longitud de la palabra en 0
void prepararPalabra(palabra *p)
{
    p->longi=0;
}

// ACCION: agregarCaracter
// ENTRADA: p, una palabra y c, un caracter
// REQUISITOS:
// MODIFICA: p, añadiendo el caracter c al final de la palabra
void agregarCaracter(palabra *p, char c)
{
    {
        p->longi = p->longi+1;
        p->letras[p->longi-1] = c;
    }
}

// ACCION: modificarCaracter
// ENTRADA: p, una palabra, i, un índice y c, un caracter
// REQUISITOS:
// MODIFICA: p, modificando el caracter en la posición i por el caracter c
void modificarCaracter(palabra *p, int i,char c)
{
    p->letras[i]=c;
}

// FUNCION: consultarCaracter
// ENTRADA: p, una palabra y i, un índice
// REQUISITOS:
// SALIDA: El caracter en la posición i de la palabra p
char consultarCaracter(palabra p, int i)
{
    char c;
    c=p.letras[i];
    return(c);
}

// FUNCION: longitudPalabra
// ENTRADA: p, una palabra
// REQUISITOS:
// SALIDA: La longitud de la palabra p
int longitudPalabra(palabra p)
{
    int longi;
    longi=p.longi;
    return(longi);
}

// FUNCION: esPalabraVacia
// ENTRADA: p, una palabra
// REQUISITOS:
// SALIDA: true si la palabra p está vacía, false en caso contrario
bool esPalabraVacia(palabra p)
{
    bool b;
    b=(p.longi==0);
    return(b);
}

// FUNCION: sonPalabrasIguales
// ENTRADA: p1 y p2, dos palabras
// REQUISITOS:
// SALIDA: true si las palabras p1 y p2 son iguales, false en caso contrario
bool sonPalabrasIguales(palabra p1, palabra p2)
{
    int i;
    bool b;
    if (p1.longi == p2.longi)
    {
        i=0;
        while ((i < p1.longi-1) && (consultarCaracter(p1,i) == consultarCaracter(p2,i)))
        {
            i = i+1;
        }
        b=(consultarCaracter(p1,i) == consultarCaracter(p2,i));

    }
    else
    {
        b=false;
    }
    return(b);
}

// ACCION: saltarBlancos
// ENTRADA: f, un puntero a un fichero de caracteres y c, un puntero a un caracter
// REQUISITOS:
// MODIFICA: f, avanzando al siguiente caracter que no sea un espacio en blanco o un salto de línea
void saltarBlancos(FicheroDeCaracteres *f, char *c)
{
    fread(c, sizeof(char),1, f);
    while (!feof(f) && ((*c == ' ') || (*c == '\n')))
    {
        *c= getc(f);
    }
}

// ACCION: copiarLetras
// ENTRADA: f, un puntero a un fichero de caracteres, c, un puntero a un caracter y p, una palabra
// REQUISITOS:
// MODIFICA: p, copiando los caracteres del fichero f hasta encontrar un espacio en blanco o un salto de línea
void copiarLetras(FicheroDeCaracteres *f, char *c, palabra *p)
{
    prepararPalabra(p);
    while((!feof(f)) && (*c != ' ' ) && (*c != '\n'))
    {
        agregarCaracter(p, *c);
        *c= getc(f);
    }
}

// ACCION: leerPalabra
// ENTRADA: f, un puntero a un fichero de caracteres y p, una palabra
// REQUISITOS:
// MODIFICA: p, leyendo una palabra del fichero f
void leerPalabra(FicheroDeCaracteres *f, palabra *p)
{
    char c;
    prepararPalabra(p);
    if (!feof(f))
    {
        saltarBlancos(f,&c);
        copiarLetras(f,&c,p);
    }
}

/*
 * ACCION: copiarPalabra
 * ENTRADA: p, una palabra
 * REQUISITOS:
 * SALIDA: q, una palabra que es copia de p
 */
void copiarPalabra(palabra p, palabra * q)
{
    int i;
    prepararPalabra(q);
    q->longi = p.longi;
    for (i = 0; i < p.longi; i++)
    {
        q->letras[i] = p.letras[i];
    }
}

/*
 *  FUNCION: escribirPalabra
 *	ENTRADA: f, fichero de caracter y p, una palabra
 *  REQUISITOS:
 *  MODIFICA: f, añadiendo la palabra p al final de f
 */
void escribirPalabra(FILE * f, palabra p)
{
    int i;
    for (i = 0; i < p.longi; i++)
    {
        putc(p.letras[i], f);
    }
}

/*
 * ACCION: muestraPalabra
 * ENTRADA: p, una palabra
 * REQUISITOS:
 * SALIDA: Escribe en pantalla la palabra p
 */
void muestraPalabra(palabra p)
{
    int i;
    for (i = 0; i < p.longi; i++)
    {
        putchar(p.letras[i]);
    }
}
