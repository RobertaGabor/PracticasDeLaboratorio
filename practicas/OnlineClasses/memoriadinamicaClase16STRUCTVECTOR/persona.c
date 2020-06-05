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
    ePersona* nuevaPersona =(ePersona*) malloc(sizeof(ePersona));

    if(nuevaPersona!=NULL)
    {
        nuevaPersona->id=0;
        nuevaPersona->peso=0;
        nuevaPersona->sexo=' ';
        strcpy(nuevaPersona->nombre,"");/*campos limpios sin basura*/
    }

    return nuevaPersona;
}

ePersona* new_PersonWithInfo(int id,char* name,char sexo,float peso)
{
    ePersona* newP=NULL; /*SIEMPRE INICIALIZAR EN NULL, ADEMAS QUE ESTA DEVOLVIENDO ePersona NULL ES COMO 0*/

    newP=new_Person();/*si son correctos asigno lugar en memoria*/
    if(newP!=NULL)/*si hay memoria asigno datos*/
    {
        if(!(person_SetID(newP,id)
           &&person_SetNombre(newP,name)
           &&person_SetPeso(newP,peso)
           &&person_SetSexo(newP,sexo)))/*si uno devuelve 0 ya todo deviuelve 0, y el ! dice si el total es 0*/
        {
            free(newP);/*si esta algo mal libera espacio que pusimos de new_person*/
            newP=NULL;/*lo apuntamos a null asi el return devuelve DEVUELTA null*/
        }
    }

   return newP;
}

int person_SetID(ePersona* person,int id)/*CADA CAMPO DE STRUCT VA A TENER UN GETTER Y UN SETTER*/
{/*desde getter usamos el id ingresado y validamos que sea x condicion y si pasa, asignamos al campo id del puntero estructura*/
    int retorno=0;

    if(person!=NULL&&id>=0)
    {
        person->id=id;
        retorno=1;
    }

    return retorno;
}

int person_GetID(int* id,ePersona* person)/*carga id en el putnero ue pasamos*/
{/*primero cargamos todos los campos y aca asignamos el id de lo ingresado al puntero id para el setter*/
    int retorno=0;

    if(person!=NULL&&id!=NULL)
    {
        *id=person->id;
        retorno=1;
    }
    return retorno;
}

int person_SetNombre(ePersona* person,char* nombre)
{
    int retorno=0;

    if(person!=NULL&&nombre!=NULL&&strlen(nombre)>=3&&strlen(nombre)<20)
    {
        strcpy(person->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int person_GetNombre(char* nombre,ePersona* person)
{
    int retorno=0;

    if(person!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,person->nombre);
        retorno=1;
    }
    return retorno;
}

int person_SetPeso(ePersona* person,float peso)
{
    int retorno=0;

    if(person!=NULL&&peso>=30)
    {
        person->peso=peso;
        retorno=1;
    }

    return retorno;
}

int person_GetPeso(float* peso,ePersona* person)
{
    int retorno=0;

    if(person!=NULL&&peso!=NULL)
    {
        *peso=person->peso;
        retorno=1;
    }
    return retorno;
}

int person_SetSexo(ePersona* person,char sexo)
{
    int retorno=0;

    if(person!=NULL&&(sexo=='m'||sexo=='f'))
    {
        person->sexo=sexo;
        retorno=1;
    }

    return retorno;
}

int person_GetSexo(char* sexo,ePersona* person)
{
    int retorno=0;

    if(person!=NULL&&sexo!=NULL)
    {
        *sexo=person->sexo;
        retorno=1;
    }
    return retorno;
}
