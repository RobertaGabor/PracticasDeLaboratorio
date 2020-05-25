#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[25];
    char ciudad[25];

    printf("Ingrese su nombre: \n");
    scanf("%s",nombre);

    printf("\nIngrese la ciudad donde vive: \n");
    scanf("%s",ciudad);

    printf("\nUsted es %s y vive en %s\n",nombre,ciudad);
    return 0;
}
