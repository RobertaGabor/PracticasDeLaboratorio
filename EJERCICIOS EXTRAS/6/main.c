#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contadorMayor;
    int contadorMenor;
    int i;

    contadorMayor=0;
    contadorMenor=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&num);

        if(num>0)
        {
            contadorMayor++;
        }
        else
        {
            if(num<0)
            {
                contadorMenor++;
            }
        }
    }
    system("cls");
    printf("La cantidad de positivos son %d y la cantidad de negativos son %d\n",contadorMayor,contadorMenor);
    return 0;
}
