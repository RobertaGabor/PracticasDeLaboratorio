#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct{

int id;
char nombre[20];
char sexo;
float peso;

}ePersona;

int initPeople(ePersona** vec,int tam);/*paso lista y el tipo de putnero a puntero y el tamanio*/
int findSpot(int* indice,ePersona** vec,int tam);
int showPerson(ePersona* persona);
int showPeople(ePersona** vec,int tam);

int main()
{
    //ePersona* lista = (ePersona*)malloc(TAM*sizeof(ePersona)); /*VECTOR DE ESTRUCTURA*/
    ePersona** lista2= (ePersona**)malloc(TAM*sizeof(ePersona*));/*VECTOR A PUNTEERO*/
    ePersona* auxPersona;
    if(lista2==NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Se pudo conseguir memoria\n");
    }

    if(initPeople(lista2,TAM))
    {
        printf("Se inicializaron las personas\n");
    }
    else
    {
        printf("No se inicializarion\n");
    }

    int indice;

    findSpot(&indice,lista2,TAM);

    if(indice!=-1)
    {
        auxPersona=(ePersona*)malloc(sizeof(ePersona));/*guarda datos de una estructura*/
        auxPersona->id=1234;
        auxPersona->peso=78.6;
        strcpy(auxPersona->nombre,"Juan");
        auxPersona->sexo="m";

        *(lista2+indice)=auxPersona;

        showPeople(lista2,TAM);
    }





    return 0;
}

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
