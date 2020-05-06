#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    /*char letra = 'A';
    char letra2;
    char letra3 = 'a';
    char letra4;*/
    char letra5;

    /*letra2=tolower(letra);
    printf("%c",letra2);

    letra4=toupper(letra3);
    printf("\n%c",letra4);*/


    letra5=getch();
    letra5=getche();
    //getche es lo mismo pero te muestra el caracter en pantalle sin print
    letra5=getchar();
    //en getchar tenes que apretar la tecla enter despues de poner el caracter
    printf("%c",letra5);


    return 0;
}
