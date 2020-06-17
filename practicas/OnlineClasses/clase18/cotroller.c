#include <stdio.h>
#include <stdlib.h>
static int obtenerId(int* id)/*no aparece en .h, no pensada para que se llame de main*/
{
    int error=1;
    *id=20000;

    FILE* f;
    f=fopen("proximoId.bin","rb");

    if(f!=NULL)
    {
        fread(id,sizeof(int),1,f);

        fclose(f);
        error=0;
    }


    return error;
}

int actualizarId(int id)
{
    int error=1;
    id++;

    FILE* f=fopen("proximoId.bin","wb");

    if(f!=NULL)
    {
        fwrite(&id,sizeof(int),1,f);

        fclose(f);
        error=0;

    }
    return error;
}

void controllerAlta()
{
    int id;
    obtenerId(&id);
    printf("ID: %d\n",id);
    actualizarId(id);

}
