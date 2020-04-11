#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int suma=0;
    for(i=0;i<100;i++)
    {
        if(i%3==0)
        {
            printf("%d\n",i);
            suma+=i;
        }
    }
    printf("La suma de todos los numeros multiplos de 3 es %d\n",suma);
    return 0;
}
