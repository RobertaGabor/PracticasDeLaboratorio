#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getString (char cadena[],int tam, char mensaje[],char mensajeError[],int reintentos);

int main()
{
    char nombre[5];
    char auxiliar[100];

    printf("Ingrese su nombre:\n");
    fflush(stdin);
    gets(auxiliar);//lo guardas en una que sea larga.

    printf("\n%d\n",strlen(auxiliar));//devuelve cant de caracteres de var que pase
    //no devuelve 100, si pones juan devuelve 4.

    //fgets(donde guardar//cantidad de caracteres//de donde se captura)
    fgets(nombre,5,stdin/*solo captura los caracteres pedidos y no le avisa nada al usuario*/);
    //si en caracteres pones 5 toma 4

    while(strlen(auxiliar)>=5)
    {
        printf("Nombre invalido, vuelva a ingresar:\n");
        fflush(stdin);
        gets(auxiliar);
    }

    strcpy(nombre,auxiliar);

    strupr(nombre);
    printf("\nSu nombre es %s\n",nombre);
    /*para modificar un solo caracter del nombre uso toupper (nombre[0]) en la misma osicion de la cadena!!*/
    nombre[0]/*piso el caracter original*/=toupper(nombre[0]);


    strlwr(nombre);
    printf("\nSu nombre es %s\n",nombre);

    /*si vemos que lol de auxiliar si entra en nombrem lo copiamos*/


    //____strncpy() para 3 parametros.


    return 0;
}
