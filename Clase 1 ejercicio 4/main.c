/* -Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int numero;
    int i;
    int contadorPositivos;
    int contadorNegativos;

    contadorNegativos=0;
    contadorPositivos=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);

        if(numero<0)
        {
            contadorNegativos++;
        }
        else
        {
            contadorPositivos++;
        }
    }

    printf("La cantidad de positivos es %d y la de negativos es %d",contadorPositivos,contadorNegativos);
    return 0;
}
