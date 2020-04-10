#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[15];
    char sexo;
    int edad;
    float nota;
    char seguir;
    int contadorVaronesAprobados;
    int acumuladorAdolescentes;
    int contadorAdolescentes;
    int acumuladorMenores;
    int contadorMenores;
    int acumuladorAdultos;
    int contadorAdultos;
    int acumuladorVarones;
    int contadorVarones;
    int acumuladorMujeres;
    int contadorMujeres;
    float promedioAdolescentes;
    float promedioAdultos;
    float promedioMenores;
    float promedioVarones;
    float promedioMujeres;

    contadorVaronesAprobados=0;
    acumuladorAdolescentes=0;
    contadorAdolescentes=0;
    acumuladorMenores=0;
    contadorMenores=0;
    acumuladorAdultos=0;
    contadorAdultos=0;
    acumuladorMujeres=0;
    contadorMujeres=0;
    acumuladorVarones=0;
    contadorVarones=0;

    do
    {

        printf("Ingrese nombre del/la estudiante:\n");
        fflush(stdin);
        scanf("%s",nombre);

        do
        {
            printf("\nIngrese su sexo:\n");
            printf("f -para femenino\n");
            printf("m -para masculino\n");
            printf("\nRespete las minusculas\n");
            fflush(stdin);
            scanf("%c",&sexo);
        }while(sexo!='m'&&sexo!='f');

        do
        {
            printf("\nIngrese su edad:\n");
            scanf("%d",&edad);
        }while(edad<0||edad>100);

        do
        {
            printf("\nIngrese la nota:\n");
            scanf("%f",&nota);
        }while(nota<0||nota>10);


        if(sexo=='m'&&nota>6)
        {
            contadorVaronesAprobados++;
        }

        if(edad<12)
        {
            acumuladorMenores+=nota;
            contadorMenores++;
        }
        else
        {
            if(edad>17)
            {
                acumuladorAdultos+=nota;
                contadorAdultos++;
            }
            else
            {
                acumuladorAdolescentes+=nota;
                contadorAdolescentes++;
            }
        }

        if(sexo=='m')
        {
            acumuladorVarones+=nota;
            contadorVarones++;
        }
        else
        {
            acumuladorMujeres+=nota;
            contadorMujeres++;
        }

        system("cls");
        printf("Desea continuar? ingrese s -para continuar, sino finalizará\n\n");
        printf("Respete las minusculas\n\n");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");
    }while(seguir=='s');
    promedioAdolescentes=(float)acumuladorAdolescentes/contadorAdolescentes;
    promedioAdultos=(float)acumuladorAdultos/contadorAdultos;
    promedioMenores=(float)acumuladorMenores/contadorMenores;
    promedioMujeres=(float)acumuladorMujeres/contadorMujeres;
    promedioVarones=(float)acumuladorVarones/contadorVarones;

    printf("La cantidad de varones aprobados es %d\n",contadorVaronesAprobados);
    printf("El promedio de notas de los menores de edad es %.2f\n",promedioMenores);
    printf("El promedio de notas de los adultos es %.2f\n",promedioAdultos);
    printf("El promedio de notas de los adolescentes es %.2f\n",promedioAdolescentes);
    printf("El promedio de mujeres es %.2f\n",promedioMujeres);
    printf("El promedio de varones es %.2f\n",promedioVarones);

    return 0;
}
