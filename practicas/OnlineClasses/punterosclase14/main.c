#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=4;
    int b=6;

    int* p;

    printf("a= %d y b=%d\n",a,b);
    printf("\nEl valor de A: %d\n\n",*(&a));
    printf("La direccion de memoria de a= %p y b=%p\n",&a,&b);

    *&a=35;/*sobreescribir la variable*/
    *&b=22;

    printf("\na= %d y b=%d\n",a,b);


    p=&a;

    printf("\n1-p vale= %d\n",*p);

    *p=30;/*modifico los valores de la direccion de memoria de a*/

    printf("\n2-p vale= %d y a vale= %d\n",*p,a);

    swap(&a,&b);

    printf("\nEn swap a= %d y b=%d\n",a,b);
}

void swap (int* x, int* y)
{
    int aux;

    aux=*x;
    *x=*y;
    *y=aux;
}
