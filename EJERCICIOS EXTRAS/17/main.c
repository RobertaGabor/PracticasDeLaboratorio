#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sNum[20];
    int num;

    printf("Ingrese un numero:\n");
    fflush(stdin);
    scanf("%s",sNum);

    num=atoi(sNum);//atoi si no puede convertir todo en numero te tira 0.

    if(num!=0)
    {
        if(num%2==0)
        {
            printf("El numero %d es par\n",num);
        }
        else
        {
            printf("El numero %d no es par\n",num);
        }
    }
    else
    {
        printf("Error debe ingresar un numero\n");
    }

    system("pause");
    system("cls");
    return 0;
}
