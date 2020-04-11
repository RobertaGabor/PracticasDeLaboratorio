#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int cuadrado;
    do
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&num);
        if(num<0)
        {
            printf("Error, ingrese un numero mayor a 0\n");
        }
    }while(num<0);
    cuadrado=num*num;
    printf("el cuadrado de %d es %d",num,cuadrado);

    return 0;
}
