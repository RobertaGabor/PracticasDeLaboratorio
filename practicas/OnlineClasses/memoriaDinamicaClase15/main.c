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
    free(p);





    return 0;
}
