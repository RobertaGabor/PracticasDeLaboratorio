#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena1[20]="juan";
    char cadena2[20]="jose";


    strcmp(cadena1,cadena2);//case sensitive
    //el si se diferencian por una mayuscula o minuscula (se restan sus ascii, si es -1 o 1, es si se resto primero la mayuscula o al minuscula

    /*==0
    !=0
    ==-1-->izquierda antes en el diccionario que la derecha
    ==1-->primer parametro despues que el segundo en el diccionario*/

    //stricmp() igual pero no considera la mayu o minu.


    strcat(cadena1," ");//paso espacio en blanco entre 2 "", porque si pongo '' es para char
    //cadena1 ya queda concatenado y queda cargado. solo se modifica la primer cadena (cadena de destino
    strcat(cadena1,cadena2);//in indice [0] se copia en el \0  ajeno. SE CONCATENA
    //al 1er parametro se le concatena el segundo.
    /*ya que concatenamos a cadena 1 (primer parametro osea es strleng de cadena1 + cadena2 no tiene que superar el strlen de cadena 1 -1*/



    return 0;
}
