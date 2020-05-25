#include <stdio.h>
#include <stdlib.h>
int factorial (int a);
int factorialRecursivo (int a);
int main()
{




    return 0;
}
int factorial(int a)// --> VERSION NORMAL
{
    int fact;
    int i;
    fact=1; //porque sino 0 por cualquier cosa es 0
    for(i=1;i<fact;i++)//i=1 porque 0 por cualquier cosa es 0
    {
        fact=fact*i;
    }

    return fact;
}
int factorialRecursivo(int a)
{
    int fact;

    if(a>-1)//asi toma el cero
    {
        if(a==1)
        {
            fact=1;
        }
        else
        {
            fact=a*factorialRecursivo(a - 1);//funciona porque en algun momento va a llegar a 1, y de ahi va a dar todos los resultados, ya que es un resutao fijo, no llama a nadie
        }
    }

    return fact;
}
