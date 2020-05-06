#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

int main()
{
    int resultado;
    int numero;

    /*char ingreso[20];
    int validaTelefono;
    fgets(ingreso,20,stdin);
    for(int i=0;i<20;i++)
    {
        if(ingreso[i]=='\0'-1)
        {
            ingreso[i]='\0';
        }
    }

    validaTelefono=utn_validarTelefono(ingreso);
    if(validaTelefono==1)
    {
        printf("Es un telefono\n");
    }
    else
    {
        printf("No es un telefono\n");
    }*/

    resultado=utn_getNumero(&numero,"Ingrese un numero entre 1 y 10\n","Error, ingrese un numero de 1 a 10\n",1,10,2);

    if(resultado==0)
    {
        printf("El numero ingresado es: %d\n",numero);
    }
    else
    {
        printf("Ocurrio un error o se le acabaron las repeticiones. Reintente desde cero\n");
    }


    return 0;
}
