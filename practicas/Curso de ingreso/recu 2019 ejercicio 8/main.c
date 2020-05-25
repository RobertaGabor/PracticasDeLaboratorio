#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char color[10];
    int valor;
    char seguir;
    int contadorRojos;
    int contadorRojosCaros;
    int contadorBaratos;
    int long acumuladorValorAutos;
    int i;
    float promedioValor;
    int valorMaximo;
    char valorMaximoColor[10];

    contadorRojos=0;
    contadorRojosCaros=0;
    contadorBaratos=0;
    acumuladorValorAutos=0;
    i=0;

    do
    {
        do
        {
            printf("\nIngrese el color del vehiculo:\n");
            printf("\nrojo\n");
            printf("\nverde\n");
            printf("\namarillo\n");
            printf("\nRespete las minunsculas\n");
            fflush(stdin);
            scanf("%s",color);
        }while(strcmp(color,"rojo")!=0&&strcmp(color,"verde")!=0&&strcmp(color,"amarillo")!=0);

        do
        {
            printf("\nIngrese el valor del vehiculo:\n");
            scanf("%d",&valor);
        }while(valor<0||valor>10000);

        if(strcmp(color,"rojo")==0)
        {
            contadorRojos++;
            if(valor>5000)
            {
                contadorRojosCaros++;
            }
        }
        if(valor<5000)
        {
           contadorBaratos++;
        }

        if(i==0||valor>valorMaximo)
        {
            valorMaximo=valor;
            strcpy(valorMaximoColor,color);
        }

        acumuladorValorAutos+=valor;
        i++;
        system("cls");
        printf("\nDesea continuar? ingrese s -si quiere continuar\n");
        printf("Respete las minusculas\n");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");
    }while(seguir=='s');
    system("cls");
    promedioValor=(float)acumuladorValorAutos/i;

    printf("La cantidad de autos rojos es %d\n",contadorRojos);
    printf("La cantidad de rojos con precio mayor a 5000 es %d\n",contadorRojosCaros);
    printf("La cantidad de autos con precio menor a 5000 es %d\n",contadorBaratos);
    printf("El promedio de valor de todos los autos es %.2f\n",promedioValor);
    printf("El auto mas caro vale %d y es de color %s\n",valorMaximo,valorMaximoColor);

    return 0;
}
