#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSTRUCT1 100
#define TAMSTRUCT4 1000
#include "validaciones.h"
#include "clientes.h"
#include "dataWareHouse.h"

/*typedef struct{

int idCliente;
int numeroRubro;
char texto[64];
int id;
int isEmpty;

}ePublicacion;*/


int main()
{
    char seguir='s';

    eClientes clientes[TAMSTRUCT1];
    //ePublicacion publicaciones[TAMSTRUCT4];

    int opcionMenuMain;
    int proximoIdCliente=1000;

    inicializarClientes(clientes,TAMSTRUCT1);

    do
    {
        opcionMenuMain=menu();
        switch(opcionMenuMain)
        {
        case 1:
            if(altaCliente(proximoIdCliente,clientes,TAMSTRUCT1))
            {
                proximoIdCliente++;
            }
            break;
        case 2:
            modificarDatos(clientes,TAMSTRUCT1);
            break;
        case 3:
            bajaCliente(clientes,TAMSTRUCT1);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
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
