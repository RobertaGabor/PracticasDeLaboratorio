#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int contadorPares;
    int contadorImpares;
    contadorImpares=0;
    contadorPares=0;

    for(i=0;i<101;i++)
    {
       if(i%2==0)
       {
           printf("numero par %d\n",i);
           contadorPares++;
       }
       else
       {
           printf("numero impar %d\n",i);
           contadorImpares++;
       }
    }

    printf("Cantidad de pares %d\n",contadorPares);
    printf("Cantidad de impares %d\n",contadorImpares);
    return 0;
}
