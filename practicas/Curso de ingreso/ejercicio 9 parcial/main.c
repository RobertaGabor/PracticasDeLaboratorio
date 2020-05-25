#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char marca[30];
    int peso;
    int temperatura;
    char seguir;
    int contadorTemperaturasPares;
    int i;
    int pesoMaximo;
    int pesoMinimo;
    char pesoMaximoMarca[30];//asterisco para poder asignar un espacio de vector, si no decis te dice warning
    int contadorTemperaturasBajoCero;
    int acumuladorPeso;
    float promedioPeso;

    contadorTemperaturasPares=0;
    i=0;
    contadorTemperaturasBajoCero=0;
    acumuladorPeso=0;

    do
    {
        printf("Ingrese marca del producto: \n");
        fflush(stdin);
        scanf("%s",marca);

        do
        {
            printf("\nIngrese el peso del producto: \n");
            scanf("%d",&peso);
        }while(peso<1||peso>100);

        do
        {
            printf("\nIngrese temperatura del producto: \n");
            scanf("%d",&temperatura);
        }while(temperatura<-30||temperatura>30);

        if(temperatura%2==0)
        {
            contadorTemperaturasPares++;
        }

        if(i==0)
        {
            pesoMaximo=peso;
            pesoMinimo=peso;
            strcpy(pesoMaximoMarca,marca);
        }
        else
        {
            if(peso>pesoMaximo)

            {
                pesoMaximo=peso;
                strcpy(pesoMaximoMarca,marca);//pone el contenido del segundo al primero
            }
            else
            {
                if(peso<pesoMinimo)
                {
                    pesoMinimo=peso;
                }
            }
        }

        if(temperatura<0)
        {
            contadorTemperaturasBajoCero++;
        }


        acumuladorPeso+=peso;

        i++;
        printf("\nDesea continuar? s- si, sino finalizará: \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }while(seguir=='s');

    system("cls");
    promedioPeso=(float)acumuladorPeso/i;

    printf("La cantidad de temperaturas pares es: %d\n",contadorTemperaturasPares);
    printf("Marca del producto mas pesado: %s\n",pesoMaximoMarca);
    printf("La cantidad de productos conservados bajo cero: %d\n",contadorTemperaturasBajoCero);
    printf("Promedio de peso de todos los productos: %.2f\n",promedioPeso);
    printf("Peso maximo: %d y peso minimo %d\n",pesoMaximo,pesoMinimo);

    return 0;
}
