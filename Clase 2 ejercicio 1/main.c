/*Ejercicio:
Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int acumuladorPromedio;
    int contadorPromedio;
    int numeroMaximo;
    int numeroMinimo;
    float promedio;

    acumuladorPromedio=0;
    contadorPromedio=0;

    for(i=0;i<5;i++)
    {
        printf("\nIngrese un numero:\n");
        scanf("%d",&numero);

        acumuladorPromedio+=numero;
        contadorPromedio++;

        if(i==0)
        {
            numeroMaximo=numero;
            numeroMinimo=numero;
        }
        else
        {
            if(numero>numeroMaximo)
            {
                numeroMaximo=numero;
            }
            else
            {
                if(numero<numeroMinimo)
                {
                    numeroMinimo=numero;
                }
            }
        }
    }
    promedio=(float)acumuladorPromedio/contadorPromedio;
    printf("El promedio de los numeros es %.2f\n",promedio);
    printf("\nEl mayor numero es %d y el menor es %d\n",numeroMaximo,numeroMinimo);
    return 0;
}
