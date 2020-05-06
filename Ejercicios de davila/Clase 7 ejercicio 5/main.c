#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*Desarrollo de la función imprimirNumeros()
Desarrollo de la función solicitarNumeros()
 Desarrollo de la función borrarImpares()
 Desarrollo de la función ordenarNumeros()
 Progrma que pida 5 numeros al usuario en un array, borrar los impares y poner 0
 imprimirlo y ordenar de menor a mayor y volver a imprimir.*/
int solicitarNumero (int* numero,char mensaje[],char mensajeError[],int reintentos);
int validarNumero (char numeroValidado[],int tam);
int pedirCharInt (char cadenaInt[],int tam);
int obtenerNumero (int* numeroObtenido);
void menuOpciones(int*  opcion);
void borrarImpares (int* arrayLleno,int tam);
void mostrarLista (int* array,int tam);
void ordenarLista (int* array,int tam);
int valorEnImpar (int x);
int main()
{
    int numeros[5];
    int opcion;
    int flag;

    do
    {
        menuOpciones(&opcion);
        switch(opcion)
        {

        case 1:

            for(int i=0; i<5; i++)
            {
                if((solicitarNumero(&numeros[i],"Ingrese un numero","Error ingrese otro valor numerico",3))==-1)
                {
                    printf("Error de programa, vuelva a inicializarlo\n");
                    flag=0;
                    break;
                }
                flag=1;
            }
            break;

        case 2:
            if(flag==1)
            {
                /*funcion de imprimir*/
                mostrarLista(numeros,5);
            }
            else
            {
                printf("Primero cargue los numeros para mostrarlos\n");
            }
            break;

        case 3:
            /*funcion de sacar impares*/
            if(flag==1)
            {
                borrarImpares(numeros,5);
            }
            else
            {
                printf("Primero cargue los numeros para eliminar los impares\n");
            }

            break;

        case 4:
            /*funcion ordenar*/
            if(flag==1)
            {
                ordenarLista(numeros,5);
            }
            else
            {
                printf("Primero cargue los numeros para ordenar la lista\n");
            }
            break;

        case 5:
            break;

        default:
            printf("Numero no valido, ingrese otro numero\n");
            fflush(stdin);
            break;

        }

    }while(opcion!=5);

    return 0;
}

void menuOpciones(int*  opcion)
{
    printf("******Menu de opciones*******\n");
    printf("1-Carga numeros\n");
    printf("2-Imprimir lista de numeros\n");
    printf("3-Eliminar impares\n");
    printf("4-Ordenar de menor a mayor\n");
    printf("5-Salir\n");

    scanf("%d",opcion);
}



int solicitarNumero (int* numero,char mensaje[],char mensajeError[],int reintentos)
{
    int retorno=-1;
    int auxiliar;
    if(numero!=NULL&&mensaje!=NULL&&mensajeError!=NULL)
    {

            while(reintentos>0)
            {
                printf("%s\n",mensaje);
                if(obtenerNumero(&auxiliar)==0)
                {
                    *numero=auxiliar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s\n",mensajeError);
                    reintentos--;
                }
            }
    }

    return retorno;
}
int obtenerNumero (int* numeroObtenido)
{
    /*pedir un char guardarlo validarlo y devolverlo como int*/
    int retorno=-1;
    char auxiliar[500];
        /*validar*/
        if((pedirCharInt(auxiliar,500)==0)&&((validarNumero(auxiliar,strlen(auxiliar)))==0))
        {
            char extra[strlen(auxiliar)];
            strcpy(extra,auxiliar);

            if(atoi(extra)==0)
            {
                if(extra==0)
                {
                   *numeroObtenido=0;
                   retorno=0;
                }

            }
            else
            {
                *numeroObtenido=atoi(extra);
                retorno=0;
            }

        }

    return retorno;
}

int pedirCharInt (char cadenaInt[],int tam)
{
    int retorno=-1;
    fflush(stdin);
    if((fgets(cadenaInt,tam,stdin))!=NULL)
    {
        for(int i=0;i!='\0';i++)
        {
            if(cadenaInt[i]=='\0'-1)
            {
                cadenaInt[i]='\0';
            }
        }
        retorno=0;
    }

    return retorno;
}

int validarNumero (char numeroValidado[],int tam)/*strlen de auxiliar en tam*/
{
    int retorno;
    int i;
    if(numeroValidado!=NULL&&tam>0)
    {
        if(numeroValidado[0]=='-')
        {
            i=1;
        }
        else
        {
            i=0;
        }

        for(;i!='\0';i++)
        {
            if(numeroValidado[i]<'0'||numeroValidado[i]>'9')
            {
                retorno=-1;
                break;
            }
        }
        retorno=0;
    }

    return retorno;
}
void mostrarLista (int* array,int tam)
{
    printf("\n\n");
    for(int i=0;i<tam;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n\n");
}
void borrarImpares (int* arrayLleno,int tam)
{
    for(int i=0;i<tam;i++)
    {
        if(!valorEnImpar(arrayLleno[i]))
        {
            arrayLleno[i]=0;
        }

    }
}

int valorEnImpar (int x)
{
    int retorno=0;/*impar*/

        if(x%2==0)
        {
            retorno=1;/*par*/
        }

    return retorno;
}

void ordenarLista (int* array,int tam)
{
    int auxiliar;
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(array[i]>array[j])//como son numeros puedo igualar directamente
            {
                auxiliar=array[i];
                array[i]=array[j];
                array[j]=auxiliar;
            }
        }
    }
}
