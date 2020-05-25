#include <stdio.h>
#include <stdlib.h>
#include "C:\ejercicios en C\PracticasDeLaboratorio\UTN_bibliotecaMain\utn_biblioteca.h"
void menuPrincipal(int* opcion);
int impArray (float arrayTemperatura[],int tam);
int cargarTemperatura (float vector[],int tam);

int main()
{
    float temperatura[31];
    int opcionElegida;
    utn_inicializadorFloat(temperatura,31,0);
    do
    {

        menuPrincipal(&opcionElegida);

        switch(opcionElegida)
        {
        case 1:
            impArray(temperatura,31);
            break;
        case 2:
            cargarTemperatura(temperatura,31);
            break;
        case 3:
            break;
        default:
            printf("Opcion incorrecta elija otro numero\n");
            break;

        }
    }while(opcionElegida!=3);



    return 0;
}
void menuPrincipal(int* opcion)
{
    printf("********Menu de opciones*******\n");
    printf("1-Imprimir array\n");
    printf("2-Cargar array\n");
    printf("3-Salir\n");

    scanf("%d",opcion);
}


int impArray (float arrayTemperatura[],int tam)
{
    int retorno=-1;
    if(arrayTemperatura!=NULL&&tam>0)
    {
        retorno=0;
        for(int i=0;i<tam;i++)
        {
            printf("Dia: %d   Temp %2.f\n",i,arrayTemperatura[i]);
        }
    }

    return retorno;
}

int cargarTemperatura (float vector[],int tam)
{
    int retorno=-1;
    int validacion;
    int dia;
    float temperatura;
    if(vector!=NULL&&tam>0)
    {
        retorno=0;
        validacion=utn_getNumero(&dia,"Ingrese dia:\n","Error ingrese un dia del 1 al 31\n",1,31,2);
        if(!validacion)
        {
            validacion=utn_getNumeroFloat(&temperatura,"Ingrese temperatura del dia:\n","Error ingrese un caracter numerico",-100,100,2);
            if(!validacion)
            {
                vector[dia-1]=temperatura;
            }
        }
    }
    return retorno;
}
