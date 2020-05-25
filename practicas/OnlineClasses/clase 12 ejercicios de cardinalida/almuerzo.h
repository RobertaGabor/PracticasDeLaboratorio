#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"

typedef struct{

    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;

void listarAlmuerzos (eAlmuerzo almuerzos[],int tamAl,eComida comidas[], int tamCo,eEmpleado empleados[], int tamEmp);
int buscarLibreAlmuerzo(eAlmuerzo vec[],int tamAl);
void inicializarAlmuerzos(eAlmuerzo vec[],int tamAl);
int altaAlmuerzo (eAlmuerzo almuerzos[],int idAlmuerzo, int tamAl, eEmpleado empleados[], int tamEm,eSector sectores[], int tamSec, eComida comidas[],int tamCo,eObraSocial obras[],int tamObr);

int cargarDescripcionComidas(char descipcion[],int id,eComida comidas[],int tamCo);
int cargarNombreEmpleado(char nombre[],int id,eEmpleado empleados[],int tamEmp);
int cargarPrecio(float* precio,int idAlmuerzoComida,eComida comida[],int tamCo);
#endif // ALMUERZO_H_INCLUDED


