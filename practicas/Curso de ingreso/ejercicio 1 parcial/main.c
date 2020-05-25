#include <stdio.h>
#include <stdlib.h>

int main()
{
   int ancho;
   int largo;
   int perimetro;

   printf("Ingrese el ancho de un rectangulo: \n");
   scanf("%d",&ancho);
   printf("\nIngrese el largo de un rectangulo: \n");
   scanf("%d",&largo);

   perimetro=2*(ancho+largo);

   printf("\nEl rectangulo mide %d de ancho y %d de largo y el perimetro es %d\n",ancho,largo,perimetro);

    return 0;
}
