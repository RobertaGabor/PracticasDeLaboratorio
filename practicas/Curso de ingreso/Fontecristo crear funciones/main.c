#include <stdio.h>
#include <stdlib.h>
#include "fontecristo.h"


int main()
{

    int num1;
    int rsptaPares;
    int rsptaImpares;
    int rsptaDivisibles;
    int rsptaPrimosTotales;


    printf("Ingrese un numero;\n");
    scanf("%d",&num1);

    rsptaPares=numerosPares(num1);
    rsptaImpares=numerosImpares(num1);
    rsptaDivisibles=numerosDivisible(num1);
    rsptaPrimosTotales=primosTotales(num1);

    printf("La cantidad de numeros pares entre %d y 0 es: %d\n",num1,rsptaPares);
    printf("La cantidad de numeros impares entre %d y 0 es: %d\n",num1,rsptaImpares);
    printf("Del 1 al 100 hay %d de numeros que se pueden dividir por %d\n",rsptaDivisibles,num1);
    numeroPrimo(num1);//el VOID de devolver solo se escribe no pones variables ni asignaciones, solo llamas a la funcion
    printf("La cantidad de numeros primos entre %d y 0 es: %d\n",num1,rsptaPrimosTotales);
    return 0;
}


