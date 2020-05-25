#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obraSocial.h"

void mostrarObras (eObraSocial obraSocial[],int tamObr)
{
    printf("***Obras Sociales*****\n");
    printf(" ID      NOMBRE    \n");
    for(int i=0;i<tamObr;i++)
    {
        printf("%d  %13s\n",obraSocial[i].id,obraSocial[i].descripcion);
    }

}

int cargarDescripcionObra(char descripcion[],int id,eObraSocial obras[],int tamObr)
{
    int retorno=0;

    for(int i=0;i<tamObr;i++)
    {
        if(obras[i].id==id)
        {
            strcpy(descripcion,obras[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}
