#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt (char mensaje[]);
float getFloat (char mensaje[]);
char getLetra(char mensaje[]);

int main()
{
    int numeroMiesterioso;
    int numeroIngresado;
    int seguir;
    char again='s';


    printf("****JUEGO ADIVINA EL NUMERO****\n");

    while(again=='s')
    {
        srand (time(NULL));//HACE QUE NO REPITA NUMEROS
        numeroMiesterioso=rand() % (0+100);//FUNCION NUMERO ALEATORIO
        seguir=0;

        while(seguir==0)
        {

            numeroIngresado=getInt("Ingrese un numero del 0 al 99\n");

            if(numeroIngresado<0||numeroIngresado>99)
            {
                printf("Numero invalido, ingrese del 0 al 99\n");
                seguir=1;
            }
            else
            {
                if(numeroIngresado==numeroMiesterioso)
                {
                    printf("Felicidades ganaste!!");
                    seguir=1;
                }
                else
                {
                    if(numeroIngresado>numeroMiesterioso)
                    {
                        printf("Te pasaste!!\n");
                    }
                    else
                    {
                        printf("Te falta!!\n");
                    }
                }
            }
        }

        again=getLetra("Desea jugar devuelta? Ingrese s, sino finalizara\n");

    }

    return 0;
}


int getInt(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}
float getFloat(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}
char getLetra(char mensaje[])
{
    char letra;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&letra);

    return letra;
}
