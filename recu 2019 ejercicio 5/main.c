#include <stdio.h>
#include <stdlib.h>

int main()
{
    char continente;
    int dias;
    int precioPorDia;
    char metodoDePago;
    int porcentaje;
    int precioTotal;

    porcentaje=0;

    do
    {
        printf("Ingrese a que continente quiere viajar: \n");
        printf("\nIngrese A -si es america\n");
        printf("\nIngrese O -si es oceania\n");
        printf("\nIngrese F -si es africa\n");
        printf("\nIngrese E -si es europa\n");
        printf("\nIngrese S -si es asia\n");
        printf("\nRespete las mayusculas\n");
        fflush(stdin);
        scanf("%c",&continente);
    }
    while(continente!='A'&&continente!='O'&&continente!='F'&&continente!='F'&&continente!='E'&&continente!='S');

    do
    {
        printf("\nIngrese la cantidad de dias de hospedaje: \n");
        scanf("%d",&dias);
    }
    while(dias<1);

    do
    {
        printf("\nIngrese metodo de pago: \n");
        printf("\nIngrese D -si es debito\n");
        printf("\nIngrese E -si es efectivo\n");
        printf("\nIngrese M -si es mercado pago\n");
        printf("\nIngrese C -si es cheque\n");
        printf("\nRespete las mayusculas\n");
        fflush(stdin);
        scanf("%c",&metodoDePago);
    }
    while(metodoDePago!='D'&&metodoDePago!='E'&&metodoDePago!='M'&&metodoDePago!='C');

    precioPorDia=dias*100;

    switch(continente)
    {
    case 'A':
        porcentaje=15;
        switch(metodoDePago)
        {
        case 'D':
            porcentaje=25;
            break;
        case 'C':
            porcentaje=0;
            break;
        }
        break;
    case 'F':
    case 'O':
        porcentaje=30;
        switch(metodoDePago)
        {
        case 'M':
        case 'E':
            porcentaje=45;
            break;
        case 'C':
            porcentaje=15;
            break;
        }
        break;
    case 'E':
        porcentaje=20;
        switch(metodoDePago)
        {
        case 'D':
            porcentaje=35;
            break;
        case 'M':
            porcentaje=30;
            break;
        case 'C':
            porcentaje=5;
            break;
        default:
            porcentaje=25;
        }
        break;
    default:
        porcentaje=-20;
        switch(metodoDePago)
        {
        case 'C':
            porcentaje=-35;
            break;
        }
    }

    precioTotal=precioPorDia-precioPorDia*porcentaje/100;

    system("cls");

    printf("\nSu total sin descuento es %d\n",precioPorDia);
    printf("\nSu descuento es del: %d\n",porcentaje);
    printf("\nSu precio a pagar es %d\n",precioTotal);

    return 0;
}
