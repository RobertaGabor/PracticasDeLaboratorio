#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harcodeo.h"
#include "clientes.h"
#include "mascotas.h"
#include "validaciones.h"


#define TAMCLIENTE 10
#define TAMMASCOTA 20
#define TAMTIPO 3




void harcodeoClientes(eClientes clientes[],int tamClientes);
void inicializarClientes(eClientes clientes[],int tamCliente);
int menu(void);
void mostrarMascotas (eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos);
void harcodeoMascota(eMascota mascotas[],int tamMascota);
void mostrarCliente(eClientes cliente);
void mostrarClientes (eClientes clientes[],int tamCliente);
int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamTipo);
int cargarDescripcionNombre(char descripcion[],int id,eClientes clientes[],int tamCliente);
void mostrarMascota(eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos,eMascota mascota);
void mostrarMascotas (eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos);
void inicializarMascotas(eMascota mascotas[],int tamMascota);
void mostrarListadoDeAnimal(eTipo tipos[],int tamTipos,eMascota mascota);
void mostrarListadoDeFamilias (eClientes clientes[],int tamCliente,eTipo tipos[],int tamTipos,eMascota mascota[],int tamMascota);
int buscarLibre(eMascota mascota[],int tamMascota);
void mostrarTipos(eTipo tipos[],int tamTipo);
int altaMascota(int idMascotas,eMascota mascotas[],int tamMascota,eTipo tipo[],int tamTipo,eClientes clientes[],int tamCliente);
int buscarMascotaId(int id,eMascota mascota[],int tamMasc);
void bajaMascota(eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos);
int menuDeCambios(void);
int modificarDatos(eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos);


int main()
{
    char seguir='s';
    int opcionMenuMain;
    int proximoIdMascota=100;

    eClientes clientes[TAMCLIENTE];
    eMascota mascotas[TAMMASCOTA];
    eTipo tipos[TAMTIPO]={{1,"Perro"},{2,"Gato"},{3,"Raro"}};

    inicializarMascotas(mascotas,TAMMASCOTA);
    inicializarClientes(clientes,TAMCLIENTE);
    harcodeoClientes(clientes,5);
    harcodeoMascota(mascotas,11);

    proximoIdMascota+=11;


    do
    {
        opcionMenuMain=menu();
        switch(opcionMenuMain)
        {
        case 1:
            mostrarClientes(clientes,TAMCLIENTE);
            break;
        case 2:
            mostrarMascotas(mascotas,TAMMASCOTA,clientes,TAMCLIENTE,tipos,TAMTIPO);
            break;
        case 3:
            mostrarListadoDeFamilias(clientes,TAMCLIENTE,tipos,TAMTIPO,mascotas,TAMMASCOTA);
            break;
        case 4:
            if(altaMascota(proximoIdMascota,mascotas,TAMMASCOTA,tipos,TAMTIPO,clientes,TAMCLIENTE))
            {
                proximoIdMascota++;
            }
            break;
        case 5:
            modificarDatos(mascotas,TAMMASCOTA,clientes,TAMCLIENTE,tipos,TAMTIPO);
            break;
        case 6:
            bajaMascota(mascotas,TAMMASCOTA,clientes,TAMCLIENTE,tipos,TAMTIPO);
            break;
        case 0:
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





int menu(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Listar clientes\n");
    printf("2-Listar mascotas\n");
    printf("3-Listar mascotas con duenios\n");
    printf("4-Alta de mascota\n");
    printf("5-Modificar dato de mascota\n");
    printf("6-Baja de mascota\n");
    printf("0-salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}


void inicializarClientes(eClientes clientes[],int tamCliente)
{
    for(int i=0;i<tamCliente;i++)
    {
      clientes[i].isEmpty=1;
    }
}

void inicializarMascotas(eMascota mascotas[],int tamMascota)
{
    for(int i=0;i<tamMascota;i++)
    {
      mascotas[i].isEmpty=1;
    }
}

void harcodeoClientes(eClientes clientes[],int tamClientes)
{
    for(int i=0; i<tamClientes; i++)
    {
        strcpy(clientes[i].nombre,nombres[i]);
        strcpy(clientes[i].apellido,apellidos[i]);
        strcpy(clientes[i].localidad,localidades[i]);
        clientes[i].telefono=telefonos[i];
        clientes[i].edad=edades[i];
        clientes[i].sexo=sexos[i];
        clientes[i].isEmpty=0;
        clientes[i].id=ids[i];
    }
}

void harcodeoMascota(eMascota mascotas[],int tamMascota)
{
    for(int i=0; i<tamMascota; i++)
    {
        strcpy(mascotas[i].nombre,nombreMascotas[i]);
        mascotas[i].edad=edadMacotas[i];
        strcpy(mascotas[i].raza,razas[i]);
        mascotas[i].tipo=tipos[i];
        mascotas[i].sexo=sexoMascotas[i];
        mascotas[i].isEmpty=0;
        mascotas[i].peso=pesos[i];
        mascotas[i].idDuenio=idDuenio[i];
        mascotas[i].idMasc=idMascota[i];
    }
}

void mostrarCliente(eClientes cliente)
{
    printf("\n%d    %10s   %10s    %10.lf      %d      %c      %10s\n",cliente.id,cliente.nombre,cliente.apellido,cliente.telefono,cliente.edad,cliente.sexo,cliente.localidad);

}

void mostrarClientes (eClientes clientes[],int tamCliente)
{
    int flag=0;
    printf("**********Listado de Clientes*********\n");
    printf(" ID         NOMBRE     APELLIDO      TELEFONO      EDAD   SEXO      LOCALIDAD\n");
    for(int i=0;i<tamCliente;i++)
    {
        if(clientes[i].isEmpty==0)
        {
            mostrarCliente(clientes[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay clientes a mostrar\n");
    }
}

int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamTipo)
{
    int retorno=0;

    for(int i=0;i<tamTipo;i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}

int cargarDescripcionNombre(char descripcion[],int id,eClientes clientes[],int tamCliente)
{
    int retorno=0;

    for(int i=0;i<tamCliente;i++)
    {
        if(clientes[i].id==id)
        {
            strcpy(descripcion,clientes[i].nombre);
            retorno=1;
        }
    }

    return retorno;
}

void mostrarMascota(eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos,eMascota mascota)
{
    char descripcionTipo[30];
    char descripcionDuenio[30];
    cargarDescripcionTipo(descripcionTipo,mascota.tipo,tipos,tamTipos);
    cargarDescripcionNombre(descripcionDuenio,mascota.idDuenio,cliente,tamCliente);

    printf("\n%10s  %10s  %15s   %2.d   %5.2f  %c  %10s\n",mascota.nombre,descripcionTipo,mascota.raza,mascota.edad,mascota.peso,mascota.sexo,descripcionDuenio);

}

void mostrarMascotas (eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos)
{
    int flag=0;
    printf("**********Listado de Mascotas*********\n");
    printf("   NOMBRE        TIPO            RAZA    EDAD   PESO SEXO     DUENIO\n");
    for(int i=0;i<tamMascota;i++)
    {
        if(mascotas[i].isEmpty==0)
        {
            mostrarMascota(cliente,tamCliente,tipos,tamTipos,mascotas[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay clientes a mostrar\n");
    }
}

void mostrarListadoDeAnimal(eTipo tipos[],int tamTipos,eMascota mascota)
{
    char descripcionTipo[30];
    cargarDescripcionTipo(descripcionTipo,mascota.tipo,tipos,tamTipos);
    printf("%10s %10s\n",descripcionTipo,mascota.nombre);
}

void mostrarListadoDeFamilias (eClientes clientes[],int tamCliente,eTipo tipos[],int tamTipos,eMascota mascota[],int tamMascota)
{
    system("cls");
    printf("*****Familias*****\n");
    for(int i=0; i<tamCliente; i++)
    {
        if(clientes[i].isEmpty==0)
        {
            printf("Cliente: %10s\n\n",clientes[i].nombre);

            for(int j=0; j<tamMascota; j++)
            {
                if(mascota[j].idDuenio==clientes[i].id&&mascota[j].isEmpty==0)
                {
                    mostrarListadoDeAnimal(tipos,tamTipos,mascota[j]);
                }
            }

            printf("\n-----------------------------------------\n");
        }

    }
}

int altaMascota(int idMascotas,eMascota mascotas[],int tamMascota,eTipo tipo[],int tamTipo,eClientes clientes[],int tamCliente)
{
    int indice=buscarLibre(mascotas,tamMascota);

    int retorno=0;

    eMascota auxiliar;

    system("cls");
    printf("*****Alta de MASCOTA*****\n");
    if(indice==-1)
    {
        printf("No hay lugar para agregar otra amscota\n");
    }
    else
    {
            auxiliar.idMasc=idMascotas;

            if(getString(auxiliar.nombre,sizeof(auxiliar.nombre),"Ingrese nombre: ","Error",1)
                &&getString(auxiliar.raza,sizeof(auxiliar.nombre),"Ingrese raza: ","Error",1)
                &&getFloat(&auxiliar.peso,6,"Ingrese peso: ","Error",1)
                &&getInt(&auxiliar.edad,"Ingrese edad: ","Error",0,100,1)
                &&getSexo(&auxiliar.sexo,"Ingrese sexo f/m: ","Error f o m",1))
            {
                mostrarClientes(clientes,tamCliente);
                if(getInt(&auxiliar.idDuenio,"Ingrese ID del duenio: ","Error de 1000 al 1004",1000,1004,1))
                {
                    mostrarTipos(tipo,tamTipo);
                    if(getInt(&auxiliar.tipo,"Ingrese Tipo: ","Error",1,3,1))
                    {
                        auxiliar.isEmpty=0;

                        mascotas[indice]=auxiliar;
                        retorno=1;
                    }
                }
            }
    }
    return retorno;

}

int buscarLibre(eMascota mascota[],int tamMascota)
{
    int encontrado=-1;
    for(int i=0;i<tamMascota;i++)
    {
        if(mascota[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

void mostrarTipos(eTipo tipos[],int tamTipo)
{
    system("cls");
    printf("tipo    Descripcion\n");
    printf("--------------------\n");
    for(int i=0;i<tamTipo;i++)
    {
        printf("%d    %10s\n",tipos[i].id,tipos[i].descripcion);
    }
}

void bajaMascota(eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos)
{
    int id;
    int indiceID;
    char confirmacion='s';

    system("cls");
    printf("*********Baja de PRINCIPAL********\n");

    if(getInt(&id,"Ingrese ID de mascota: ","Error de 100 en adelante",100,1000,1))
    {
        indiceID=buscarMascotaId(id,mascotas,tamMascota);
        if(indiceID==-1)
        {
            printf("No se encontro el ID o está dadod de baja\n");
        }
        else
        {
            printf("\n   NOMBRE        TIPO            RAZA    EDAD   PESO SEXO     DUENIO\n");
            mostrarMascota(cliente,tamCliente,tipos,tamTipos,mascotas[indiceID]);
            printf("\n\nDesea comfirmar baja?: \n");
            printf("s - para confirmar\n");
            fflush(stdin);
            scanf("%c",&confirmacion);

            if(confirmacion=='s')
            {
                mascotas[indiceID].isEmpty=1;
                printf("\n\n****Removido exitosamente***\n");
            }
            else
            {
                printf("\nOperacion cancelada\n");
            }
        }
    }

}

int buscarMascotaId(int id,eMascota mascota[],int tamMasc)
{
    int indice=-1;
    for(int i=0;i<tamMasc;i++)
    {
        if(mascota[i].idMasc==id&&mascota[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int modificarDatos(eMascota mascotas[],int tamMascota,eClientes cliente[],int tamCliente,eTipo tipos[],int tamTipos)
{
    int id;
    int retorno=0;

    int indice;
    int opcionCambio;
    int flag;

    eMascota auxiliar;

    system("cls");
    if(mascotas!=NULL&&tamMascota>0)
    {
        retorno=1;
        printf("\n*****Modificar datos de una Mascota*****\n");

        if(getInt(&id,"\nIngrese ID de la mascota: ","\nError. Debe ingresar un numero entero de 100 en adelante\n",100,10000,0))
        {
            indice=buscarMascotaId(id,mascotas,tamMascota);
            if(indice==-1)
            {
                printf("\n*****No se encontro este ID en la base de datos*****\n\n");
            }
            else
            {
            	flag=0;

                do
                {

                    system("cls");
                    printf("*****Mascota seleccionada*****\n");

                    mostrarMascota(cliente,tamCliente,tipos,tamTipos,mascotas[indice]);
                    printf("\n\n");
                    system("pause");
                    system("cls");

                    opcionCambio=menuDeCambios();

                    switch(opcionCambio)
                    {
                    case 1:
                        if(getString(auxiliar.nombre,sizeof(auxiliar.nombre),"Ingrese otro nombre : ","Error",1))
                           {
                               strcpy(mascotas[indice].nombre,auxiliar.nombre);
                                flag=1;
                           }
                        break;
                    case 2:
                        if(getInt(&auxiliar.edad,"Ingrese edad: ","Error",0,100,1))
                        {
                            mascotas[indice].edad=auxiliar.edad;
                            flag=1;
                        }
                        break;
                    case 3:
                        mostrarTipos(tipos,tamTipos);
                        if(getInt(&auxiliar.tipo,"Ingrese Tipo: ","Error",1,3,1))
                        {
                            mascotas[indice].tipo=auxiliar.tipo;
                            flag=1;
                        }
                        break;
                    case 4:
                        if(getString(auxiliar.raza,sizeof(auxiliar.nombre),"Ingrese raza: ","Error",1))
                        {
                            strcpy(mascotas[indice].raza,auxiliar.raza);
                            flag=1;
                        }
                        break;
                    case 5:
                        if(getSexo(&auxiliar.sexo,"Ingrese sexo f/m: ","Error f o m",1))
                        {
                            mascotas[indice].sexo=auxiliar.sexo;
                            flag=1;
                        }
                        break;
                    case 6:
                        if(getFloat(&auxiliar.peso,6,"Ingrese peso: ","Error",1))
                        {
                            mascotas[indice].peso=auxiliar.peso;
                            flag=1;
                        }
                        break;
                    case 7:
                        break;
                    default:
                        printf("\n*****Error. Ingrese una opcion valida*****\n\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                }while(opcionCambio!=7);

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

int menuDeCambios(void)
{
    int opcion;
    printf("******Eleccion de dato a modificar*******\n");
    printf("1-Nombre\n");
    printf("2-Edad\n");
    printf("3-Tipo\n");
    printf("4-Raza\n");
    printf("5-Sexo\n");
    printf("6-Peso\n");
    printf("7-Salir\n");

    printf("\nQue dato desea cambiar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
