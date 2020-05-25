#include <stdio.h>
#include <stdlib.h>

int main()
{
    int precio;
    int descuento;
    float precioConDescuento;


    printf("Ingrese el precio: \n");
    scanf("%d",&precio);

    printf("\nIngrese el descuento sin %: \n");
    scanf("%d",&descuento);

    precioConDescuento=precio-(float)precio*descuento/100;

    printf("\nEl precio con descuento es %.2f\n",precioConDescuento);

    return 0;
}
