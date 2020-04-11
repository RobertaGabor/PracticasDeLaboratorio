#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resta;

    printf("Ingrese un numero:\n");
    scanf("%d",&num1);
    printf("Ingrese otro numero:\n");
    scanf("%d",&num2);

    resta=num1-num2;
    system("cls");
    if(resta>0)
    {
        printf("Resultado positivo");
    }
    else{
        printf("Resultado negativo");
    }
    return 0;
}
