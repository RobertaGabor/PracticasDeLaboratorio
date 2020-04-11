#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i;
    int num;
    int acumuladorNum;
    int productoNum;

    acumuladorNum=0;
    productoNum=1;

    for(i=0;i<10;i++)
    {
        do
        {
            printf("Ingrese un numero distinto a cero:\n");
            fflush(stdin);
            scanf("%d",&num);
        }while((isalpha(num)!=0)||num==0);//si lo ingresado en el parametro de alpha es un alfabeto te tira cualquier numero distinto a 0(la funcion funciona correcta).

        if(num>0)
        {
            acumuladorNum+=num;
        }
        else
        {
            productoNum=num*productoNum;
        }
    }
    printf("La suma de los positivos es %d y el producto de los positivos %d\n",acumuladorNum,productoNum);
    return 0;
}
