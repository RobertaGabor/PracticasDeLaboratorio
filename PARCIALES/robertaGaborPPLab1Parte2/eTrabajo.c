#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSERVICIOS 4
#define TAMCOLORES 5
#define TAMSMARCAS 5
#define TAMAUTOS 1000
#define TAMTRABAJOS 1000
#include "validaciones.h"
#include "eAuto.h"
#include "eColor.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "data.h"

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ)
{
    char descripcion[25];
    cargarDescripcionServicio(descripcion,trabajo.idServicio,servicios,tamServ);
    printf("\n%d    %10s    %2.d/%2.d/%d    %10s\n",trabajo.idTrabajo,trabajo.patente,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio,descripcion);
}

void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ)
{
    system("cls");
    printf("**********Listado de Trabajos*********\n\n");
    printf("ID         PATENTE     FECHA        SERVICIO\n");
    for(int i=0;i<tamTra;i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i],servicios,tamServ);
        }

    }
    printf("\n");
}

int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra,eCliente clientes[],int tamCli)
{
    int indice=buscarLibreTrabajo(trabajo,tamTra);
    int retorno=0;

    eTrabajo auxiliar;

    system("cls");
    printf("*****Alta de Trabajo*****\n\n\n");
    if(indice==-1)
    {
        printf("No hay lugar para agregar otro trabajo\n");
    }
    else
    {
        mostrarAutos(autos,tamAu,colores,tamCol,marcas,tamMar,clientes,tamCli);
            if(getPatente(auxiliar.patente,20,"\nIngrese patente del auto: ","Error ingrese una cadena valida",1))
            {
                if(buscarPatenteAuto(auxiliar.patente,autos,tamAu)!=-1)
                {   system("cls");
                    mostrarServicios(servicio,tamServ);
                    if(getInt(&auxiliar.idServicio,"Ingrese ID del servicio: ","Error debe ser un numero del 20000 al 20003",20000,20003,1))
                    {
                        if(getInt(&auxiliar.fecha.dia,"Ingrese dia de ingreso: ","Error debe ingresar un dia del 1 al 31",1,31,1)
                           &&getInt(&auxiliar.fecha.mes,"Ingrese mes de ingreso: ","Error debe ingreaar un numero del 1 al 12",1,12,1)
                           &&getInt(&auxiliar.fecha.anio,"Ingrese anio de ingreso: ","Error ingrese un anio valido",1000,2020,1))
                        {
                            retorno=1;
                            auxiliar.isEmpty=0;
                            auxiliar.idTrabajo=id;
                            trabajo[indice]=auxiliar;
                        }
                    }
                }
                else
                {
                    printf("\n*****La patente no se encuentra en el sistema*****\n");
                }

            }
    }
    return retorno;
}


int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra)
{
    int encontrado=-1;
    for(int i=0;i<tamTra;i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}
void inicializarTrabajos(eTrabajo trabajos[],int tamTra)
{
    for(int i=0;i<tamTra;i++)
    {
      trabajos[i].isEmpty=1;
    }
}

void mostrarAutoConFecha(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,eTrabajo trabajos)
{
    char marca[20];
    char color[20];
    char cliente[20];
    cargarDescripcionColor(color,autos.idColor,colores,tamCol);
    cargarDescripcionMarca(marca,autos.idMarca,marcas,tamMar);
    cargarDescripcionCliente(cliente,autos.idCliente,clientes,tamCli);

    printf("\n%2.d    %10s   %10s    %d  %10s  %10s  %2.d/%2.d/%d\n\n",autos.idAuto,color,marca,autos.modelo,autos.patente,cliente,trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);
}

int buscarUnaCargaTrabajo(eTrabajo trabajos[],int tamTra)
{
    int encontrado=0;
    for(int i=0;i<tamTra;i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            encontrado=1;
            break;
        }
    }

    return encontrado;
}

void harcodeo(eTrabajo trabajo[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        trabajo[i].fecha.dia=dias[i];
        trabajo[i].fecha.mes=meses[i];
        trabajo[i].fecha.anio=anios[i];
        trabajo[i].idServicio=idServiciod[i];
        trabajo[i].idTrabajo=idTrabajod[i];
        trabajo[i].isEmpty=0;
        strcpy(trabajo[i].patente,patented[i]);
    }
}
