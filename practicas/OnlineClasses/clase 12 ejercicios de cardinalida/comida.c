#include "comida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarComidas (eComida comidas[],int tamCo)
{
    system("cls");
    printf("*****Listado de comidas*****\n");
    printf("Id    Descripcion   Precio\n");
    for(int i=0;i<tamCo;i++)
    {
        printf("%d   %11s   %2.f\n",comidas[i].id,comidas[i].descripcion,comidas[i].precio);
    }
}
int cargarDescripcionComidas(char descripcion[],int id,eComida comidas[],int tamCo)
{
    int retorno=0;

    for(int i=0;i<tamCo;i++)
    {
        if(comidas[i].id==id)
        {
            strcpy(descripcion,comidas[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}
