#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harcodeo.h"
#include "clientes.h"

void harcodeo(eClientes clientes[],int tamClientes)
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
        clientes[i].idDuenio=ids[i];
    }
}
