#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char nacionalidad;
    int estudiosCursados;
    int antiguedad;
    char seguir;
    int contadorTarea=0;
    int contador=0;
    float porcentaje;

    do
    {
         do
        {
            printf("Ingrese nombre del empleado:\n");
            fflush(stdin);
            gets(nombre);
        }while(isdigit(nombre[0])!=0);
        do
        {
            printf("Ingrese nacionalidad:\n");
            printf("A - Argentino\n");
            printf("E - Extranjero\n");
            scanf("%c",&nacionalidad);
            nacionalidad=toupper(nacionalidad);
        }while(nacionalidad!='A'&&nacionalidad!='E');

        do
        {
            printf("Ingrese estudios cursados:\n");
            printf("1 - Primaria\n");
            printf("2 - Secundaria\n");
            printf("3 - Universitario\n");
            scanf("%d",&estudiosCursados);
        }while(estudiosCursados!=1&&estudiosCursados!=2&&estudiosCursados!=3);

        do
        {
            printf("Ingrese antiguedad:\n");
            scanf("%d",&antiguedad);
        }while(isdigit(antiguedad)==1);


        if(nacionalidad=='E'&&estudiosCursados==3&&antiguedad>=20)
        {
            printf("%s",nombre);
            contadorTarea++;
        }
        contador++;
        printf("Desea continuar? ingrese s sino finalizara\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }while(seguir=='s');
    porcentaje=(float)contadorTarea*100/contador;
    printf("::::::::Empleado extrajeros universitarios con antiguedad igual mayor a 20 años::::::::::\n");
    printf("Cantidad :%d\n",contadorTarea);
    printf("Cantidad de empleados en total: %d\n",contador);
    printf("Porcentaje de elegidos: %.2f\n",porcentaje);

    return 0;
}
