#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//tarea en el otro

void mostrarVector (int x[],int tam);
void swapBubblesort (int vector[],int tam);
void ordenarCharArray (char vector[],int tam);
void mostrarVectorChar (char x[],int tam);

int main()
{
    int ingresoVector[TAM]={8,9,5,2,4};
    char ingresoArray []={'a','z','e','f','g','l','o'};
    printf("Antes de la funcion\n");
    mostrarVector(ingresoVector,TAM);

    swapBubblesort(ingresoVector,TAM);
    printf("\nDespues de la funcion\n");
    mostrarVector(ingresoVector,TAM);

    printf("\nAlfabeto sin ordenar\n");
    mostrarVectorChar(ingresoArray,7);

    printf("\nDespues de la funcion\n");
    ordenarCharArray(ingresoArray,7);
    mostrarVectorChar(ingresoArray,7);

    return 0;
}



void swapBubblesort (int vector[],int tam)
{
    int auxiliar;
    for(int i=0;i<tam-1;i++)//la primer flecha no llega al ultimo
    {
        for(int j=i+1;j<tam;j++)//j se define sin el  vector
        {
            if(vector[i]>vector[j])
            {
               auxiliar=vector[j];
               vector[j]=vector[i];
               vector[i]=auxiliar;
            }
        }
    }

}
void mostrarVector (int x[],int tam)
{
     for(int i=0;i<tam;i++)
        {
            printf("%d ",x[i]);
        }
}

void mostrarVectorChar (char x[],int tam)
{
     for(int i=0;i<tam;i++)
        {
            printf("%c ",x[i]);
        }
}

void ordenarCharArray (char vector[],int tam)
{
    char auxiliar;
    for(int i=0;i<tam-1;i++)//la primer flecha no llega al ultimo
    {
        for(int j=i+1;j<tam;j++)//j se define sin el  vector
        {
            if(vector[i]>vector[j])
            {
               auxiliar=vector[j];
               vector[j]=vector[i];
               vector[i]=auxiliar;
            }
        }
    }

}



//en main
/*for(int i=0;i<10;i++)//-->for exterior
{
    printf("Hola\n");

    for(int j=0;j<5;j++)//VEO 5 CHAU CADA 1 HOLA
    {                   //-->for interior
        printf("Chau\n");
    }
}*/
