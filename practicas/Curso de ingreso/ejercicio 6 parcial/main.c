#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora;

    printf("Ingrese una hora: \n");
    scanf("%d",&hora);

    switch(hora)
    {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        printf("\nEs de maniana\n");
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        printf("\nEs de tarde\n");
        break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("\nEs de noche\n");
        break;
    default:
        printf("\nHora no valida\n");
    }

    if(hora>19&&hora<25)
    {
        printf("\nHora de ir a dormir\n");
    }

    return 0;
}
