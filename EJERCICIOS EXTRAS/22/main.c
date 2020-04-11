#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1=56;
    int num2=32;
    int auxiliar=num1;

    num1=num2;
    num2=auxiliar;

    printf("el valor de num1 es %d y el de num2 es %d",num1,num2);
    return 0;
}
