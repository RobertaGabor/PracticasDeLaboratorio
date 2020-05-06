#include <stdio.h>
#include <stdlib.h>

/** \brief busca un entero dentro de un array de enteros
 *
 * \param numero valor a buscar
 * \param vector donde se busca
 * \param tamaño del vector
 * \return el indice del elemento donde se encuentra el numero o -1 si no está
 *
 */
int buscarNumero (int numero, int x[],int tam);

//una que ssea optener mayor de un vector que nos pasan --> int obtenerMayor (int x[],int tam);
//otra que devuelva promedio --> float calcularPromedio(int x[], int tam)
//obtener menor tho.
int main()
{
    /*int numeros[5]={2,3,5,1,8};//memoria para 5 elementos
    int numeros[5]={};//memoria para 5 elementos

    printf("1) %d\n",numeros[2]); //acceso aleatorio

    for(int i=0;i<5;i++)//estructura secuencial (repetitiva) -->porque conozco tamaño de vector
    {
        printf("2) %d ",numeros[i]);
    }

    numeros[4]=10;//en el indice 4 ubicao un elemento 10
    printf("3)%d ",numeros[4]);

      for(int i=0;i<5;i++)//estructura secuencial (repetitiva) -->porque conozco tamaño de vector
    {
        scanf("%d",&numeros[i]);
    }

        for(int i=0;i<5;i++)//estructura secuencial (repetitiva) -->porque conozco tamaño de vector
    {
        printf("%d",&numeros[i]);
    }*/
    int numeros[]={4,6,8,3,5};

    printf("%d ",buscarNumero(6,numeros,5));
    printf("%d ",buscarNumero(12,numeros,5));

    return 0;
}
int buscarNumero (int numero,int x[],int tam)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(numero==x[i])
        {
            retorno=i;//el indice es con 0
            break;
        }
    }

    return retorno;
}
