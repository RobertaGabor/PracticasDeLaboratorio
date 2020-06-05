#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{

char nombre[20];
int edad;

}ePersona;

int main()
{
    ePersona per={"Juan",20};

                                                                           /*WRITE*/
    FILE* f = fopen("archivo.bin","w");/*ABRIMOS PONEMOS BIN DE EXTENSIO X COMODIDAD*/

    if(f==NULL)/*VALIDAMOS*/
    {
        printf("Problemas para abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    /*USAMOS*/
    int x=1234;
    fprintf(f,"%d",x);
    fprintf(f,"\nHola mundo\n");//escribe el archivo

    /*escribir en binario*/

    fwrite(&x,sizeof(int),1,f);/*no se usa para lectura de texto*/

    fclose(f);/*CERRAMOS*/
                                                                        /*READ (me lo muestra en consola)*/



    FILE* g = fopen("archivo.text","r");
    char c;
    char cadena[100];
    if(g==NULL)/*VALIDAMOS*/
    {
        printf("Problemas para abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    /*USAMOS*/

    while(!feof(g))//mientras no haya llegado al final del archivo 2 FORMAS DE LEERLO
    {
        c=fgetc(g);//devuelve caracter
        fgets(cadena,100,g);

        printf("%c",c);//leo caracter a caracter y muestro eso
        printf("%s",cadena);
    }

    fclose(g);/*CERRAMOS*/

    return 0;
}
