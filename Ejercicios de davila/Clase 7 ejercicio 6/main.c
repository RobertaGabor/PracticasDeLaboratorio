#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*dado el texto almacenado en el array, escribir una funion que reciba un array su longitud,
 y que devuelva la cantidad de palabras que hay en el array*/
int contarPalabras (char array[],int tam,int* cantidad);
int main()
{
    char texto[]=" Hola juancete pepe  a aaa ";
    int tamano;
    int cantidad;
    tamano=strlen(texto);
    if(!contarPalabras(texto,tamano,&cantidad))
    {
        printf("Cantidad: %d",cantidad);
    }
    else
    {
        printf("No se pudo contar\n");
    }



    return 0;
}

int contarPalabras (char array[],int tam,int*cantidad)
{
    int i=0;/*i=0*/
    int j=i+1;/*j=i+1*/
    int contadorPalabras=0;
    int retorno=-1;
    if(array!=NULL&&tam>0&&cantidad!=NULL)
    {
        retorno=0;
        for(; i<tam; i++)
        {
                if(array[j]!='\0')
                {
                    if(array[i]==' '&&array[j]!=' ')
                    {
                        contadorPalabras++;
                    }
                }
            j++;
        }
       if(array[0]!=' '&&array['\0'-1]!=' ')
        {
            contadorPalabras++;
        }
    }
    *cantidad=contadorPalabras;
    return retorno;
}
