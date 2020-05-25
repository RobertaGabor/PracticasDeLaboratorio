#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "eAuto.h"
#include "eColor.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "informes.h"

int menuInformes (void)
{
    system("cls");
    int opcion;
    printf("*****Menu informes*****\n");
    printf("1-Mostrar autos segun color a eleccion\n");
    printf("2-Mostrar autos segun marca a eleccion\n");
    printf("3-Informar el/los autos mas viejos\n");
    printf("4-Mostrar todos los autos divididos por marcas\n");
    printf("5-Cantidad de autos segun color y marca\n");
    printf("6-Mostrar la o las marcas mas elegidas por los clientes\n");
    printf("7-Trabajos realizados a un auto\n");
    printf("8-Mostrar el total los servicios realizados a un auto a elegir\n");
    printf("9-Mostrar los autos que realizaron un servicio a elegir\n");
    printf("10-Mostrar todos los servicios realizados en una fecha a eleccion\n");
    printf("0-Salir\n");
    printf("Que opcion desea?: ");
    scanf("%d",&opcion);

    return opcion;

}

void mostrarAutosSegunColor(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    system("cls");
    int colorElegido;
    char descripcion[20];
    int flag=0;
    mostrarColores(colores,tamCol);
    if(getInt(&colorElegido,"Ingrese ID del color a elegir: ","Error debe ser un entero entre 5000 y 5004",5000,5004,0))
    {
        system("cls");
        cargarDescripcionColor(descripcion,colorElegido,colores,tamCol);
        printf("**********Listado de Autos de color %s*********\n",descripcion);
        printf(" ID         COLOR       MARCA   MODELO    PATENTE     CLIENTE\n");
        for(int i=0; i<tamAu; i++)
        {
            if(autos[i].isEmpty==0&&autos[i].idColor==colorElegido)
            {
                mostrarAuto(autos[i],colores,tamCol,marcas,tamMar,clientes,tamCli);
                flag=1;
            }

        }
    }
    else
    {
        printf("*****ID de color Invalido*****\n");
    }

    if(!flag)
    {
        printf("\n*****No hay autos de ese color*****\n");
    }
}

void mostrarAutosSegunMarca(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    system("cls");
    int marcaElegida;
    char descripcion[20];
    int flag=0;
    mostrarMarcas(marcas,tamMar);
    if(getInt(&marcaElegida,"Ingrese ID de la marca a elegir: ","Error debe ser un entero entre 1000 y 1004",1000,1004,0))
    {
        system("cls");
        cargarDescripcionMarca(descripcion,marcaElegida,marcas,tamMar);
        printf("**********Listado de Autos de la marca %s*********\n",descripcion);
        printf(" ID         COLOR       MARCA   MODELO    PATENTE     CLIENTE\n");
        for(int i=0; i<tamAu; i++)
        {
            if(autos[i].isEmpty==0&&autos[i].idMarca==marcaElegida)
            {
                mostrarAuto(autos[i],colores,tamCol,marcas,tamMar,clientes,tamCli);
                flag=1;
            }

        }
    }
    else
    {
        printf("*****ID de marca Invalido*****\n");
    }

    if(!flag)
    {
        printf("\n*****No hay autos de esa marca*****\n");
    }
}

void autoMasViejo (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    system("cls");
    int flag=0;
    int menorModelo;
    for(int i=0;i<tamAu;i++)
    {
        if((i==0||menorModelo>autos[i].modelo)&&autos[i].isEmpty==0)
        {
            menorModelo=autos[i].modelo;
            flag=1;
        }
    }
    printf("*****Modelo o modelos mas viejos*****\n");
    printf(" ID         COLOR       MARCA   MODELO    PATENTE     CLIENTE\n");

    for(int j=0;j<tamAu;j++)
    {
        if(autos[j].modelo==menorModelo)
        {
            mostrarAuto(autos[j],colores,tamCol,marcas,tamMar,clientes,tamCli);
        }
    }

    if(!flag)
    {
        printf("*****No hay autos que listar*****\n");
    }
}

void mostrarAutoMarcas(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    char descripcionMarca[20];
    system("cls");
    printf("**********Listado de Autos por marca*********\n\n\n");


    for(int i=0; i<tamMar; i++)
    {
        int flag=0;
        cargarDescripcionMarca(descripcionMarca,marcas[i].idMarca,marcas,tamMar);
        printf("*****Autos de la marca: %s\n",descripcionMarca);
        printf(" ID         COLOR       MARCA   MODELO    PATENTE     CLIENTE\n");
        for(int j=0;j<tamAu;j++)
        {
            if(autos[j].isEmpty==0&&autos[j].idMarca==marcas[i].idMarca)
            {
                mostrarAuto(autos[j],colores,tamCol,marcas,tamMar,clientes,tamCli);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("\n*****No hay autos ingresados de esa marca*****\n");
        }

        printf("\n\n------------------------------------------------------------\n\n");

    }
}

void cantidadSegunMarcayColor(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    system("cls");
    int marcaElegida;
    int colorElegido;
    char descripcionMarca[20];
    char descripcionColor[20];
    int contador=0;

    printf("*****Cantidad segun color y marca*****\n");
    mostrarMarcas(marcas,tamMar);
    if(getInt(&marcaElegida,"Ingrese ID de la marca que desea seleccionar: ","Error debe ingresar un entero entre 1000 y 1004",1000,1004,0))
    {
        mostrarColores(colores,tamCol);
        if(getInt(&colorElegido,"Ingrese ID del color que desea elegir: ","Error debe ingresar un entero entre 5000 y 5004",5000,5004,1))
        {
            for(int i=0;i<tamAu;i++)
            {
                if(autos[i].idColor==colorElegido&&autos[i].idMarca==marcaElegida&&autos[i].isEmpty==0)
                {
                    contador++;
                }
            }
        }
    }
    cargarDescripcionColor(descripcionColor,colorElegido,colores,tamCol);
    cargarDescripcionMarca(descripcionMarca,marcaElegida,marcas,tamMar);
    printf("\n\nLa cantidad de autos marca %10s   y color %10s es: %d\n\n",descripcionMarca,descripcionColor,contador);
}

void marcaMasAtendida(eAuto autos[],int tamAu,eMarca marcas[],int tamMar)
{
    cantidadPorMarca marcasAutos[tamMar];
    int mayorMarca;
    int idMayor;
    int contador;
    char marcaMayor[20];

    for(int i=0;i<tamMar;i++)
    {
        contador=0;
        marcasAutos[i].idMarca=marcas[i].idMarca;
        for(int j=0;j<tamAu;j++)
        {
            if(autos[j].isEmpty==0&&(autos[j].idMarca==marcasAutos[i].idMarca))
            {
                contador++;
            }
        }
        marcasAutos[i].cantidad=contador;
    }

    for(int c=0;c<tamMar;c++)
    {
        if(c==0||mayorMarca<marcasAutos[c].cantidad)
        {
            mayorMarca=marcasAutos[c].cantidad;
            idMayor=marcasAutos[c].idMarca;
        }
    }
    cargarDescripcionMarca(marcaMayor,idMayor,marcas,tamMar);
    printf("\n*****La marca mas elegida por los clientes es: %s*****\n",marcaMayor);
}

void mostrarTrabajosDeUnAuto (eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra)
{
    system("cls");
    char patenteElegida[20];
    if(getPatente(patenteElegida,20,"Ingrese patente a buscar: ","Error. ingrese patente valida",0))
    {
        system("cls");
        printf("*****Trabajos de la patente %10s\n",patenteElegida);
        printf("ID         PATENTE     FECHA        SERVICIO\n");
        for(int i=0;i<tamTra;i++)
        {
            if((strcmp(patenteElegida,trabajo[i].patente)==0)&&(trabajo[i].isEmpty==0))
            {
                mostrarTrabajo(trabajo[i],servicio,tamServ);
                printf("\n-----------------------------------------------------\n");
            }
        }
    }
}

void mostrarServiciosDeUnAuto (eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra)
{
    system("cls");
    char patenteElegida[20];
    int contadorServicios=0;

    if(getPatente(patenteElegida,20,"Ingrese patente a buscar: ","Error. ingrese patente valida",0))
    {
        system("cls");
        for(int i=0;i<tamTra;i++)
        {
            if(strcmp(patenteElegida,trabajo[i].patente)==0&&trabajo[i].isEmpty==0)
            {
                for(int j=0;j<tamServ;j++)
                {
                    if(trabajo[i].idServicio==servicio[j].idServicio)
                    {
                        contadorServicios+=servicio[j].precio;
                    }
                }

            }
        }
        printf("\n\n*****Suma de los servicios de la patente %10s: %d*****\n\n",patenteElegida,contadorServicios);
    }
}

void mostrarAutosDeUnServicio (eServicio servicio[],int tamServ,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,eTrabajo trabajos[],int tamTra)
{
    system("cls");
    int idServicio;
    int flag=0;
    char descripcionServicio1[25];
    mostrarServicios(servicio,tamServ);
    if(getInt(&idServicio,"Ingrese ID del servicio: ","Error debe ingresar un entero entre 20000 y 20003",20000,20003,0))
    {
        system("cls");
        cargarDescripcionServicio(descripcionServicio1,idServicio,servicio,tamServ);
        printf("*****Autos que realizaron el servicio %10s\n",descripcionServicio1);
        printf("\nID         COLOR      MARCA      MODELO    PATENTE    CLIENTE   FECHA\n\n");

        for(int i=0;i<tamTra;i++)
        {
            if(trabajos[i].isEmpty==0&&trabajos[i].idServicio==idServicio)
            {
                mostrarAutoConFecha(autos[i],colores,tamCol,marcas,tamMar,clientes,tamCli,trabajos[i]);
                printf("\n------------------------------------------------------------------------------\n");
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\n*****No hay autos que listar*****\n\n");
        }
    }
}


void mostrarServiciosDeUnaFecha (eServicio servicios[],int tamServ,eTrabajo trabajos[],int tamTra)
{
    system("cls");
    int dia;
    int mes;
    int anio;
    int flag=0;

    if(getInt(&dia,"Ingrese dia de ingreso: ","Error debe ingresar un dia del 1 al 31",1,31,1)
    &&getInt(&mes,"Ingrese mes de ingreso: ","Error debe ingreaar un numero del 1 al 12",1,12,1)
    &&getInt(&anio,"Ingrese anio de ingreso: ","Error ingrese un anio valido",1000,2020,1))
    {
        system("cls");
        printf("\n*****Servicios realizados en la fecha %2.d/%2.d/%d*****\n\n",dia,mes,anio);
        printf("ID         PATENTE     FECHA        SERVICIO\n");
        for(int i=0;i<tamTra;i++)
        {
            if(trabajos[i].isEmpty==0&&trabajos[i].fecha.dia==dia&&trabajos[i].fecha.mes==mes&&trabajos[i].fecha.anio==anio)
            {
                mostrarTrabajo(trabajos[i],servicios,tamServ);
                printf("\n----------------------------------------------------------------\n");
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\n*****No hay servicios en esta fecha*****\n");
        }

    }
}
