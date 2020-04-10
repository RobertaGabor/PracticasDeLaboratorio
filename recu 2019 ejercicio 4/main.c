#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resto;
    int resultado;

    printf("Ingrese un numero: \n");
    scanf("%d",&numero1);

    printf("Ingreso otro numero: \n");
    scanf("%d",&numero2);

    resto=numero1%numero2;

    if(numero1==numero2)
    {
        resultado=numero1*numero2;
        printf("\n%d\n",resultado);
    }
    else
    {
        if(resto==0)
        {
            resultado=numero1-numero2;
            printf("\n%d\n",resultado);
        }
        else
        {
            printf("\n%d\n",resto);
        }
    }
    if(resto>3)
    {
        printf("\nEl resto es mayor a 3\n");
    }

    return 0;
}
