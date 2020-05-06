#include <stdio.h>
#include <stdlib.h>
#include "C:\ejercicios en C\PracticasDeLaboratorio\UTN_bibliotecaMain\utn_biblioteca.h"

/*Escribir la función calcularMayor(), la misma debe recibir dos números enteros
y devolver por referencia, el numero mayor. Deberá retornar un 1 sí encontró un
mayor, o un 0 si ambos números son iguales.*/

int main()
{
    char num1Auxiliar[20];
    char num2Auxiliar[20];
    int num1;
    int num2;
    int validacion1;
    int validacion2;
    int mayor;

    validacion1=utn_getStringNumeros("Ingrese un numero:\n",num1Auxiliar);
    validacion2=utn_getStringNumeros("Ingrese otro numero:\n",num2Auxiliar);

    if(validacion1!=0&&validacion2!=0)
    {
        num1=atoi(num1Auxiliar);
        num2=atoi(num2Auxiliar);
        utn_numeroMayor(num1,num2,&mayor);
        if(utn_numeroMayor==0)
        {
            printf("%d y %d son iguales\n");
        }
        else
        {
            printf("%d es el mayor de %d y %d\n",mayor,num1,num2);
        }
    }
    else
    {
        printf("Ingrese solo valores numericos\n");
    }


    return 0;
}
