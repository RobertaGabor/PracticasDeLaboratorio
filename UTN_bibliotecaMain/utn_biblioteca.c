#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            if(utn_getInt(&auxiliarResultado)==0&&auxiliarResultado<=maximo&&auxiliarResultado>=minimo)//si get ind devuelve 0 es numero. y se guarda en &auxiliar
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

int utn_scanGetInt (char ingreso[],int tam)//SIRVE PARA PEDIR NOMBRE O STRINGS
{
    int retorno=-1;
    char auxiliar[4500];

    if(ingreso!=NULL&&tam>0)
    {
        fflush(stdin);
        //devuelve null si no se pudo, por eso retorno si s elogro o no
        if(fgets(auxiliar,sizeof(auxiliar),stdin)!=NULL)
        {
            if(auxiliar[strlen(auxiliar)-1]='\n')
            {
                 auxiliar[strlen(auxiliar)-1]='\0';
            }
            if(strlen(auxiliar)<=tam)
            {
                strncpy(ingreso,auxiliar,tam)
                retorno=0;
            }
        }

    }

    return retorno;
}

int utn_getInt(int* numero)
{
    int retorno=1;
    char bufferString[50];
    if(numero!=NULL)
    {
        if(utn_scanGetInt(bufferString,sizeof(bufferString))==0&&utn_validarNumero(bufferString,sizeof(bufferString)))
        {
            retorno=0;
            *numero=atoi(bufferString);
        }
    }


    return retorno;
}

int utn_getFloat(float numero[])
{
    int retorno=1;
    char auxiliar[500];
    if(utn_scanGetInt(auxiliar,sizeof(auxiliar))==0&&utn_validarNumeroFloat(auxiliar)==1)
    {
        retorno=0;
        *numero=atof(auxiliar);
    }

    return retorno;

}

char utn_getLetra(char mensaje[])
{
    char letra;
    printf("%s",mensaje);
    scanf("%c",&letra);

    return letra;
}

int utn_validarNumero (char vector[],int tam)
{
    int retorno=1;
    int i=0;
    if(vector[0]=='-')
    {
        i=1;
    }

    for(;vector[i]!='\0'&&i<tam;i++)
    {
        if(vector[i]<'0'||vector[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_validarLetra (char vector[])
{
    int retorno=1;

    for(int i=0;vector[i]!='\0';i++)
    {
        if(vector[i]!=' '&&(vector[i]<'a'||vector[i]>'z')&&(vector[i]<'A'||vector[i]>'Z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_validarAlfanumerico (char vector[])
{
   int retorno=1;

    for(int i=0;vector[i]!='\0';i++)
    {
        if(vector[i]!=' '&&(vector[i]<'a'||vector[i]>'z')&&(vector[i]<'A'||vector[i]>'Z')&&(vector[i]<'0'||vector[i]>'9'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_validarTelefono (char vector[])
{
    int retorno=0;
    int retornoAuxiliar=0;
    int contadorGuion=0;

    for(int i=0;vector[i]!='\0';i++)
    {
        if(vector[i]!=' '&&vector[i]!='-'&&(vector[i]<'0'||vector[i]>'9'))
        {
            retornoAuxiliar=1;
        }
        else
        {
            if(vector[i]=='-')
            {
                contadorGuion++;
            }
        }
    }

    if(contadorGuion==1&&retornoAuxiliar==0)
    {
        retorno=1;
    }

    return retorno;
}

int utn_getStringNumeros(char mensaje[],char ingreso[])
{
    int retorno=0;
    char auxiliar[1000];
    utn_getString(mensaje,auxiliar);
    if(utn_validarNumero(auxiliar)==1)
    {
        strcpy(ingreso,auxiliar);
        retorno=1;
    }
    return retorno ;
}

int utn_getStringLetras(char mensaje[],char ingreso[])
{
    int retorno=0;
    char auxiliar[1000];
    utn_getString(mensaje,auxiliar);
    if(utn_validarLetra(auxiliar)==1)
    {
        strcpy(ingreso,auxiliar);
        retorno=1;
    }
    return retorno ;
}

void utn_getString (char mensaje[],char ingreso[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",ingreso);
}

void utn_inicializadorString (int vector[],int tam,int inicio)
{
    for(int i=0;i<tam;i++)
    {
        vector[i]=inicio;
    }
}

int utn_buscadorEspacio(int vector[],int tam,int buscado)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==buscado)
        {
            retorno=i;//Para despues saber la posicion en la que esta lo buscado
            break;
        }
    }

    return retorno;
}

int utn_numeroMayor(int x, int y,int* mayor)
{
    int retorno;

    if(x==y)
    {
        retorno=0;
    }
    else
    {
        retorno=1;
        if(x>y)
        {
            *mayor=x;
        }
        else
        {
            if(y>x)
            {
                *mayor=y;
            }
        }
    }

    return retorno;

}
int utn_getNumeroFloat(float* resultado,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos)
{
    int i;
    float auxiliarResultado;
    int validacion;
    validacion=-1;

    if(resultado!=NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo&&reintentos>=0)
    {
        for(i=0; i<=reintentos; reintentos--)
        {
            printf("%s",mensaje);
            if(utn_getFloat(&auxiliarResultado)==0&&auxiliarResultado<=maximo&&auxiliarResultado>=minimo)
            {
                *resultado=auxiliarResultado;
                validacion=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                break;
            }
        }
    }

    return validacion;
}
int utn_validarNumeroFloat (char vector[])
{
    int retorno=1;
    int contadorPunto=0;
    int retornoAuxiliar=1;
    int i=0;
    if(vector[0]=='-')
    {
        i=1;
    }

    for(;vector[i]!='\0';i++)
    {
        if(vector[i]<'0'||vector[i]>'9')
        {
            retornoAuxiliar=0;
            break;
        }
        else
        {
            if(vector[i]=='.')
            {
                contadorPunto++;
            }
        }
    }

    if(contadorPunto==1&&retornoAuxiliar==1)
    {
        retorno=0;
    }
    return retorno;
}
int utn_inicializadorFloat (float vector[],int tam,float inicio)
{
    int retorno=-1;
    if(vector!=NULL&&tam>0)
    {
        retorno=0;
        for(int i=0;i<tam;i++)
        {
            vector[i]=inicio;
        }
    }

    return retorno;
}
