#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    /*int a;
    int b;
    int c;
    int d;*/
    int id;
    char cadena[3][128];
    char sexo;
    float sueldo;



    int cant;
    FILE* f;

    /*f=fopen("numero.txt","r");*/
    f=fopen("datos.csv","r");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(f))/*no llega al final*/
    {
        /*cant=fscanf(f,"%d,%d,%d,%d\n",&a,&b,&c,&d);*//*la coma sirve porque en txt se separan por comas*/

        /*ponemos el \n porque en el txt termine con \n asi que tambien lo capturamos*/

        cant=fscanf(f,"%d,%[^,],%[^,],%[^,],%c,%f\n",&id,cadena[0],cadena[1],cadena[2],&sexo,&sueldo);/*la coma sirve porque en txt se separan por comas*/
        printf("%d\n",cant);
        if(cant==6)/*cant==4*/
        {
            /*printf("%d %d %d %d\n",a,b,c,d);*/
            printf("%d,%s,%s,%s,%c,%.2f\n",id,cadena[0],cadena[1],cadena[2],sexo,sueldo);
        }
        else
        {
            break;
        }

    }

    fclose(f);
    return 0;
}

void leerPersonasCSV(ePersona** lista,int tam, char* nombreArchivo)
{

}
