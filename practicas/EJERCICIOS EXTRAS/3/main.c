#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int producto;
    int cuadradoNum1;

    printf("Ingrese un numero:\n");
    scanf("%d",&num1);
    printf("Ingrese otro numero:\n");
    scanf("%d",&num2);

    producto=num1*num2;
    cuadradoNum1=num1*num1;

    system("cls");
    printf("El producto de %d y %d es %d y el cuadrado de %d es %d",num1,num2,producto,num1,cuadradoNum1);

    return 0;
}
