#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define COLUMNA 20
#include <string.h>
void mostrarAlumnos (int legajos[],char sexos[],char nombres[][20],int parcial1[],int parcial2[],float promedios[],int tam);
int main()
{
    int legajos[TAM]={2121,3245,1234,1822,9213};
    char sexos[TAM]={'m','m','f','f','f'};
    int parcial1[TAM]={2,2,7,10,6};
    int parcial2[TAM]={2,7,8,9,5};
    float promedios[TAM]={2,4.50,7.50,9.50,5.50};
    float auxFloat;
    int auxInt;
    char auxChar;
    char auxCad[COLUMNA];
    char nombres2[TAM][COLUMNA]={"pepe","susi","cata","pedro","toto"};
    for(int i=0;i<TAM-1;i++)
    {
        for(int j=i+1;j<TAM;j++)
        {
            if(sexos[i]<sexos[j])//primero aparece los hombres y despues mujres. la f es menor que la j
            {
                auxFloat=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=auxFloat;

                auxInt=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxInt;

                auxInt=parcial1[i];
                parcial1[i]=parcial1[j];
                parcial1[j]=auxInt;

                auxInt=parcial2[i];
                parcial2[i]=parcial2[j];
                parcial2[j]=auxInt;

                auxChar=sexos[i];
                sexos[i]=sexos[j];
                sexos[j]=auxChar;

                strcpy(auxCad,nombres2[i]);
                strcpy(nombres2[i],nombres2[j]);
                strcpy(nombres2[j],auxCad);
            }
            else
            {
              if(sexos[i]==sexos[j])//primero aparece en mujeres descendente mayor nota y en hombre igual.
              {
                 if(promedios[i]<promedios[j])
                 {
                    auxFloat=promedios[i];
                    promedios[i]=promedios[j];
                    promedios[j]=auxFloat;

                    auxInt=legajos[i];
                    legajos[i]=legajos[j];
                    legajos[j]=auxInt;

                    auxInt=parcial1[i];
                    parcial1[i]=parcial1[j];
                    parcial1[j]=auxInt;

                    auxInt=parcial2[i];
                    parcial2[i]=parcial2[j];
                    parcial2[j]=auxInt;

                    auxChar=sexos[i];
                    sexos[i]=sexos[j];
                    sexos[j]=auxChar;

                    strcpy(auxCad,nombres2[i]);
                    strcpy(nombres2[i],nombres2[j]);
                    strcpy(nombres2[j],auxCad);
                  }

              }
            }
        }
    }

    mostrarAlumnos(legajos,sexos,nombres2,parcial1,parcial2,promedios,TAM);
    return 0;

}



void mostrarAlumnos (int legajos[],char sexos[],char nombres[][20],int parcial1[],int parcial2[],float promedios[],int tam)//si es mostrar datos de un solo alumno no va el tam.
{
    printf("Legajos     sexos     nombre      nota 1      nota 2     promedio\n");
    for(int i=0;i<tam;i++)
    {
        printf("%d          %c        %10s         %3d         %3d         %5.2f\n",legajos[i],sexos[i],nombres[i],parcial1[i],parcial2[i],promedios[i]);
    }
}
