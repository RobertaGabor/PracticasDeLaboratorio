#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float kilos;
    char sabor[10];
    int i;
    float acumuladorKilos;
    float promedioKilos;
    float kilosMinimo;
    char kilosMinimoSabor[10];
    int cantidadBolsasCarne;
    float acumuladorKilosCarne;
    float promedioKiloCarnes;

    acumuladorKilos=0;
    cantidadBolsasCarne=0;
    acumuladorKilosCarne=0;

    for(i=0;i<10;i++)
    {
        do
        {
            printf("Ingrese el kilo de la bolsa:\n");
            scanf("%f",&kilos);
        }while(kilos<0||kilos>500);

        do
        {
            printf("\nIngrese el sabor:\n");
            printf("\nvegetales\n");
            printf("\ncarne\n");
            printf("\npollo\n");
            printf("\nRespete las minusculas\n");
            fflush(stdin);
            scanf("%s",sabor);
        }while(strcmp(sabor,"carne")!=0&&strcmp(sabor,"pollo")!=0&&strcmp(sabor,"vegetales"));//comparacion de strings
        //la comparacion si son iguales da 0 y ese se compara con el !=0 o 1. si son iguales da 0 y 0!=0 no entra.
        acumuladorKilos+=kilos;

        if(i==0||kilos<kilosMinimo)
        {
            kilosMinimo=kilos;
            strcpy(kilosMinimoSabor,sabor);
        }

        if(strcmp(sabor,"carne")==0)
        {
            acumuladorKilosCarne+=kilos;
            cantidadBolsasCarne++;

        }

    }

    promedioKilos=(float)acumuladorKilos/i;
    promedioKiloCarnes=(float)acumuladorKilosCarne/cantidadBolsasCarne;

    system("cls");

    printf("Promedio de kilos totales es: %.2f\n",promedioKilos);
    printf("La bolsa mas liviana pesa %.2f y es de sabor %s\n",kilosMinimo,kilosMinimoSabor);
    printf("La cantidad de bolsas de carne es %d y el promedio de kilos es %.2f\n",cantidadBolsasCarne,promedioKiloCarnes);


    return 0;
}
