#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void swap (int* x, int* y);
void bubbleSortEleccion (int vector[],int tam, int opcion);
void copiarCadena (char cadenaDest[],char cadenaOrig[]);
void pedirNumero (int* x,int* y);
void mostrarVector (int x[],int tam);

int main()
{
    int num1;
    int num2;
    int vector[]={8,2,4,1};

    pedirNumero(&num1,&num2);
    printf("Antes de la funcion= primero: %d segundo %d\n",num1,num2);
    swap(&num1,&num2);
    printf("Despues de la funcion= primero: %d segundo %d\n",num1,num2);

    bubbleSortEleccion(vector,TAM,0);

    mostrarVector(vector,TAM);


    return 0;
}
void pedirNumero (int* x,int* y)
{
    printf("Ingrese un numero:\n");
    scanf("%d",x);
    printf("Ingrese otro numero:\n");
    scanf("%d",y);
}

void swap (int* x, int* y)
{
    int auxiliar;

    auxiliar=*x;

    *x=*y;
    *y=auxiliar;
}

void bubbleSortEleccion (int vector[],int tam, int opcion)
{
    int auxiliar;
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vector[i]>vector[j]&&opcion)
            {
                auxiliar=vector[j];
                vector[j]=vector[i];
                vector[i]=auxiliar;
            }
            else
            {
                if(vector[i]<vector[j]&&!opcion)
                {
                    auxiliar=vector[j];
                    vector[j]=vector[i];
                    vector[i]=auxiliar;
                }
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
