#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Solicitar al usuario 5 números, almacenar estos en un array de enteros,
permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
Permitir Modificar el valor de cualquiera de los números cargados indicando
el índice del mismo y su nuevo valor.*/
int main()
{
    int ingresoNumeros[5];
    int maximo;
    int minimo;
    float promedio;
    int acumulador;
    char poner[5][15];
    char relacion[3][15]={"Maximo","Minimo","Intermedio"};
    char seguir='s';
    int indice;
    char reescribir;

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&ingresoNumeros[i]);
    }


    do
    {
       acumulador=0;
       do
       {
            printf("Desea cambiar un numero?\n");
            printf("s - si desea continuar sino generara la lista\n");
            fflush(stdin);
            scanf("%c",&reescribir);
            if(reescribir=='s')
            {
                printf("Ingrese que indice desea cambiar:\n");
                printf("Indice  Numero\n");

                for(int i=0; i<5; i++)
                {
                    printf("%d      %d\n",i,ingresoNumeros[i]);
                }
                scanf("%d",&indice);
                for(int i=0;i<5;i++)
                {
                    if(i==indice)
                    {
                        printf("Ingrese el nuevo numero:\n");
                        scanf("%d",&ingresoNumeros[i]);
                    }
                }
            }
            else
            {
                break;
            }

        } while(reescribir=='s');

        for(int i=0; i<5; i++)
        {

            if(i==0)
            {
                maximo=ingresoNumeros[i];
                minimo=ingresoNumeros[i];
            }
            else
            {
                if(ingresoNumeros[i]>maximo)
                {
                    maximo=ingresoNumeros[i];
                }
                else
                {
                    if(ingresoNumeros[i]<minimo)
                    {
                        minimo=ingresoNumeros[i];
                    }
                }
            }


            acumulador+=ingresoNumeros[i];
        }

        for(int i=0; i<5; i++)
        {

            if(ingresoNumeros[i]==maximo)
            {
                strcpy(poner[i],relacion[0]);
            }
            else
            {
                if(ingresoNumeros[i]==minimo)
                {
                    strcpy(poner[i],relacion[1]);
                }
                else
                {
                    strcpy(poner[i],relacion[2]);
                }
            }

        }

        promedio=(float)acumulador/5;
        printf("::::::::Numeros ingresados::::::::::\n");
        printf("Indice        Numero        Relacion\n");

        for(int i=0; i<5; i++)
        {
            printf("   %d             %d          %s\n",i,ingresoNumeros[i],poner[i]);
        }

       printf("El promedido total es: %.2f\n",promedio);

       printf("Desea generar otra lista?\n");
       printf("s - para continuar sino finalizara\n");
       fflush(stdin);
       scanf("%c",&seguir);
    }while(seguir=='s');
    return 0;
}
