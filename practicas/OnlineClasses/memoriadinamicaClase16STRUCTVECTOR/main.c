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
        }


        findSpot(&indice,lista2,TAM);
        if(indice!=-1)
        {
            auxPersona=new_PersonWithInfo(3345,"Ana",'f',80.2);
            if(auxPersona!=NULL)
            {
                *(lista2+indice)=auxPersona;
            }

            findSpot(&indice,lista2,TAM);
            if(indice!=-1)
            {
                auxPersona=new_PersonWithInfo(1223,"Pepe",'m',55.7);
                if(auxPersona!=NULL)
                {
                    *(lista2+indice)=auxPersona;
                }
            }

        }
        printf("\n------ANTES DE BAJA----\n");
        showPeople(lista2,TAM);

        /*DAR DE BAJA*/

        free(*(lista2+1/*ese 1 viene de una funcion de buscar indice de x persona*/));
        *(lista2+1)=NULL; /*y dejamos el NULL es como 0 en isEmpty*/
        printf("\n------DESPUES DE BAJA----\n");
        showPeople(lista2,TAM);

        /*NUEVA ALTA*/

        findSpot(&indice,lista2,TAM);
        if(indice!=-1)
        {
            auxPersona=new_PersonWithInfo(2566,"Susie",'f',58.9);
            if(auxPersona!=NULL)
            {
                *(lista2+indice)=auxPersona;
            }
        }

        printf("\n------DESPUES DE NUEVA ALTA----\n");
        showPeople(lista2,TAM);/*me pone a susies ENTRE ELLOS DOS*/



    }

    return 0;
}

