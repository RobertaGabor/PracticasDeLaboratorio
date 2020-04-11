#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char letra;
    int i;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;

    for(i=0;i<20;i++)
    {
        do
        {
            printf("Ingrese una letra:\n");
            fflush(stdin);
            scanf("%c",&letra);
        }while(!isalpha(letra));

        switch(letra)
        {
        case 'a':
            contadorA++;
            break;
        case 'e':
            contadorE++;
            break;
        case 'i':
            contadorI++;
            break;
        case 'o':
            contadorO++;
            break;
        case 'u':
            contadorU++;
            break;
        }
    }
    printf("La cantidad de A es %d\n",contadorA);
    printf("La cantidad de E es %d\n",contadorE);
    printf("La cantidad de I es %d\n",contadorI);
    printf("La cantidad de O es %d\n",contadorO);
    printf("La cantidad de U es %d\n",contadorU);

    return 0;
}
