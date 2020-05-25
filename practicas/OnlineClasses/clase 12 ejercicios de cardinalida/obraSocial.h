#ifndef OBRASOCIAL_H_INCLUDED
#define OBRASOCIAL_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eObraSocial;


void mostrarObras (eObraSocial obraSocial[],int tamObr);
int cargarDescripcionObra(char descripcion[],int id,eObraSocial obras[],int tamObr);
#endif // OBRASOCIAL_H_INCLUDED
