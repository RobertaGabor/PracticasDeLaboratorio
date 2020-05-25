#include <stdio.h>
#include <stdlib.h>
#define FILAS 5
#define COLUMNAS 20
#include <string.h>

int main()
{
    char letra='l';
    char nombre[COLUMNAS]="Miguel";
    char nombres[FILAS][COLUMNAS]={"Ana","Miguel","Julieta","Pepe","Susi"};
    char auxCad[COLUMNAS];
    char nombres2[FILAS][COLUMNAS];

    /*mostrar cadena de caracteres*/
    for(int i=0;i<FILAS;i++)
    {
        printf("%s\n",nombres[i]);
    }//lista de todos los nombres

    printf("%s\n",nombre);//cadena de caracteres
    printf("%s\n",nombres[1]);//cadena de caracteres dentro de vector

    /*mostrar un caracter de un nombre*/
    printf("%c\n",letra);//en escalar
    printf("%c\n",nombre[5]);//en cadena
    printf("%c\n",nombres[1][5]);//en vector de cadenas.Columnas tambien empiezan de 0

    /*carga secuancial*/
    for(int i=0;i<FILAS;i++)
    {
        printf("Ingrese un nombre:\n");
        fflush(stdin);
        gets(nombres2[i]);
    }

    /*swap de nombres orden alfabetico*/

    for(int i =0;i<FILAS-1;i++)
    {
        for(int j=i+1;j<FILAS;j++)
        {
            if(strcmp(nombres2[i],nombres2[j])>0)//strcmp devuelve 1 o 0
            {
                strcpy(auxCad,nombres2[i]);//se copia con funcion
                strcpy(nombres2[i],nombres2[j]);
                strcpy(nombres2[j],auxCad);
            }
        }
    }

    for(int i=0;i<FILAS;i++)
    {
        printf("%s\n",nombres2[i]);
    }

    return 0;
}
