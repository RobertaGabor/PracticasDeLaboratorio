#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copiarCadena (char cadenaDest[],char cadenaOrig[],int tam);

int main()
{
    char nombre1[5];
    char nombre2[5];

    printf("Ingrese un nombre:\n");
    fflush(stdin);
    gets(nombre1);

    copiarCadena(nombre2,nombre1,5);
    printf("Nombre copiado:\n");
    printf("%s",nombre2);
}

void copiarCadena(char cadenaDest[],char cadenaOrig[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        cadenaDest[i]=cadenaOrig[i];
    }
    cadenaDest[i]=cadenaOrig[i];
}

/*int main()
{
    char nombre[5];
    char nombre2[5];

    printf("Ingrese su nombre:\n");
    fflush(stdin);
    gets(nombre);

    copiarCadena(nombre2,nombre);//CADENA DESTINO MAYOR O IGUAL QUE CADENA ORIGEN

    printf("%s",nombre2);

    return 0;
}

void copiarCadena (char cadenaDest[],char cadenaOrig[])
{
    int i=0;//donde empieza

    while(cadenaOrig[i]!='\0')//no se cuantos caracteres voy a recorrer
    {
        cadenaDest[i]=cadenaOrig[i];
        i++;
    }
    cadenaDest[i]=cadenaOrig[i];//para que caracter \0 sea la misma al final.

}*/
