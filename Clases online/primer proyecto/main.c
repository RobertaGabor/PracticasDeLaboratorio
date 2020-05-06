#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num1; //= 20;
   int num2; //= 30;
   float resultado;
   char letra;

   printf("Ingrese una letra: ");
   scanf("%c",&letra);

   printf("Ingrese un numero: ");
   scanf("%d",&num1);

   printf("Ingrese otro numero: ");
   scanf("%d",&num2);

   //resultado = num1 + num2;
   resultado = (float) num1 / num2;

   //printf("%d",resultado);
   //printf("%d + %d = %d",num1,num2,resultado);
   printf("\nnum 1 vale: %d \nnum 2 vale: %d \nresultado vale: %.2f \nel caracter ingresado es: %c \n",num1,num2,resultado,letra); //barra invertida

    return 0;
}
