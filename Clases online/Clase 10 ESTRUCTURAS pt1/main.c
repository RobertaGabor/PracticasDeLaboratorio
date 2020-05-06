#include <stdio.h>//directivas preprocesador--estructuras--funciones--main
#include <stdlib.h>

typedef struct{

    int dia;
    int mes;
    int anio;//no usar ñ

}eFecha;

typedef struct{

int id;//4 bytes
char nombre[20];//20 bytes-->corta el ancho de palabra. cada 4 bytes,tiene que ser multiplo
int edad;//4 bytes
char sexo;//1 bytes-->asigna 36 directo en vez de 32(si eliminas sexo da 32). cuando agrego este byte extra cambia los multiplos de 4. por eso corta en 36
float sueldo;//8 bytes
eFecha fechaIngreso;

}eEmpleado;

void mostrarEmpleado (eEmpleado x);

int main()
{
    eEmpleado unEmpleado={ 1234,"Juan",30,'m',20000.50, {27,4,2020} };
    eEmpleado segundoEmpleado;
    eEmpleado tercerEmpleado;

    printf("%d %s %c %.2f %d\n", unEmpleado.id,unEmpleado.nombre,unEmpleado.sexo,unEmpleado.sueldo,unEmpleado.edad);

    segundoEmpleado=unEmpleado;

    mostrarEmpleado(segundoEmpleado);

    printf("Ingrese id:\n");
    scanf("%d",&tercerEmpleado.id);

    printf("Ingrese nombre:\n");
    fflush(stdin);
    gets(tercerEmpleado.nombre);

    printf("Ingrese su sexo:\n");
    fflush(stdin);
    scanf("%c",&tercerEmpleado.sexo);

    printf("Ingrese sueldo:\n");
    scanf("%f",&tercerEmpleado.sueldo);

    printf("Ingrese la edad:\n");
    scanf("%d",&tercerEmpleado.edad);

    /*printf("Ingrese dia de ingreso:\n");
    scanf("%d",&tercerEmpleado.fechaIngreso.dia);

    printf("Ingrese mes de ingreso:\n");
    scanf("%d",&tercerEmpleado.fechaIngreso.mes);

    printf("Ingrese año de ingreso:\n");
    scanf("%d",&tercerEmpleado.fechaIngreso.año);*/

    printf("Ingrese fecha de ingreso dd/mm/aaa:\n");
    scanf("%d/%d/%d",&tercerEmpleado.fechaIngreso.dia,&tercerEmpleado.fechaIngreso.mes,&tercerEmpleado.fechaIngreso.anio);//el user tiene que poner la barra

    mostrarEmpleado(tercerEmpleado);

}

void mostrarEmpleado(eEmpleado x)
{
    printf("%d %s %c %.2f %d %02d/%02d/%02d\n", x.id,x.nombre,x.sexo,x.sueldo,x.edad,x.fechaIngreso.dia,x.fechaIngreso.mes,x.fechaIngreso.anio);

}
