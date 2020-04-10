#include <stdio.h>
#include <stdlib.h>

int main()
{
    char planeta;// hecho sin cadenas switch (porque no se puede)

    printf("Planetas: \n");
    printf("a - Mercurio\n");
    printf("b - Marte\n");
    printf("c - Tierra\n");
    printf("d - Venus\n");

    printf("\n\nIngrese opcion del planeta: \n");
    scanf("%c",&planeta);

    switch(planeta)
    {
    case 'a':
    case 'b':
        printf("\nAca hace mas calor");
        break;
    case 'c':
        printf("\nAca vivimos");
        break;
    case 'd':
        printf("\nAca hace mas frio");
        break;
    default:
        printf("\nPlaneta no valido");
    }



    return 0;
}
