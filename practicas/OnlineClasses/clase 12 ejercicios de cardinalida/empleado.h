#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"
#include "obraSocial.h"

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
int obrasocial;
} eEmpleado;


void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado (eEmpleado x,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void mostrarEmpleados (eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void ordenarEmpleado (eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleadoId(int id,eEmpleado vec[],int tam);
int altaEmpleado(int x,eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void bajaEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void modificarEmpleado(eEmpleado vec[],int tam,eSector sectores[],int tamSec,eObraSocial obras[],int tamObr);
void harcodeo(eEmpleado vec[],int cant);//cant cuantos deseas cargar de todo el vector
int cargarDescripcionSector(char descripcion[]/*donde copio la desc*/,int id/*el id del sector del empleado*/,eSector sectores[]/*cadena de sectores*/,int tam/*tamaño de esa cadena de sectores*/);
int menu(void);
#endif // EMPLEADO_H_INCLUDED


