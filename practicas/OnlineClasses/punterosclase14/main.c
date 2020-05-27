#include <stdio.h>
#include <stdlib.h>

void swap (int* x, int* y);
int main()
{
    int a=4;
    int b=6;
    int vec[5]={4,3,2,7,9};

    int* p;

    printf("a= %d y b=%d\n",a,b);
    printf("\nEl valor de A: %d\n\n",*(&a));
    printf("La direccion de memoria de a= %p y b=%p\n",&a,&b);

    *&a=35;/*sobreescribir la variable*/
    *&b=22;

    printf("\na= %d y b=%d\n",a,b);


    p=&a;

    printf("\n1-p vale= %d\n",*p);

    *p=19;/*modifico los valores de la direccion de memoria de a*/

    printf("\n2-p vale= %d y a vale= %d\n",*p,a);

    swap(&a,&b);

    printf("\nEn swap a= %d y b=%d\n",a,b);

    printf("\n\nVector-----------------------------------------------------\n\n");

    printf("\nDireccion de vec: %p\n\n",&vec);//la direccion de vec es la del PRIMER ELEMENTO
    printf("\nDireccion de vec: %p\n\n",&vec[0]);//coinciden

    printf("\nMuestra el valor en indice 0 porque es la direccion de ese indice: %d\n\n",*vec);
    printf("\nPara obtener el valor del segundo elemento tengo que avanzar el sizeof del tipo de vector si es int +1=+4bytes: ");
    printf("\nValor de indice 2: %d\n\n",*(vec+1));

    printf("\n\nRecorro el vector en sus direcciones de memoria: \n\n");

    for(int i=0;i<5;i++)
    {
       printf("%d",vec[i]);/*NOTACION VECTORIAL CORCHETES*/
    }

    printf("\n..................\n");

    for(int i=0;i<5;i++)
    {
       printf("%d\n",*(vec+i));/*NOTACION DE PUNTEROS CON ASTERISCO*/
    }

}

void swap (int* x, int* y)
{
    int aux;

    aux=*x;
    *x=*y;
    *y=aux;
}

void mostrarVectorNotacionVectorial(int x[],int tam)/*NO SE USA MAS*/
{
    for(int i=0;i<tam;i++)
    {
       printf("%d",x[i]);
    }
}
void mostarVectorPuntero(int* x,int tam)/*con notacion puntero con asterisco*/
{
    for(int i=0;i<tam;i++)
    {
       printf("%d",*(x+i));
    }
}
