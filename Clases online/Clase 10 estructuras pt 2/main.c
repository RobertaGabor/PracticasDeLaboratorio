#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
typedef struct{

    int dia;
    int mes;
    int anio;//no usar ñ

}eFecha;

typedef struct{

int id;//4 bytes
char nombre[20];//20 bytes-->corta el ancho de palabra. cada 4 bytes,tiene que ser multiplo
int edad;//4 bytes
char sexo;//1 bytes-->asigna 36 directo en vez de 32(si eliminas sexo da 32). cuando agrego este byte extra cambia los multiplos de 4. por eso corta en 36
float sueldo;//8 bytes
eFecha fechaIngreso;
} eEmpleado;

void mostrarEmpleado (eEmpleado x);
void mostrarEmpleados (eEmpleado vec[],int tam);
void ordenarEmpleado (eEmpleado vec[],int tam);

int main()
{
    eEmpleado lista[TAM]={{2144,"Jose",23,'m',2313245,{12,05,1776}}/*cada uno es un empleado*/,
                         {8765,"Maria",34,'f',3141355,{23,03,1334}},
                         {9100,"pepe",55,'m',38478237,{11,02,1776}},
                         {3471,"susana",57,'f',384666,{10,02,1200}},
                         };//lista
    //puedo poner cada , de empleado enter y sigo el proximo juego de llaves abajo
    /*for(int i=0; i<TAM; i++)
    {
        printf("Ingrese id:\n");
        scanf("%d",&lista[i].id);

        printf("Ingrese nombre:\n");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("Ingrese su sexo:\n");
        fflush(stdin);
        scanf("%c",&lista[i].sexo);

        printf("Ingrese sueldo:\n");
        scanf("%f",&lista[i].sueldo);

        printf("Ingrese la edad:\n");
        scanf("%d",&lista[i].edad);

        printf("Ingrese fecha de ingreso dd/mm/aaa:\n");
        scanf("%d/%d/%d",&lista[i].fechaIngreso.dia,&lista[i].fechaIngreso.mes,&lista[i].fechaIngreso.anio);//el user tiene que poner la barra

    }*/

    /*for(int i=0;i<TAM;i++)
    {
       mostrarEmpleado(lista[i]);
    }*/
    printf("Desordenado\n");
    mostrarEmpleados(lista,TAM);

    ordenarEmpleado(lista,TAM);

    printf("Ordenado\n");
    mostrarEmpleados(lista,TAM);

    return 0;
}

void mostrarEmpleado(eEmpleado x)
{
    printf("%d %10s    %c   %11.2f     %d   %02d/%02d/%02d\n", x.id,x.nombre,x.sexo,x.sueldo,x.edad,x.fechaIngreso.dia,x.fechaIngreso.mes,x.fechaIngreso.anio);

}

void mostrarEmpleados (eEmpleado vec[],int tam)
{
    printf("__Listado de empleados facheros__\n");
    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    \n");
    for(int i=0;i<tam;i++)
    {
        mostrarEmpleado(vec[i]);
    }
}

void ordenarEmpleado (eEmpleado vec[],int tam)
{
    eEmpleado auxiliarEmpleado;//porque queres swaear TODOS los datos de un empleado a otro, no solo id, ese es el criterio
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(vec[i].sexo>vec[j].sexo)
            {
                auxiliarEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxiliarEmpleado;
            }
            else
            {
                 if(vec[i].sexo==vec[j].sexo&&vec[i].sueldo>vec[j].sueldo)//como es numerico con signos, si es caracter strcmp
                {/*if(strcmp (vec[i].nombre,vec[j].nombre)>0)*/
                    auxiliarEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxiliarEmpleado;

                }
            }
        }
    }
}
