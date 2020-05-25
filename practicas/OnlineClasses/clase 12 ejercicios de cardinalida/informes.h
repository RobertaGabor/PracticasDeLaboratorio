#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "empleado.h"
#include "sector.h"

void informarEmpleadosSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void informarEmpleadosXSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
int menuInformes(void);
void informar(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void informeEmpleadosAnio(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void informarEmpleadosVarones(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void informarTotalSueldos(eEmpleado vec[],int tam);
void informarSueldoTotalSector(eEmpleado vec[],int tam,eSector sectores[],int tamSec);
void informarMayorSueldoSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec);
void informarMayorSueldoXSector (eEmpleado empleados[],int tam,eSector sectores[],int tamSec);
void modificarSueldoPorcentaje (eEmpleado empleados[],int tam,eSector sectores[],int tamSec);
void sectorConMasSalario (eEmpleado empleados[],int tam,eSector sectores[],int tamSec);
float obtenerTotalSueldosSector (eEmpleado empleados[],int tam,int idSector);
#endif // INFORMES_H_INCLUDED
