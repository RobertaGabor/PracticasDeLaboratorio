#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
    int x = 5;
    int y = 6;
    int *p;
    p = &x;
    p = &y;/*se queda con lo ultimo asignado*/
    *p = 10;/*cambia el valor de la direccion de memoria de y*/

    printf("x:  %d   y:  %d   p: %d",x,y,*p);/*con *p muestro lo que hay en el puntero*/
    /*assert(x == 5)
    assert(y == 10)*/

    printf("\n\n----------------------------------------------------------------\n\n");

    /*int &r = x no se puede usar una direccion como inicializacion de puntero*/
    int r=x;
    int *s = &x;/*se puede escribir asi*/
    int *p1;
    int *p2 = &r;

    p1=&r;/*o asi despues de definir puntero*/
    *p1=24;/*para modificar usamos asterisco*/



    printf(" r: %d   s:  %d  p2:  %d",r,*s,*p2);
    /*assert(s == p2)*/

    printf("\n\n----------------------------------------------------------------\n\n");

    int *d = &x;
    int *q = &y;
    int **pp = &d;
    pp = &q;//*pp = q
    **pp = 4;

    printf("d: %d q: %d pp: %d\n\n",*d,*q,**pp);
    /*assert(y == 4)
    assert(x == 5)*/

    funcion2();/*ME TIRA QUE ES NULL, ES DECIR NO CAMBIO A HOLA MUNDO*/
    funcion4();/*ESTE SI CAMBIO*/
    return 0;
}

void funcion1(char* p1)
{
    p1=(char*)malloc(20*sizeof(char));
    strcpy(p1,"Hola mundo\n");
}

void funcion2()
{
    char* p2= NULL;
    funcion1(p2);
    printf("%s",p2);
}

void funcion3(char** p1)
{
    *p1=(char*)malloc(20*sizeof(char));
    strcpy(*p1,"\nHola mundo\n");
}

void funcion4()
{
    char* p2= NULL;
    funcion3(&p2);
    printf("%s",p2);
}
