#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{

int id;
char marca[20];
char modelo[20];
int anio;

}eAuto;

class iAuto{
public int id;
private char marca[20];
protected char modelo[20];/*privada y protected no entras al campo con .*/
private int anio;
public void saludar;
printf("Hola mundo");
};

int main()
{
    iAuto* unAuto=new iAuto;
    iAuto.id;
    return 0;
}

eAuto* new_Auto()
{
   return (eAuto*)malloc (sizeof(eAuto));
}
if(auto_setId(auto1,atoi(id))!=0)/*una forma es setear afuera de param*/

eAuto* new_AutoParamCadena(char* id,char* marca,char* modelo,char* anio)/*PASO COMO CADENA Y ADENTRO CON EL SETER USO ATOI Y CONVIERTO*/
/*otra forma es usar todas cadenas y en los seter convertir si esta bien*/

/*PARSEAR*/

//csv comma separate values

1234,Ford,Focus,2018/*misma variable campos separados por comas*/
1287,Renault,Arol,2019/*distintas variables separadas por \n*/
/*lectura como texto*/


int auto_destroy(eAuto* unAuto)/*ESTA DENTRO DE LA BAJA*/
{
    int retorno=1;

    if(unAuto!=NULL)
    {
        free(unAuto);
        *unAuto=NULL;
        retorno=0;
    }

    return retorno;
}
