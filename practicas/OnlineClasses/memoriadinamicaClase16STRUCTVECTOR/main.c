#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "persona.h"
#define TAM 5


int main()
{
    //ePersona* lista = (ePersona*)malloc(TAM*sizeof(ePersona)); /*VECTOR DE ESTRUCTURA*/
    ePersona** lista2= (ePersona**)malloc(TAM*sizeof(ePersona*));/*VECTOR A PUNTEERO*/
    ePersona* auxPersona;
    if(lista2==NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Se pudo conseguir memoria\n");
    }

    if(initPeople(lista2,TAM))
    {
        printf("Se inicializaron las personas\n");
    }
    else
    {
        printf("No se inicializarion\n");
    }

    printf("\n\n------------------------------------------------------------\n\n");

    int indice;

    findSpot(&indice,lista2,TAM);

    if(indice!=-1)
    {
        auxPersona=new_PersonWithInfo(1234,"Juan",'m',76.5);/*guarda datos de una estructura dinamicamente*/
        if(auxPersona!=NULL)
        {
            *(lista2+indice)=auxPersona;

            showPeople(lista2,TAM);
        }

    }

    return 0;
}

