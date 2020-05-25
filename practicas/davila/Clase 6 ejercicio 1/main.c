#include <stdio.h>
#include <stdlib.h>

/*Agregar a la biblioteca utn.h funciones para obtener y validar diferentes tipos de valores:

- Solo números, ej. 123436679
- Solo letras, ej. abBD
- Alfanumericos, ej. ab555gT6
- Teléfonos, ej. 4XXX-XXXX

Realizar un programa que pida al usuario el ingreso de un dato y determine con cuales de los tipos cumple.*/

int main()
{
    char ingreso[20];
    int validaTelefono;
    fgets(ingreso,20,stdin);
    for(int i=0;i<20;i++)
    {
        if(ingreso[i]=='\0'-1)
        {
            ingreso[i]='\0';
        }
    }

    validaTelefono=utn_validarTelefono(ingreso);
    if(validaTelefono==1)
    {
        printf("Es un telefono\n");
    }
    else
    {
        printf("No es un telefono\n");
    }


    return 0;
}

