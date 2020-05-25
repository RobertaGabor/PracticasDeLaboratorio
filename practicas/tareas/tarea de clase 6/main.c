#include <stdio.h>
#include <stdlib.h>

int buscarMaximo (int vector[],int tam);//listo
int buscarMinimo (int vector[],int tam);//listo
float promedioVector (int vector[],int tam);//listo
void mostrarVector (int vector[],int tam);
int buscarNumeroEnVector (int vector[],int tam,char mensaje[],int* numeroBuscar);

int main()
{
    int numero[5];
    int maximo;
    int minimo;
    int validacion;
    int numeroBuscado;
    int contadorBuscado=0;

    for(int i=0;i<5;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",&numero[i]);
    }
    mostrarVector(numero,5);

    maximo=buscarMaximo(numero,5);

    for(int i=0;i<5;i++)
    {
        if(numero[i]==maximo)
        {
            printf("\nubicacion: %d, maximo=%d\n",i+1,maximo);
        }
    }
    minimo=buscarMinimo(numero,5);

    for(int i=0;i<5;i++)
    {
        if(numero[i]==minimo)
        {
            printf("\nubicacion: %d, minimo=%d\n",i+1,minimo);
        }
    }

    printf("El promedio de vector es %.2f\n",promedioVector(numero,5));

    validacion=buscarNumeroEnVector(numero,5,"Ingrese que numero desea buscar en el vector\n",&numeroBuscado);

    for(int i=0;i<5;i++)
    {
        if(numeroBuscado==numero[i])
        {
            contadorBuscado++;
        }
    }

    if(validacion==1)
    {
        printf("El numero si se encuentra en el vector y se encuentra %d veces\n",contadorBuscado);
    }
    else
    {
        printf("El numero no se encuentra en el vector\n");
    }

    return 0;
}

void mostrarVector(int vector[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("%d ",vector[i]);
    }
}

int buscarMaximo (int vector[],int tam)
{
    int maximo;
    for(int i=0;i<tam;i++)
    {
        if(i==0||vector[i]>maximo)
        {
            maximo=vector[i];
        }
    }
    return maximo;
}

int buscarMinimo (int vector[],int tam)
{
    int minimo;
    for(int i=0; i<tam; i++)
    {
        if(i==0||vector[i]<minimo)
        {
            minimo=vector[i];
        }
    }
    return minimo;
}
float promedioVector (int vector[],int tam)
{
    int acumulador=0;
    int contador=0;
    float promedio;
    for(int i=0;i<tam;i++)
    {
        acumulador+=vector[i];
        contador++;
    }
    promedio=(float)acumulador/contador;
    return promedio;
}
int buscarNumeroEnVector (int vector[],int tam,char mensaje[],int* numeroBuscar)
{
    int validacion=0;

    printf("%s",mensaje);
    scanf("%d",numeroBuscar);

    for(int i=0;i<tam;i++)
    {
        if(*numeroBuscar==vector[i])
        {
            validacion=1;
            break;
        }
    }
    return validacion;
}

