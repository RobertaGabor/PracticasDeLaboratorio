#include "fontecristo.h"
#include <stdio.h>
#include <stdlib.h>

int numerosPares(int a)
{
    int i;
    int flag;
    int respuesta;

    flag=0;

    for(i=0;i<a;i++)
    {
        if(i%2==0)
        {
            flag++;
        }
    }
    respuesta=flag;
    return respuesta;

}

int numerosImpares(int a)
{
    int i;
    int flag;
    int respuestaImpares;

    flag=0;

    for(i=0;i<a;i++)
    {
        if(i%2!=0)
        {
            flag++;
        }
    }
    respuestaImpares=flag;
    return respuestaImpares;
}

int numerosDivisible(int a)
{
    int i;
    int respuestaDivisibles;
    int flag;

    flag=0;

    for(i=1;i<101;i++)
    {
        if(i%a==0)
        {
            flag++;
        }
    }
    respuestaDivisibles=flag;
    return respuestaDivisibles;
}

void numeroPrimo(int a)
{
    int i;
    int flag;

    flag=0;//primo

    for(i=2;i<a;i++)
    {
        if(a%i==0)
        {
            flag=1;//no primo
            break;
        }
    }
    if(flag==0)
    {
        printf("El numero es primo\n");
    }
    else
    {
        printf("El numero no es primo\n");
    }
}

int primosTotales(int a)
{
    int auxiliar;
    int i;
    int flag;
    int respuestaPrimosTotales;
    int contadorFlag;

    contadorFlag=0;

    for(i=0;i<a;a--)
    {
        flag=0;
        for(auxiliar=a-1;auxiliar>1;auxiliar--)
        {
            if(a%auxiliar==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            contadorFlag++;
        }
    }
    respuestaPrimosTotales=contadorFlag;
    return respuestaPrimosTotales;
}

