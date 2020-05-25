#include <stdio.h>
#include <stdlib.h>
#include <string.h>//si trabajo con cadenas agregar.
#include <ctype.h>
void normalizarNombre(char name[],char lastName[],char fullName[]);
int main()
{
    char nombre[20];
    char apellido[20];//cada uno tiene 19 esacio.38,mas coma y espacio t \0, 41.
    char nombreCompleto[41];//minimo para que no haya desbordamiento-

    printf("Ingrese nombre:\n");
    fflush(stdin);
    fgets(nombre,20,stdin);
    nombre[strlen(nombre)-1]='\0';

    printf("Ingrese apellido:\n");
    fflush(stdin);
    fgets(apellido,20,stdin);
    apellido[strlen(apellido)-1]='\0';

    normalizarNombre(nombre,apellido,nombreCompleto);
    puts(nombreCompleto);
    return 0;
}

void normalizarNombre(char name[],char lastName[],char fullName[])//no pasamos tamaño xq no importa recorrerlo tood, solo queremos saber el \0
{
    strcpy(fullName,lastName);
    strcat(fullName,", ");
    strcat(fullName,name);
    strlwr(fullName);
    fullName[0]=toupper(fullName[0]);

    for(int i=0;fullName[i]!='\0';i++)
    {
        if(fullName[i]==' ')
        {
            fullName[i+1]=toupper(fullName[i+1]);
        }
    }
}
