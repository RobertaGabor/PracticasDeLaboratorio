#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\ejercicios en C\PracticasDeLaboratorio\tareas\tareaClase11autoincremental\dataWarehouse.h"
#define TAM 5
#define TAMSEC 5

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

int id;
char nombre[20];
int edad;
char sexo;
eFecha fechaIngreso;
int isEmpty;
float sueldo;
int idSector;//FK...el id del vector id de eSector al que pertenece
} eEmpleado;

typedef struct{//puede ir donde quiera porque en la estrctura de empleado va a ser un valor de tipo numerico

    int id;//PK...
    char descripcion[20];

}eSector;//no importa que vaya despues

int menu(void);
void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado (eEmpleado x,eSector sectores[],int tamSec);
void mostrarEmpleados (eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void ordenarEmpleado (eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleadoId(int id,eEmpleado vec[],int tam);
int altaEmpleado(int x,eEmpleado vec[],int tam);
void bajaEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void modificarEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
int cargarDescripcionSector(char descripcion[]/*donde copio la desc*/,int id/*el id del sector del empleado*/,eSector sectores[]/*cadena de sectores*/,int tam/*tamaño de esa cadena de sectores*/);

void harcodeo(eEmpleado vec[],int cant);//cant cuantos deseas cargar de todo el vector
int menuInformes(void);
void informar(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void informeEmpleadosAnio(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void informarEmpleadosVarones(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void informarTotalSueldos(eEmpleado vec[],int tam);

int main()
{
    char seguir='s';
    eEmpleado lista[TAM];
    int opcionMenu;
    int proximoId=1000;
    eSector sectores[TAMSEC]={{1,"Sistemas"},{2,"RRHH"},{3,"Ventas"},{4,"Compras"},{5,"Contable"}};

    inicializarEmpleados(lista,TAM);
    harcodeo(lista,4);
    mostrarEmpleados(lista,TAM,sectores,TAMSEC);
    proximoId+=4;//xq harcodeamos ya 4, asi que el proximo va a ser el que les sigue
    system("pause");
    do
    {
        opcionMenu=menu();
        switch(opcionMenu)
        {
        case 1:
            if(altaEmpleado(proximoId,lista,TAM))
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(lista,TAM,sectores,TAMSEC);
            break;
        case 3:
            bajaEmpleado(lista,TAM,sectores,TAMSEC);
            break;
        case 4:
            break;
        case 5:
            mostrarEmpleados(lista,TAM,sectores,TAMSEC);
            break;
        case 6:
            informar(lista,TAM,sectores,TAMSEC);
            break;
        case 7:
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

    system("pause");
    }while(seguir=='s');

    return 0;
}

void mostrarEmpleado(eEmpleado x, eSector sectores[],int tamSect)
{
    char nombreSector[20];
    cargarDescripcionSector(nombreSector,x.idSector,sectores,tamSect);

    printf("%d %10s    %c   %11.2f     %d   %02d/%02d/%02d   %13s\n", x.id,x.nombre,x.sexo,x.sueldo,x.edad,x.fechaIngreso.dia,x.fechaIngreso.mes,x.fechaIngreso.anio,nombreSector);

}

void mostrarEmpleados (eEmpleado vec[],int tam, eSector sectores[],int tamSect)
{
    int flag=0;
    printf("__Listado de empleados facheros__\n");
    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO   SECTOR    \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamSect);
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
int menuInformes(void)
{
    char opcion;
    system("cls");
    printf("*****Menu de informes****\n");
    printf("a-LISTAR EMPLEADOS DE UN ANIO\n");
    printf("b-LISTAR EMPLEADOS VARONES\n");
    printf("c-INFORMAR LA SUMA TOTAL DE SUELDOS\n");
    printf("d-INFORME D\n");
    printf("e-INFORME E\n");
    printf("s-SALIR\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
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
    printf("7-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
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

int/*devuelve si se pudo o no para poder modificar id incremental*/ altaEmpleado(int id,eEmpleado vec[],int tam)
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

            printf("Ingrese sector: ");
            scanf("%d",&auxEmpleado.idSector);
            auxEmpleado.isEmpty=0;

            vec[indice]=auxEmpleado;
            retorno=1;
    }
    return retorno;

}

void bajaEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec)
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
        mostrarEmpleado(vec[indiceID],sectores,tamSec);
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

void modificarEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec)
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
        mostrarEmpleado(vec[indiceID],sectores,tamSec);
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
    }
}
void informar(eEmpleado vec[],int tam,eSector sectores[],int tamSec)
{
    char opcionInformes;
    char seguir='s';

    do
    {
        opcionInformes=menuInformes();
        switch(opcionInformes)
        {
        case 'a':
            informeEmpleadosAnio(vec,tam,sectores,tamSec);
            break;
        case 'b':
            informarEmpleadosVarones(vec,tam,sectores,tamSec);
            break;
        case 'c':
            informarTotalSueldos(vec,tam);
            break;
        case 'd':
            printf("informe d\n");
            break;
        case 'e':
            printf("informe e\n");
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

void informeEmpleadosAnio(eEmpleado vec[],int tam,eSector sectores[],int tamSec)
{
    int anio;
    system("cls");
    printf("***Informe de empleados por ingreso****\n\n",anio);
    printf("Ingrese anio: ");
    scanf("%d",&anio);
    int flag=0;


    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0&&vec[i].fechaIngreso.anio==anio)
        {
            mostrarEmpleado(vec[i],sectores,tamSec);
            flag=1;
        }
    }

    if(!flag)
    {
        printf("No hay empleados que ingresaron en ese anio\n");
    }
}

void informarEmpleadosVarones(eEmpleado vec[],int tam,eSector sectores[],int tamSec)
{
    system("cls");
    printf("***Informe de empleados varones****\n\n");
    int flag=0;

    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0&&vec[i].sexo=='m')
        {
            mostrarEmpleado(vec[i],sectores,tamSec);
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

