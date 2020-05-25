#include "dataWareHouse.h"
#include "clientes.h"
#include <string.h>


void harcodeo(eClientes clientes[],int tamCli)
{
    for(int i=0; i<tamCli; i++)
    {
        strcpy(clientes[i].nombre,nombres[i]);
        strcpy(clientes[i].apellido,apellidos[i]);
        clientes[i].cuit=cuits[i];
        clientes[i].isEmpty=0;
    }
}
