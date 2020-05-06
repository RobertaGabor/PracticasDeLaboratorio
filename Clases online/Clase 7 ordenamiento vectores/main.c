#include <stdio.h>
#include <stdlib.h>

/*BURBUJERO*/
void swap (int* x, int* y); //HACER
void bubbleSortEleccion (int vector[],int tam, int opcion);//hacer un vector con criterio 1 o 0 para descendente o ascendente;
void copiarCadena (char cadenaDest[],char cadenaOrig[]);
int main()
{/*comilla simple literal d ecaracteres*/
//a =97 y b=98 en ascii. a<b==1. minusculas>mayusculas


    int x=5;
    int y=10;
    int auxiliar;

    printf("x: %d y: %d\n",x,y);

    auxiliar=x;
    x=y;
    y=auxiliar;
    printf("x: %d y: %d",x,y);


    return 0;
}
