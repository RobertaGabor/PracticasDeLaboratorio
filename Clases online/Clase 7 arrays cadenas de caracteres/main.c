#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];//puedo guardar 19 letras.
    char nombre2[20];

    printf("Ingrese su nombre: \n");
    fflush(stdin);
    //scanf("%s",nombre);//NO NECESITA & PORQUE YA E SUNA CADENA DE CARACTERES (ES UN VECTOR)
    //pero te toma solo la primer palabra.
    gets(nombre);
    printf("%s\n",nombre);//si escribe 19 caracteres pero APRETA ENTER (+ de 19) scanf va apisar memoria

    //COMO COPIAR CADENAS

    strcpy(nombre2,nombre);
    printf("%s\n",nombre2);

    return 0;
}
