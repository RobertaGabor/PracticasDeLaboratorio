#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{

int id;
char descripcion[30];

}eTipo;

typedef struct{

char nombre[30];
int tipo;
char raza[30];
int edad;
float peso;
char sexo;
int isEmpty;
int idDuenio;
int idMasc;

}eMascota;

#endif // MASCOTAS_H_INCLUDED
