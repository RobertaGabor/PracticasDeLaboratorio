#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSTRUCT1 100
#define TAMSTRUCT4 1000
#include "validaciones.h"
#include "clientes.h"

void inicializarClientes(eClientes clientes[],int tamCli)
{
    for(int i=0;i<tamCli;i++)
    {
      clientes[i].isEmpty=1;
    }
}

int menu(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Alta de cliente\n");
    printf("2-Modificar el dato de un cliente\n");
    printf("3-Baja de un clientes\n");
    printf("4-Publicar\n");
    printf("5-Pausar publicacion\n");
    printf("6-Reanudar publicacion\n");
    printf("7-Imprimir clientes\n");
    printf("8-Imprimir publicaciones\n");
    printf("9-Informar clientes\n");
    printf("10-Informar publicaciones\n");
    printf("0-salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int altaCliente(int id,eClientes clientes[],int tamStruct1)
{
    int indice=buscarLibre(clientes,tamStruct1);

    int retorno=0;

    eClientes auxiliar;

    system("cls");
    printf("*****Alta de Clientes*****\n");
    if(indice==-1)
    {
        printf("No hay lugar disponible para dar de alta otro cliente\n");
    }
    else
    {

            auxiliar.id=id;

            if(getString(auxiliar.nombre,sizeof(auxiliar.nombre),"Ingrese nombre del cliente","Error debe ser una cadena alfabetica",1))
            {
                   if(getString(auxiliar.apellido,sizeof(auxiliar.apellido),"Ingrese apellido del cliente","Error debe ser una cadena alfabetica",1))
                   {
                       if(getCuit(&auxiliar.cuit,"Ingrese CUIT","Error. debe ser un CUIT",999999999,9999999999,1))
                       {
                            auxiliar.isEmpty=0;
                            clientes[indice]=auxiliar;
                            retorno=1;
                       }
                   }
            }
    }
    return retorno;

}

int buscarLibre(eClientes clientes[],int tamCli)
{
    int encontrado=-1;
    for(int i=0;i<tamCli;i++)
    {
        if(clientes[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

int modificarDatos(eClientes cliente[],int tamCli)
{
    int id;
    int retorno=0;

    int indice;
    int opcionCambio;
    int flag;

    eClientes auxiliar;

    system("cls");
    if(cliente!=NULL&&tamCli>0)
    {
        retorno=1;
        printf("\n*****Modificar datos del cliente*****\n");

        if(getInt(&id,"\nIngrese ID del cliente: ","\nError. Debe ingresar un numero entero numerico mayor a 1000\n",1000,10000,0))
        {
            indice=buscarIdCliente(id,cliente,tamCli);
            if(indice==-1||cliente[indice].isEmpty==1)
            {
                printf("\n*****No se encontro este ID en la base de datos*****\n\n");
            }
            else
            {
            	flag=0;

                do
                {

                    printf("*****Cliente seleccionado*****\n");
                    mostrarCliente(cliente,indice);

                    printf("\n\n");
                    system("pause");
                    system("cls");

                    opcionCambio=menuModificar();

                    switch(opcionCambio)
                    {
                    case 1:
                        if(getString(auxiliar.nombre,sizeof(auxiliar.nombre),"Ingrese nuevo nombre del cliente","Error debe ser una cadena alfabetica",1))
                        {
                            strcpy(cliente[indice].nombre,auxiliar.nombre);
                            flag=1;
                        }
                        break;
                    case 2:
                        if(getString(auxiliar.apellido,sizeof(auxiliar.apellido),"Ingrese apellido del cliente","Error debe ser una cadena alfabetica",1))
                        {
                            strcpy(cliente[indice].apellido,auxiliar.apellido);
                            flag=1;
                        }
                        break;
                    case 3:
                        if(getCuit(&auxiliar.cuit,"Ingrese CUIT","Error. debe ser un CUIT",9999999999,99999999999,1))
                        {
                            cliente[indice].cuit=auxiliar.cuit;
                        }
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n*****Error. Ingrese una opcion valida*****\n\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                }while(opcionCambio!=0);

                if(flag==1)
                {
                    printf("\n******Los cambios se han cargado con exito!!!****\n");
                    system("pause");
                }
            }
        }
    }
    return retorno;
}
int buscarIdCliente(int id,eClientes clientes[],int tamCli)
{
    int indice=-1;
    for(int i=0;i<tamCli;i++)
    {
        if(clientes[i].id==id&&clientes[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarCliente (eClientes cliente[],int indice)
{
    printf("\n%d   %lld  %13s   %13s\n",cliente[indice].id,cliente[indice].cuit,cliente[indice].nombre,cliente[indice].apellido);

}

int menuModificar(void)
{

    int opcion;
    system("cls");
    printf("********Menu de cambios**********\n");

    printf("1-Cambiar nombre\n");
    printf("2-Cambiar apellido\n");
    printf("3-Cambiar CUIT\n");
    printf("0-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void bajaCliente(eClientes clientes[],int tamCli)
{
    int id;
    int indiceID;
    char confirmacion='s';

    system("cls");
    printf("*********Baja de Cliente********\n");

    getInt(&id,"Ingrese ID a dar de baja","Error debe ser un ID entero mayor a 1000",1000,10000,0);
    indiceID=buscarIdCliente(id,clientes,tamCli);

    if(indiceID==-1||clientes[indiceID].isEmpty==-1)
    {
        printf("No se encontro el ID o ya esta dado de baja\n");
    }
    else
    {
        mostrarCliente(clientes,id);
        printf("Desea comfirmar baja?: \n");
        printf("s - para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            clientes[indiceID].isEmpty=1;
        }
        else
        {
            printf("\nOperacion cancelada\n");
        }
    }
}


