#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{

char nombre[20];
int edad;
float peso;

}ePersona;

int main()
{
    ePersona per={"Juan",20,48.7};

                                                                           /*WRITE*/
    FILE* t = fopen("archivo.bin","wb");/*ABRIMOS PONEMOS BIN DE EXTENSION X COMODIDAD pero todos son binarios en realidad*/

    if(t==NULL)/*VALIDAMOS*/
    {
        printf("Problemas para abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    /*USAMOS*/
    fwrite(&per,sizeof(ePersona),1,t);/*aca si funciona en WB*/

    fclose(t);/*CERRAMOS*/


                                                                        /*READ*/




    ePersona persona;
    FILE* g = fopen("archivo.bin","rb");

    if(g==NULL)/*VALIDAMOS*/
    {
        printf("Problemas para abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    /*USAMOS*/

    fread(&persona,sizeof(ePersona),1,t);
    printf("edad:%d nombre:%s peso:%.2f",persona.edad,persona.nombre,persona.peso);

    fclose(g);/*CERRAMOS*/
    return 0;
}
