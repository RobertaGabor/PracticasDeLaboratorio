#include <stdio.h>
#include <stdlib.h>

void saludar(void);
void despedir(void);

void queHago(void (*callBack)(void));//recibe funciones como parametros

int sumar (int a,int b);
int restar (int a,int b);
int multiplicar (int a,int b);
int calcular (int a,int b,int (*callBack)(int,int));

int main()
{

    int x=12;
    int z=5;
    int calculo;

    /*escalar*/
    int* p;
    p=&x;
    printf("%d\n\n",*p);

    /*funcion*/
    void (*pFunc)(void);
    saludar();

    pFunc=saludar;
    pFunc();

    pFunc=despedir;
    pFunc();

    /*llamo funcion con funciones*/
    queHago(saludar);
    queHago(despedir);

    calculo=calcular(x,z,sumar);
    printf("\nsuma: %d\n",calculo);
    calculo=calcular(x,z,restar);
    printf("resta: %d\n",calculo);
    calculo=calcular(x,z,multiplicar);
    printf("multiplicacion: %d\n",calculo);

    return 0;
}

void saludar(void)
{
    printf("Hola\n");
}

void despedir(void)
{
    printf("Chau\n");
}

void queHago(void (*callBack)(void))/*como las dos son iguales puedo pasar uno solo*/
{
    callBack();/*como esta llama a la mismo tipo llama a una funcion y listo*/
}/*si fuera dos funciones distintas no se podria por el prototipo*/
/*en lo antes hecho tendria que haber hecho 2 funciones queHago , una para cada accion*/

int sumar (int a,int b)
{
    int resultado;
    resultado=a+b;

    return resultado;
}

int restar (int a,int b)
{
    int resultado;
    resultado=a-b;

    return resultado;
}

int multiplicar (int a,int b)
{
    int resultado;
    resultado=a*b;

    return resultado;
}

int calcular (int a,int b,int (*callBack)(int,int))
{
    int calculo=callBack(a,b);
    return calculo;
}
