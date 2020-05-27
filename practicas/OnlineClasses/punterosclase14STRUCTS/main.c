#include <stdio.h>
#include <stdlib.h>
typedef struct{

char nombre[20];
int edad;
float sueldo;

}eEmpleado;

int main()
{
   eEmpleado emp1={"jose",40,34000};

   printf("%s  %d  %2.f\n",emp1.nombre,emp1.edad,emp1.sueldo);
}
