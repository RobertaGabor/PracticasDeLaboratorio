#include <stdio.h>
#include <stdlib.h>

int main()
{

    int auxiliarVendedor;
    float auxiliarIgreso;
    int vendedor1;
    float acumulador1=0;
    float ingreso1;
    int vendedor2;
    float ingreso2;
    float acumulador2=0;
    int vendedor3;
    float acumulador3=0;
    float ingreso3;
    int seguir=1;
    int i=0;

    do
    {
       printf("Ingrese numero de vendedor:\n");
       scanf("%d",&auxiliarVendedor);

       printf("Ingrese lo cobrado en la boleta:\n");
       scanf("%f",&auxiliarIgreso);

       if(i==0||auxiliarVendedor==vendedor1)
       {
           vendedor1=auxiliarVendedor;
           ingreso1=auxiliarIgreso;
           acumulador1+=ingreso1;
       }
       else
       {
           if(auxiliarVendedor==vendedor2)
           {
                vendedor2=auxiliarVendedor;
                ingreso2=auxiliarIgreso;
                acumulador2+=ingreso2;
           }
           else
           {
               vendedor3=auxiliarVendedor;
               ingreso3=auxiliarIgreso;
               acumulador3+=ingreso3;
           }
       }

       printf("Desea continuar? escriba 0 para finalizar sino continuara\n");
       fflush(stdin);
       scanf("%d",&seguir);
       i++;
    }while(seguir!=0);

    printf("vendedor 1 es %d vendedor 2 es %d vendedor 3 es %d\n",acumulador1,acumulador2,acumulador3);
    return 0;
}
