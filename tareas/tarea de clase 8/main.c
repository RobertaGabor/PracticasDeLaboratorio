#include <stdio.h>
#include <stdlib.h>
#define TAM 20
#define TOM TAM*2-1


int imprimirOrdenado (char vector[],int tam);
void ordenarLista (char vector[],int tam);
void mostrarConjunto (char vector1[],char vector2[]);
/*que al mostrar nombre completo aparezca
el nombre que puso y apellido que puso
nombre con inicial mayus,coma, espacio apellido con mayus
no tocar vaiables.*/

int main()
{
    char nombre[TAM];
    char apellido[TAM];
    int contadorNombre;
    int contadorApellido;

    printf("Ingrese nombre:\n");
    gets(nombre);

    printf("Ingrese apellido:\n");
    gets(apellido);

    ordenarLista(nombre,TAM);
    ordenarLista(apellido,TAM);

    contadorApellido=imprimirOrdenado(apellido,TAM);
    contadorNombre=imprimirOrdenado(nombre,TAM);

    if(contadorApellido+contadorNombre+2>TOM)
    {
        printf("Error. Ingrese datos mas cortos\n");
    }
    else
    {
        mostrarConjunto(nombre,apellido);
    }

    return 0;
}

 void ordenarLista (char vector[],int tam)
 {
        for(int i=0;i<tam;i++)
        {
             if(i==0)
             {
                 if(vector[i]>96&&vector[i]<123)
                 {
                     vector[i]=vector[i]-32;
                 }
                 else
                 {
                     if(vector[i]<65||(vector[i]>90&&vector[i]<97))
                    {
                        break;
                    }
                 }
             }
             else
             {
                if(vector[i]>64&&vector[i]<91)
                {
                    vector[i]=vector[i]+32;
                }
                else
                {
                    if(vector[i]<65||(vector[i]>90&&vector[i]<97))
                    {
                        break;
                    }
                }
             }
        }
 }

int imprimirOrdenado (char vector[],int tam)
 {
    int contador=0;
    for(int i=0;i<tam;i++)
    {
        if(vector[i]!='\0')
        {
          contador++;
        }
    }

    return contador;
 }


 void mostrarConjunto (char vector1[],char vector2[])
 {
    printf("%s, %s\n",vector1,vector2);
 }
