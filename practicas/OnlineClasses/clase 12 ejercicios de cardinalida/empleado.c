#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "obraSocial.h"
#include "C:\ejercicios en C\PracticasDeLab1\tareas\tareaClase11autoincremental\dataWarehouse.h"

void harcodeo(eEmpleado vec[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        vec[i].id=ids[i];
        strcpy(vec[i].nombre,nombres[i]);
        vec[i].edad=edades[i];
        vec[i].sexo=sexos[i];
        vec[i].sueldo=sueldos[i];
        vec[i].fechaIngreso.dia=dias[i];
        vec[i].fechaIngreso.mes=meses[i];
        vec[i].fechaIngreso.anio=anios[i];
        vec[i].isEmpty=0;
        vec[i].idSector=idsSectores[i];
        vec[i].obrasocial=idObrasocial[i];
    }
}

int buscarLibre(eEmpleado vec[],int tam)
{
    int encontrado=-1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

int buscarEmpleadoId(int id,eEmpleado vec[],int tam)
{
    int indice=-1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].id==id&&vec[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int/*devuelve si se pudo o no para poder modificar id incremental*/ altaEmpleado(int id,eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    int indice=buscarLibre(vec,tam);
    int retorno=0;
    eEmpleado auxEmpleado;
    system("cls");
    printf("*****Alta de empleado*****\n");
    if(indice==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {
        /*printf("Ingrese id: ");
        scanf("%d",&id);
        existe=buscarEmpleadoId(id,vec,tam);

        if(existe!=-1)
        {
            printf("El id ya existe\n");
        }
        else
        {*/
            auxEmpleado.id=id;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);

            printf("Ingrese sexo: ");
            scanf("%c",&auxEmpleado.sexo);

            printf("Ingrese edad: ");
            scanf("%d",&auxEmpleado.edad);

            printf("Ingrese sueldo: ");
            scanf("%f",&auxEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaa: ");
            scanf("%d/%d/%d",&auxEmpleado.fechaIngreso.dia,&auxEmpleado.fechaIngreso.mes,&auxEmpleado.fechaIngreso.anio);

            mostrarSectores(sectores,tamSec);

            printf("Ingrese id sector: ");
            scanf("%d",&auxEmpleado.idSector);

            mostrarObras(obras,tamObr);
            printf("Ingrese id de la obra social: ");
            scanf("%d",&auxEmpleado.obrasocial);

            auxEmpleado.isEmpty=0;

            vec[indice]=auxEmpleado;
            retorno=1;
    }
    return retorno;

}

void bajaEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    int id;
    int indiceID;
    char confirmacion='s';
    system("cls");
    printf("******Baja de empleado********\n");
    printf("Ingrese un ID a dar de baja: ");
    scanf("%d",&id);

    indiceID=buscarEmpleadoId(id,vec,tam);
    if(indiceID==-1)
    {
        printf("No se encontro el ID\n");
    }
    else
    {
        mostrarEmpleado(vec[indiceID],sectores,tamSec,obras,tamObr);
        printf("Desea comfirmar baja?: \n");
        printf("s - para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            vec[indiceID].isEmpty=1;
        }
    }
}

void modificarEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr)
{
    int id;
    int indiceID;
    char confirmacion='s';
    float nuevoSueldo;


    system("cls");
    printf("******Modificar empleado********\n");
    printf("Ingrese un ID de empleado: ");
    scanf("%d",&id);

    indiceID=buscarEmpleadoId(id,vec,tam);
    if(indiceID==-1)
    {
        printf("No se encontro el ID\n");
    }
    else
    {
        mostrarEmpleado(vec[indiceID],sectores,tamSec,obras,tamObr);
        printf("Modificar sueldo?: ");
        fflush(stdin);
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f",&nuevoSueldo);
            vec[indiceID].sueldo=nuevoSueldo;
            printf("Se ha actualizado la informacion con exito\n");
        }
    }
}
void mostrarEmpleado(eEmpleado x, eSector sectores[],int tamSect,eObraSocial obras[],int tamObr)
{
    char nombreSector[20];
    char nombreObra[20];
    cargarDescripcionSector(nombreSector,x.idSector,sectores,tamSect);
    cargarDescripcionObra(nombreObra,x.obrasocial,obras,tamObr);

    printf("\n%d %10s    %c   %11.2f     %d   %02d/%02d/%02d   %13s   %10s\n", x.id,x.nombre,x.sexo,x.sueldo,x.edad,x.fechaIngreso.dia,x.fechaIngreso.mes,x.fechaIngreso.anio,nombreSector,nombreObra);

}

void mostrarEmpleados (eEmpleado vec[],int tam, eSector sectores[],int tamSect,eObraSocial obras[],int tamObr)
{
    system("cls");
    int flag=0;
    printf("__Listado de empleados facheros__\n");
    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO   SECTOR    OBRA SOCIAL\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamSect,obras,tamObr);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados\n");
    }
}

void ordenarEmpleado (eEmpleado vec[],int tam)
{
    eEmpleado auxiliarEmpleado;
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
                 if(vec[i].sexo==vec[j].sexo&&vec[i].sueldo>vec[j].sueldo)
                {
                    auxiliarEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxiliarEmpleado;

                }
            }
        }
    }
}

void inicializarEmpleados(eEmpleado vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
      vec[i].isEmpty=1;
    }
}

int menu(void)
{
    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");
    printf("1-Alta de un empleados\n");
    printf("2-Modificar datos de un empleados\n");
    printf("3-Baja de un empleados\n");
    printf("4-Ordenar lista\n");
    printf("5-Imprimir lista\n");
    printf("6-Informes\n");
    printf("7-Alta de un almuerzo\n");
    printf("8-Listar almuerzos\n");
    printf("10-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int cargarDescripcionSector(char descripcion[],int id,eSector sectores[],int tam)
{
    int retorno=0;

    for(int i=0;i<tam;i++)
    {
        if(sectores[i].id==id)
        {
            strcpy(descripcion,sectores[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}
