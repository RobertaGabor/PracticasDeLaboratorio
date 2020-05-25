#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    float resultado;//no olvidar float si hay division!!

    printf("Ingrese un numero: ");
    scanf("%d",&num1);

    printf("Ingrese otro numero: ");
    scanf("%d",&num2);

    if(num1==num2)
    {
        printf("\n%d%d\n\n",num1,num2);
    }
    else
    {
        if(num1>num2)
        {
            if(num2!=0)
            {
               resultado=(float)num1/num2;
               printf("\n%.2f",resultado);
            }
            else
            {
                printf("Cero no es un numero válido para esta opcion\n\n");
            }
        }
        else
        {
            resultado=num1+num2;
            if(resultado<50)
            {
                printf("\nEl resultado es %0.f y es menor a 50",resultado);
            }
            else
            {
                printf("\nEl resultado es %0.f y es mayor a 50",resultado);
            }
        }
    }
    return 0;
}
