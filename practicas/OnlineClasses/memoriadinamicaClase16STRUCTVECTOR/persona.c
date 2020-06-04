#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "persona.h"

int initPeople(ePersona** vec,int tam)
{
    int retorno=0;
    if(vec!=NULL&&tam>0)
    {
        retorno=1;
        for(int i=0;i<tam;i++)
        {
            *(vec+i)=NULL;/*el asterisco uso para modificar la direcciond e memoria, y el i porque lista es la direccion de memoria
            del primer elemento, si sumamos por iteracion va yendo a las otras direcciones*/
        }
    }
    return retorno;
}

int findSpot(int* indice,ePersona** vec,int tam)
{
    int retorno=0;
    if(vec!=NULL&&tam>0&&indice!=NULL)/*si en la llamada hay algo*/
    {
        *indice=-1;
        retorno=1;
        for(int i=0;i<tam;i++)
        {
            if(*(vec+i)==NULL)/*porque inicializamos todos los putneros en null, sino tiene una direccion de memoria*/
            {
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}

int showPeople(ePersona** vec,int tam)
{
    int retorno=0;
    if(vec!=NULL&&tam>0)
    {
        retorno=1;
        for(int i=0;i<tam;i++)
        {
            if(*(vec+i)!=NULL)
            {
                showPerson(*(vec+i));
            }
        }
    }
    return retorno;
}

int showPerson(ePersona* persona)
{
    int retorno=0;
    if(persona!=NULL)
    {
      retorno=1;
      printf("%d%10s  %c  %.2f\n",persona->id,persona->nombre,persona->sexo,persona->peso);
    }
    return retorno;
}

ePersona* new_Person()/*para usarlo cada vez que se quiere crear, en vez de pedir siempre malloc VACIO*/
{
    return (ePersona*) malloc(sizeof(ePersona));
}

ePersona* new_PersonWithInfo(int id,char* name,char sexo,float peso)/*en otra funcion donde pedimos vereficamos validacion de TIPO letras, num etc*/
{
    ePersona* newP=NULL; /*SIEMPRE INICIALIZAR EN NULL, ADEMAS QUE ESTA DEVOLVIENDO ePersona NULL ES COMO 0*/
    //if(validarId(id)&& validarName(name)&& validarSex(sexo)&&validarWeight(peso))/*valido datos correctos de parametros*/
    //{faltan las validaciones
        newP=new_Person();/*si son correctos asigno lugar en memoria*/
        if(newP!=NULL)/*si hay memoria asigno datos*/
        {

            newP->peso=peso;
            strcpy(newP->nombre,name);
            newP->sexo='m';
        }
   //}

   return newP;
}

int person_SetID(ePersona* person,int id)/*CADA CAMPO DE STRUCT VA A TENER UN GETTER Y UN SETTER*/
{
    int retorno=0;

    if(person!=NULL&&id>=0)
    {
        person->id=id;
        retorno=1;
    }

    return retorno;
}

