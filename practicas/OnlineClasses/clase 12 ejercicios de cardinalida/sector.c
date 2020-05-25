#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"


void mostrarSectores (eSector sectores[],int tam)
{
    printf("***Sectores*****\n");
    printf(" ID      SECTOR    \n");
    for(int i=0;i<tam;i++)
    {
        printf("%d  %13s\n",sectores[i].id,sectores[i].descripcion);
    }

}

