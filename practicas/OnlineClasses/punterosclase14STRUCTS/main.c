#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{

int dia;
int mes;
int anio;

}eFecha;
typedef struct{

char nombre[20];
int edad;
float sueldo;
eFecha fechaIng;

}eEmpleado;

void cambiarNombre(eEmpleado* unEmpleado);
void mostrarEmpleado (eEmpleado unEmpleado);

int main()
{
   eEmpleado emp1={"jose",40,34000,{27,5,2020}};
   eEmpleado* p;

   p=&emp1;

   printf("\nDatos de emp1: \n");
   printf("%s  %d  %.2f  %02d/%02d/%d\n",emp1.nombre,emp1.edad,emp1.sueldo,emp1.fechaIng.dia,emp1.fechaIng.mes,emp1.fechaIng.anio);

   printf("\nCuando obtenemos los datos de una struct a traves de puntero: \n");
   printf("%s  %d  %.2f  %02d/%02d/%d\n",p->nombre,p->edad,p->sueldo,p->fechaIng.dia,p->fechaIng.mes,p->fechaIng.anio);/*Uso la flecha*/

   mostrarEmpleado(emp1);
   cambiarNombre(&emp1);/*pasamos la direccion*/
   mostrarEmpleado(emp1);
}

void cambiarNombre(eEmpleado* unEmpleado)
{
    char nombre[20];
    printf("Ingrese nuevo nombre: ");
    fflush(stdin);
    gets(nombre);

    strcpy(unEmpleado->nombre,nombre);/*flecha porque es a puntero*/
}

void mostrarEmpleado (eEmpleado unEmpleado)
{
   printf("%s  %d  %.2f  %02d/%02d/%d\n",unEmpleado.nombre,unEmpleado.edad,unEmpleado.sueldo,unEmpleado.fechaIng.dia,unEmpleado.fechaIng.mes,unEmpleado.fechaIng.anio);

}
