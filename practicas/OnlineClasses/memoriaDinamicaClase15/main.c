#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*estatico*/
    int x;/*reservo memoria estatica para un entero*/
    x=10;
    printf("x vale %d\n",x);

    /*dinamico*/
    int* p=(int*)malloc(sizeof(int));
    /*casteo de puntero void(malloc devuelve eso) a puntero entero que es lo que pido*/
    /*reservo memoria dinamica para un entero*/

    //p=NULL;
    if(p==NULL)
    {
        printf("No se consiguio memoria\n");
        exit(EXIT_FAILURE);//solo en main,en funciones no se usa EXIT
    }

    *p=10;
    printf("p vale %d\n",*p);


    /*VECTORES*/
    printf("\n---------------------\n");
    int y[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        printf("%d\n",y[i]);
    }


    int* q=(int*)malloc(5 * sizeof(int));
    int* aux;
    /*pido datos*/
    for(int i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",q+i);/*con dinamico es + i*/
    }
    printf("\n\n");
    /*muestro datos*/
    for(int i=0;i<5;i++)
    {
        printf("%d",*(q+i));
    }
/*agrandar*/
    aux=(int*)realloc(q,10 * sizeof(int));/*pones el total, no cuanto queres agrandar*/
    if(aux!=NULL)
    {
        q=aux;
        printf("\nSe pudo conseguir lugar\n");

        for(int i=5/*porque ya cargue 5*/;i<10;i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",q+i);
        }
        printf("\n\n");
        for(int i=0; i<10; i++)
        {
            printf("%d",*(q+i));
        }
/*achicar*/
        printf("\n\n");
        q=(int*)realloc(q,6 * sizeof(int));
        for(int i=0; i<6; i++)
        {
            printf("%d",*(q+i));
        }
/*inicializar en 0*/
        printf("\n\n");
        int* vec=(int*)calloc(6,sizeof(int));
        for(int i=0; i<6; i++)
        {
            printf("%d",*(vec+i));
        }
    }
    else
    {
        printf("No se pudo aumentar los bytes\n");
    }

    free(p);
    return 0;
}
