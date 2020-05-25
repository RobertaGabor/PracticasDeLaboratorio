#include <stdio.h>
#include <stdlib.h>
int pedirEnteroRango (char mensaje[],char mensajeError[],int min, int max,int iteraciones);
char pedirCaracter (char mensaje[],char mensajeError[],char caracter1, char caracter2);

int main()
{
    int numero;
    //int sexo;
    //int seguir;
    numero=pedirEnteroRango("Numero entre 1-56: ","\nError.Reingrese:\n",1,56,5);
    /*sexo=pedirCaracter("\nIngrese sexo f o m:\n","\nError reingrese\n",'f','m');
    printf("\nEl sexo es %c\n",sexo);
    printf("\n\nEl numero ingresado es %d\n\n",numero);
    seguir=pedirCaracter("\nDesea continuar?: s o n\n","\nError ingrese s o n\n",'s','n');
    if(seguir=='s')
    {
        printf("\nUsted desea continuar\n");
    }
    else
    {
        printf("\nUsted no desea continuar\n");
    }*/
    if(numero<1)//1 es el numero inferior elegido
    {
        printf("Usted supero sus chances");
    }
    else
    {
        printf("Su numero es %d",numero);
    }

    return 0;
}

int pedirEnteroRango (char mensaje[],char mensajeError[],int min, int max,int iteraciones)
{
    int a;

    printf("%s",mensaje);//pide uan vez asi que iteraciones va disminuyendo
    scanf("%d",&a);

   while(a<min||a>max)
   {
       iteraciones--;//rests uno al principio porque ya ingreso uno.
       if(iteraciones==0)
       {
           a=min-1;
           break;
       }//va antes del mensaje asi si supero va al break y no muestra
       printf("%s",mensajeError);
       scanf("%d",&a);
   }
   /*while(a<min||a>max)
    {
        printf("%s",mensajeError);
        scanf("%d",&a);
    }*/

    return a;//devuelve o el numero correcto o el min-1. en main aclaras cual es.
}
char pedirCaracter (char mensaje[],char mensajeError[],char caracter1, char caracter2)
{
    char letra;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&letra);

     while(letra!=caracter1&&letra!=caracter2)//usar siempre parametros
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&letra);
    }
    return letra;
}

