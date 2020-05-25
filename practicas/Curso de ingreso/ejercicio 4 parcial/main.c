#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d",&num1);

    printf("Ingrese otro numero: ");
    scanf("%d",&num2);

    if(num1==num2)
    {
        printf("%d%d\n\n"num1,num2);
    }
    else
    {
       if(num1>num2)
       {
           resultado=num1-num;
           printf("%d",resultado);
       }
       else
       {
            resultado=num1+num2;
            if(resultado>10)
            {
                printf("El resultado es %d y es mayor a 10",resultado);
            }
            else
            {
                printf("El resultado es %d no supera 10",resultado);
            }
       }
    }

    return 0;
}
