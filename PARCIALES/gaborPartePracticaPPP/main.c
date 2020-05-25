#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAMNOTE 4
typedef struct{

int id;
char procesador[20];
char marca[20];
float precio;

}eNotebooks;

/*1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
 devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. **/

float aplicarDescuento (float precioProducto);

/*Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */

int contarCaracteres (char cadena[],char caracter);

/*Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos
desde el main. */

void ordenarNotebooks (eNotebooks notebooks[],int tamNote);
int main()
{
    float precioRemera=53;
    float precioConDescuento;
    int cantidadDeLetras;

    eNotebooks notebooks[TAMNOTE]={{10,"corei3","TCL",25000},{11,"moderadum","Lenovo",30000},{12,"celeron","Vga",14000},{13,"fushi","TCL",11000}};

    precioConDescuento=aplicarDescuento(precioRemera);
    printf("%2.f\n",precioConDescuento);

    cantidadDeLetras=contarCaracteres("Mauriom",'m');
    printf("%d\n",cantidadDeLetras);

    ordenarNotebooks(notebooks,TAMNOTE);
    printf("ID   PROCESADOR         MARCA  PRECIO\n");
    for(int i=0;i<TAMNOTE;i++)
    {
        printf("%d  %13s  %13s  %2.f\n",notebooks[i].id,notebooks[i].procesador,notebooks[i].marca,notebooks[i].precio);
    }

    return 0;
}
float aplicarDescuento (float precioProducto)
{
    float precioFinal=0;

    if(precioProducto!='0')
    {
       precioFinal=precioProducto-(float)(precioProducto*5/100);
    }

    return precioFinal;
}
int contarCaracteres (char cadena[],char caracter)
{
    int cantidad=0;

    for(int i=0;cadena[i]!='\0';i++)
    {
        cadena[i]=tolower(cadena[i]);
        if(cadena[i]==caracter)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void ordenarNotebooks (eNotebooks notebooks[],int tamNote)
{
    eNotebooks auxiliar;
    for(int i=0;i<tamNote-1;i++)
    {
        for(int j=i+1;j<tamNote;j++)
        {
            if(strcmp(notebooks[i].marca,notebooks[j].marca)>0)
            {
                auxiliar=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=auxiliar;
            }
            else
            {
                 if((strcmp(notebooks[i].marca,notebooks[j].marca)==0)&&notebooks[i].precio>notebooks[j].precio)
                {
                    auxiliar=notebooks[i];
                    notebooks[i]=notebooks[j];
                    notebooks[j]=auxiliar;
                }
            }
        }
    }
}
