#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];
    float precio;

}eComida;

void listarComidas (eComida comidas[],int tamCo);//lista la comida los precios
int cargarDescripcionComidas(char descripcion[],int id,eComida comidas[],int tamCo);
#endif // COMIDA_H_INCLUDED


