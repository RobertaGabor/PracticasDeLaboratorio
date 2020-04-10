#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    char letra;
    char seguir;//para que sea hasta que el usuario quiera
    int contadorPares;
    int contadorImpar;
    int contadorCeros;
    int acumuladorNegativos;
    int acumuladorPositivos;
    int contadorPositivos;
    float promedioPositivos;
    int maximo;
    int minimo;
    char letraMaximo;
    char letraMinimo;
    int flag;

    contadorPares=0;
    contadorImpar=0;//contador cuenta o acumula
    contadorCeros=0;
    acumuladorNegativos=0;
    acumuladorPositivos=0;
    contadorPositivos=0;
    flag=0;

    do
    {
        printf("Ingrese una letra: ");
        fflush(stdin);// en caracter o cadena se usa si o si
        scanf("%c",&letra);

        printf("Ingrese un numero: ");
        scanf("%d",&numero);//numero no lleva el fflush

        while(numero<-100 || numero>100)//falta validar que SEA un numero
        {
            printf("Error, ingrese numero entre -100 y 100");
            scanf("%d",&numero);
        }

        //analizo la paridad del numero
        if(numero%2==0)
        {
            contadorPares++;
        }
        else
        {
            contadorImpar++;
        }

        //analizo el signo del numero

        if(numero==0)
        {
            contadorCeros++;
        }
        else
        {
            if(numero<0)
            {
                acumuladorNegativos=acumuladorNegativos+numero;// puedo usar acumuladorNegativos += numero;
            }
            else
            {
                acumuladorPositivos+=numero;
                contadorPositivos++;
            }
        }

        //maximos y minimos

        if(flag==0)
        {
           maximo=numero;
           minimo=numero;
           letraMaximo=letra;
           letraMinimo=letra;
        }
        else
        {
            if(numero>maximo)
            {
                maximo=numero;
                letraMaximo=letra;
            }
            else
            {
                if(numero<minimo)
                {
                    minimo=numero;
                    letraMinimo=minimo;
                }
            }
        }
        /*if(numero>maximo||flag==0)
        {
        maximo=numero
        letramaxima=letra
        }
        if(numero<minimo||flag==0)
        {
        minimo=numero
        letraminima=letra
        flag=1
        }*/

        printf("Quiere continuar?: \n");
        fflush(stdin);
        flag++;//va antes o despues de flush, flush solo liampia o ingresado por sanf
        scanf("%c",&seguir);
    }while(seguir=='s');//si es comparacion de char con char comillas simples

    if(contadorPositivos!=0)
    {
        promedioPositivos=(float) acumuladorPositivos/contadorPositivos;//porque no se puede dividir por cero
        //el float dice acumulador float dividido por contador int es float.
    }
    //muestro resultados
    system("cls");//liampia todo lo ingresado y solo muestra resultados
    //system antes de mostrar resultados
    printf("a-cantidad de pares: %d\n",contadorPares);
    printf("b-cantidad de impares: %d\n",contadorImpar);
    printf("c-cantidad de ceros: %d\n",contadorCeros);
    printf("d-promedio de positivos: %.2f\n",promedioPositivos);
    printf("e-suma de negativos: %d\n",acumuladorNegativos);
    printf("f-numero maximo: %d y letra maxima: %c\n",maximo,letraMaximo);
    printf("g-numero minimo: %d y letra minima: %c\n",minimo,letraMinimo);

    return 0;
}
