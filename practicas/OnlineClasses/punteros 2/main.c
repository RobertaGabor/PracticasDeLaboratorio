#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=20;
    int*p;//asignas el tipo que tiene la direccion.
    p=&x;//decis que p es la direcciond e memoria de x
    *p=30;//el valor de la direcciond e memoria de p es 30.
    printf("x vale %d\n",x);
    //printf("x vale %p\n",&x);%p muestra puntero y &x uestra la direccion
    return 0;
}
