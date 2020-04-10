#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*void muestra(int a, int b);

int main()
{
    int a;
    int b;
    char nombreCompleto[30];

    printf("Ingrese nombre completo:\n");
    gets(nombreCompleto);

    printf("Su nombre es %s",nombreCompleto);

    printf("ingrese numero a\n");
    scanf("%d",&a);
    printf("ingrese numero b\n");
    scanf("%d",&b);

    muestra(a,b);
    printf("en main son %d y %d",a,b);

    return 0;
}
void muestra(int a, int b)
{
    a=b;
    printf("valores dentro de la funcion %d y %d",a,b);
}*/

int main ()
{
    //char a;		/* Variable 'a' de tipo char */
	//char *pchar;	/* Puntero a char 'pchar' */
	/*char letra;

    scanf("%c",&letra);
    letra=tolower(letra);
    printf("%c\n",letra);
    a='m';*/
	//pchar = &a;	/* 'pchar' <- @ de 'a' */
    /**pchar='c';
	printf("la direccion de memoria de 'a' es: %p \n", &a);
	printf("y su contenido es : %c \n", *pchar); */

	long num2;
    printf("%d",sizeof(num2));

    char* p;
    int n;
    n=10;
    p=(char*)malloc(n*sizeof(char)); /*Reserva memoria para 10 caracteres.
    malloc va a asignar, cada 2bites de memoria "...sizeof(char)...", un tamaño 'n' de memoria. la expresión "(char*)"
    es la función "cast" esta función convierte cualquier tipo de dato a otro tipo de dato, (en este caso convierte
    a un tipo de dato carácter).*/


}

