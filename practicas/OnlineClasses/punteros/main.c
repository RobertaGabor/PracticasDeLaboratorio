#include <stdio.h>
#include <stdlib.h>
void duplicarNumero2 (int* p);

//void duplicarNumero (int x);
//int duplicarNumero (int x);
int main()
{
    int num=5;
    printf("Antes de la funcion num vale %d\n",num);
    duplicarNumero2(&num);//pongo & para escribir encima de la variable afuera
    printf("Despues de la funcion num vale %d\n",num);
    return 0;
}
/*void duplicarNumero (int x)//void significa que no retiorna nada que utilice como variable
{
    x=x*2;
    printf("Dentro de la funcion num vale %d\n",x);
}
int duplicarNumero (int x)//void significa que no retiorna nada que utilice como variable
{
    x=x*2;
    printf("Dentro de la funcion num vale %d\n",x);
    return x;//el print y el return se muestran separados, si invocas la funcion muestra print y lleva la variable
    //si pongo una variable igual a la funcion ejecuta los dos pero toma el valor de la funcion, ademas de mostrar el print.
}*/
void duplicarNumero2 (int* p)//void significa que no retiorna nada que utilice como variable
{
   *p=*p*2;
   printf("en main %d\n",*p);
}
