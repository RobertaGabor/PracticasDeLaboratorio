#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int num;
    int i;
    int acumuladorAnteriores;
    acumuladorAnteriores=0;

    do
    {
        printf("Ingrese un numero:\n");
        fflush(stdin);
        scanf("%d",&num);
    }while(isalpha(num)!=0);

    for(i=0;i<num;i++)
    {
        acumuladorAnteriores+=i;
    }

    printf("La suma total de los numeros anteriores a %d es %d\n",num,acumuladorAnteriores);
    return 0;
}
