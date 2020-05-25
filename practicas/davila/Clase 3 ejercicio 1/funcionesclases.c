#include <stdio.h>
#include <stdlib.h>
#include "funcionesclases.h"

float retorneNumero()
{
    float numero;
    printf("Ingrese un numero:\n");
    scanf("%f",&numero);

    return numero;
}
float sacarArea(float a)
{
    float area;
    area=3.14*a*a;

    return area;
}
