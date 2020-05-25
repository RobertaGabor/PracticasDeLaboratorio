#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"

void informar(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    char opcionInformes;
    char seguir='s';

    do
    {
        opcionInformes=menuInformes();
        switch(opcionInformes)
        {
        case 'a':
            informeEmpleadosAnio(vec,tam,sectores,tamSec,obras,tamObr);
            break;
        case 'b':
            informarEmpleadosVarones(vec,tam,sectores,tamSec,obras,tamObr);
            break;
        case 'c':
            informarTotalSueldos(vec,tam);
            break;
        case 'd':
            informarEmpleadosSector(vec,tam,sectores,tamSec,obras,tamObr);
            break;
        case 'e':
            informarEmpleadosXSector(vec,tam,sectores,tamSec,obras,tamObr);
            break;
        case 'f':
            informarSueldoTotalSector(vec,tam,sectores,tamSec);
            break;
        case 'g':
            informarMayorSueldoSector(vec,tam,sectores,tamSec);
            break;
        case 'h':
            informarMayorSueldoXSector(vec,tam,sectores,tamSec);
            break;
        case 'i':
            modificarSueldoPorcentaje(vec,tam,sectores,tamSec);
            break;
        case 'j':
            sectorConMasSalario(vec,tam,sectores,tamSec);
            break;
        case 'k':
            break;
        case 'l':
            break;
        case 's':
            printf("Seguro que desea salir?\n");
            printf("Ingrese s para cancelar, ingrese cualquier letra distinta para salir\n");
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        default:
            printf("Ingrese un informe valido\n");
            break;
        }
        system("pause");
    }
    while(seguir=='s');
}

void informeEmpleadosAnio(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    int anio;
    system("cls");
    printf("***Informe de empleados por ingreso****\n\n",anio);
    printf("Ingrese anio: ");
    scanf("%d",&anio);
    int flag=0;


    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    SECTOR    OBRA SOCIAL\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0&&vec[i].fechaIngreso.anio==anio)
        {
            mostrarEmpleado(vec[i],sectores,tamSec,obras,tamObr);
            flag=1;
        }
    }

    if(!flag)
    {
        printf("No hay empleados que ingresaron en ese anio\n");
    }
}

void informarEmpleadosVarones(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    system("cls");
    printf("***Informe de empleados varones****\n\n");
    int flag=0;

    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    SECTOR    OBRA SOCIAL\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0&&vec[i].sexo=='m')
        {
            mostrarEmpleado(vec[i],sectores,tamSec,obras,tamObr);
            flag=1;
        }
    }

    if(!flag)
    {
        printf("No hay empleados varones que mostrar\n");
    }
}

void informarTotalSueldos(eEmpleado vec[],int tam)
{
    system("cls");
    printf("****Sueldo total a pagar a los empleados****\n");
    float sueldoTotal=0;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            sueldoTotal+=vec[i].sueldo;
        }
    }
    printf("Total a pagar: $%2.f\n",sueldoTotal);
}

void informarEmpleadosSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    int sector;
    int flag=0;
    system("cls");
    printf("******Buscar empleados por sector*****\n");
    mostrarSectores(sectores,tamSec);
    printf("Ingrese sector: ");
    scanf("%d",&sector);
    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO   SECTOR    OBRA SOCIAL\n");
    for(int i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0&&empleados[i].idSector==sector)
        {
            mostrarEmpleado(empleados[i],sectores,tamSec,obras,tamObr);
            flag=1;
        }
    }

    if(!flag)
    {
        printf("No hay empleados en este sector\n");
    }
}

void informarEmpleadosXSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    for(int i=0;i<tamSec;i++)
    {
        int flag=0;
        printf("\n\nSector %13s:\n",sectores[i].descripcion);
        printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO   SECTOR    OBRA SOCIAL\n");
        for(int j=0;j<tam;j++)
        {
            if(empleados[j].isEmpty==0&&empleados[j].idSector==sectores[i].id)
            {
                mostrarEmpleado(empleados[j],sectores,tamSec,obras,tamObr);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("\nNo hay empleados en este sector\n");
        }
    }
    printf("\n\n\n");
}


int menuInformes(void)
{
    char opcion;
    system("cls");
    printf("*****Menu de informes****\n");
    printf("a-LISTAR EMPLEADOS DE UN ANIO\n");
    printf("b-LISTAR EMPLEADOS VARONES\n");
    printf("c-INFORMAR LA SUMA TOTAL DE SUELDOS\n");
    printf("d-INFORMAR EMPLEADOS POR SECTOR\n");
    printf("e-INFORMAR EMPLEADOS SEPARADOS POR SECTOR \n");
    printf("f-INFORMAR SUELDO TOTAL DE UN SECTOR\n");
    printf("g-INFORMAR MAYOR SUELDO SECTOR\n");
    printf("h-INFORMAR MAYOR SUELDO X CADA SECTOR\n");
    printf("i-MODIFICAR SUELDO X SECTOR\n");
    printf("j-INFORMAR SECTOR CON MAS SALARIO\n");
    printf("k-INFORMAR \n");
    printf("l-INFORMAR \n");
    printf("m-INFORMAR \n");
    printf("s-SALIR\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
void informarSueldoTotalSector(eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    int sector;
    float totalSueldo=0;
    char descripcion[20];

    system("cls");
    printf("******Buscar empleados por sector*****\n");
    mostrarSectores(sectores,tamSec);
    printf("Ingrese sector: ");
    scanf("%d",&sector);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0&&empleados[i].idSector==sector)
        {
            totalSueldo=totalSueldo+empleados[i].sueldo;
        }
    }
    cargarDescripcionSector(descripcion,sector,sectores,tamSec);
    printf("\nTotal de sueldo en el sector %13s: $%2.f\n",descripcion,totalSueldo);
}
void informarMayorSueldoSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    system("cls");
    int flag=0;
    int aux;
    float mayorSueldo;
    int idSector;
    char nombreSector[25];

    mostrarSectores(sectores,tamSec);
    printf("Ingrese id del sector: ");
    scanf("%d",&idSector);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0&&empleados[i].idSector==idSector)
        {
            aux=0;
            if(empleados[i].sueldo>mayorSueldo||aux==0)
            {
                mayorSueldo = empleados[i].sueldo;
                flag=1;
                aux=1;
            }
        }
    }

    cargarDescripcionSector(nombreSector,idSector,sectores,tamSec);
    if(flag)
    {
         printf("\n\nEl mayor sueldo de %13s es %2.f\n\n",nombreSector,mayorSueldo);
    }
    else
    {
        printf("\nNo hay empleados en este sector\n\n");
    }

}

void informarMayorSueldoXSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    system("cls");
    float mayorSueldo;
    int aux;
    printf("****Informar mayor sueldo x sector******\n");
    for(int i=0;i<tamSec;i++)
    {

        mayorSueldo=0;
        printf("\n\nSector %13s:\n",sectores[i].descripcion);

        for(int j=0; j<tam; j++)
        {
            if(empleados[j].isEmpty==0&&empleados[j].idSector==sectores[i].id)
            {
                aux=0;
                if(empleados[j].sueldo>mayorSueldo||aux==0)
                {
                    mayorSueldo = empleados[j].sueldo;
                    aux=1;
                }
            }
        }

        printf("El mayor sueldo es %2.f\n",mayorSueldo);
        printf("\n\n\n");
        printf("\n------------------------------------------------------------\n");
    }

}

void modificarSueldoPorcentaje (eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    system("cls");
    int flag=0;
    int idSector;
    int porcentaje;
    float aumento;

    printf("\nIngrese id del sector: ");
    mostrarSectores(sectores,tamSec);
    scanf("%d",&idSector);

    printf("\nIngrese porcentaje aumento: ");
    scanf("%d",&porcentaje);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0&&empleados[i].idSector==idSector)
        {
            aumento=empleados[i].sueldo*porcentaje/100;
            empleados[i].sueldo+=aumento;
            flag=1;
        }
    }

    if(flag)
    {
        printf("\nSe han modificado los sueldo con exito\n ");
    }
    else
    {
        printf("No hay empleados en este sector\n");
    }
}

float obtenerTotalSueldosSector(eEmpleado empleados[],int tam,int idSector)
{
    float acumuladorSueldos=0;
    for(int i=0;i<tam;i++)
    {
        if(empleados[i].idSector==idSector && empleados[i].isEmpty==0)
        {
            acumuladorSueldos+=empleados[i].sueldo;
        }
    }


    return acumuladorSueldos;
}

void sectorConMasSalario (eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    float mayorSueldo;
    float vectorTotales[tamSec];

    for(int s=0;s<tamSec;s++)
    {
        vectorTotales[s]=obtenerTotalSueldosSector(empleados,tam,sectores[s].id);
    }

    for(int i=0;i<tamSec;i++)
    {
        if(i==0||mayorSueldo<vectorTotales[i])
        {
            mayorSueldo=vectorTotales[i];
        }
    }

    printf("Sectores o sectores con mayor salario total: \n");
    for(int i=0;i<tamSec;i++)
    {
        if(vectorTotales[i]==mayorSueldo)
        {
            printf("%11s\n",sectores[i].descripcion);
        }
    }



}
