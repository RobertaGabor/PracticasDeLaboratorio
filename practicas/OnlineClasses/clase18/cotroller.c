#include <stdio.h>
#include <stdlib.h>
static int obtenerId()/*no aparece en .h, no pensada para que se llame de main*/
{
    static int id=20000;/*statics porque recuerda el ++ y no deja de estar en stack*/
    id++;

    return id;
}

int proximoId()
{
    return obtenerId();
}
