#include <stdio.h>
#include <stdlib.h>

typedef struct{

int id;
char nombre[20]
char sexo;
float peso;

}ePersona;
int main()
{
    ePersona lista = (ePersona*)/*casteo puntero*/ malloc(5*sizeof(int)); /*VECTOR DE ESTRUCTURA*/
    /*si pedimos un millon va a ser dificil un vector porque realloc no va a encontrar tanto espacio de BLOQUE,
    entonces usamos PUNTEROS A ESTRUCTURA Y ESTAN TODOS DESPARRAMADOS*/

    ePersona** lista2 = (ePersona**)malloc(5*sizeof(ePersona*));

    return 0;
}
