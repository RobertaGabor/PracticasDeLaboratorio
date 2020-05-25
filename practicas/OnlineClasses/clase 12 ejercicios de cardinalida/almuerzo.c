#include "comida.h"
#include "almuerzo.h"
#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inicializarAlmuerzos(eAlmuerzo vec[],int tamAl)
{
    for(int i=0;i<tamAl;i++)
    {
      vec[i].isEmpty=1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo vec[],int tamAl)
{
    int encontrado=-1;
    for(int i=0;i<tamAl;i++)
    {
        if(vec[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

void listarAlmuerzos (eAlmuerzo almuerzos[],int tamAl,eComida comidas[], int tamCo,eEmpleado empleados[], int tamEmp)
{
    system("cls");
    int flag=0;
    char desComida[20];
    char nombreEmpleado[20];
    float precio;
    printf("*****Listado de almuerzos*****\n");
    printf("IdAlmuerzo  Empleado   Fecha   Descripcion   Precio\n");
        for(int i=0;i<tamCo;i++)
        {
            if(almuerzos[i].isEmpty==0)
            {
                cargarNombreEmpleado(nombreEmpleado,almuerzos[i].idEmpleado,empleados,tamEmp);
                cargarDescripcionComidas(desComida,comidas[i].id,comidas,tamCo);
                cargarPrecio(&precio,almuerzos[i].idComida,comidas,tamCo);
                printf("%d   %10s  %2.d/%2.d/%d %10s     %2.f\n",almuerzos[i].id,nombreEmpleado,almuerzos[i].fecha.dia,almuerzos[i].fecha.mes,almuerzos[i].fecha.anio,desComida,precio);
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("No hay almuerzos que listar\n");
        }
}

int altaAlmuerzo (eAlmuerzo almuerzos[],int idAlmuerzo, int tamAl, eEmpleado empleados[], int tamEm,eSector sectores[], int tamSec, eComida comidas[],int tamCo,eObraSocial obras[],int tamObr)
{
    int retorno=0;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    system("cls");
    printf("*****Alta almuerzo****\n");

    indice=buscarLibreAlmuerzo(almuerzos,tamAl);

    if(indice==-1)
    {
        printf("Sistema completo\n");
    }
    else
    {
        mostrarEmpleados(empleados,tamEm,sectores,tamSec,obras,tamObr);
        printf("Ingrese id del empleado: ");
        scanf("%d",&nuevoAlmuerzo.idEmpleado);

        listarComidas(comidas,tamCo);
        printf("Ingrese id de comida: ");
        scanf("%d",&nuevoAlmuerzo.idComida);

        printf("Ingrese fecha de ingreso: ");
        scanf("%d/%d/%d",&nuevoAlmuerzo.fecha.dia,&nuevoAlmuerzo.fecha.mes,&nuevoAlmuerzo.fecha.anio);

        nuevoAlmuerzo.id=idAlmuerzo;
        nuevoAlmuerzo.isEmpty=0;
        retorno=1;
        almuerzos[indice]=nuevoAlmuerzo;

    }

    return retorno;
}

int cargarNombreEmpleado(char nombre[],int id,eEmpleado empleados[],int tamEmp)
{
    int retorno=0;

    for(int i=0;i<tamEmp;i++)
    {
        if(empleados[i].id==id)
        {
            strcpy(nombre,empleados[i].nombre);
            retorno=1;
        }
    }

    return retorno;
}

int cargarPrecio(float* precio,int idAlmuerzoComida,eComida comida[],int tamCo)
{
    int retorno=0;

    for(int i=0;i<tamCo;i++)
    {
        if(comida[i].id==idAlmuerzoComida)
        {
            *precio=comida[i].precio;
            retorno=1;
        }
    }

    return retorno;
}
