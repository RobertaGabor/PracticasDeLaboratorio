#include <stdio.h>
#include <stdlib.h>
#define TAM 5
/*pedir nota primer parcial y segundo. para 5 personas. y mostrar listado*/
int main()
{
    int parcial[TAM];
    int parcial2[TAM];
    float promedios[TAM];//en vectores el nombre es en plural
    int legajos[TAM];//porque no se de quien son los datos
    char sexos[TAM];
    float auxiliarFloat;
    int auxiliarInt;
    char auxiliarChar;//auxiliar segun tipod e dato;

    for(int i=0;i<TAM;i++)
    {
        printf("Ingrese legajo:\n");
        scanf("%d",&legajos[i]);
        printf("Ingrese sexo:\n");
        fflush(stdin);
        scanf("%c",&sexos[i]);
        printf("Ingrese nota del primer parcial:\n");
        scanf("%d",&parcial[i]);//se guarda en i
        printf("Ingrese nota del segundo parcial:\n");
        scanf("%d",&parcial2[i]);

        promedios[i]=(float)(parcial[i]+parcial2[i])/2;
    }

    /*ordenar*/
    for(int i=0;i<TAM-1;i++)//hacer auxiliar por cada vector que queremos swapear
    {
        for(int j=i+1;j<TAM;j++)
        {
            if(promedios[i]<promedios[j])//si queremos cambiar el criterio solo cambiamos eso
            {
                auxiliarFloat=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=auxiliarFloat;

                auxiliarInt=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxiliarInt;

                auxiliarInt=parcial[i];
                parcial[i]=parcial[j];
                parcial[j]=auxiliarInt;

                auxiliarInt=parcial2[i];
                parcial2[i]=parcial2[j];
                parcial2[j]=auxiliarInt;

                auxiliarChar=sexos[i];
                sexos[i]=sexos[j];
                sexos[j]=auxiliarChar;
            }
        }
    }

    printf("****Listado de notas****\n");
    printf("Legajos      Sexo      Nota p1      Nota p2     promedio\n");

    for(int i=0;i<TAM;i++)
    {
        printf("%4d     %c        %2d             %2d           %5.2f\n",legajos[i],sexos[i],parcial[i],parcial2[i],promedios[i]);//el 5 es la cifras TOTALES. si digo 2 decimales mas el punto queda libres 2 decimales.
    }
    //%2d porque sino el 10 me desfasa todo

    /*ordenar desde el mejor promedio hacia abajo*/

    //burbujero sobre criterio de ordenamiento
    //swap NO SOLO SOBRE EL CRITERIO, sino tambien swapear los otros vectores.
    //para eso hardcodeo, osea le doy valores yo asi no tengo que ir ingresando todo el tiempo.



    return 0;
}
