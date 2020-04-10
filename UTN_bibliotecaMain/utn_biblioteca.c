#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int i;
    int auxiliarResultado;
    int validacion;
    validacion=1;

    if(pResultado!=NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo&&reintentos>=0)
    {
        for(i=0;i<=reintentos;reintentos--)
        {
            printf("%s",mensaje);
            scanf("%d",&auxiliarResultado);//usamos el auxiliar por  que si pone uno mal no queremos devolverlo.
            if(auxiliarResultado<=maximo&&auxiliarResultado>=minimo)
            {
                *pResultado=auxiliarResultado;
                validacion=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
        }
    }

    return validacion;
}
