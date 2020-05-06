/*Crear una función que permita ingresar un numero al usuario y lo retorne. --> si dice que pedir el numero este en la funcion se pide en la funcion
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
el área de un círculo cuyo radio es ingresado por el usuario.
Documentar las funciones al estilo Doxygen.*/
#include <stdio.h>
#include <stdlib.h>
#include "funcionesclases.h"

int main()
{
    float radio;
    float area;
    radio=retorneNumero();//no se ve amenos que ponga aca un print f de mostrar o en la funcion, el retorn NO ES PRINTF
    area=sacarArea(radio);
    printf("El area es: %.2f\n",area);
    return 0;
}/*NO TIENE SENTIDO HACER UNA FUNCION DE PEDIR Y DEVOLEVR N NUMERO SI EN MAIN PEDIS EL NUMERO PORQUE EN
LA FUNCION NO HARIAS NADA.*/

