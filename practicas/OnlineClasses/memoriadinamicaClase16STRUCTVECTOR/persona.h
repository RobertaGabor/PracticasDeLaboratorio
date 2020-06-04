#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


typedef struct{

int id;
char nombre[20];
char sexo;
float peso;

}ePersona;


int initPeople(ePersona** vec,int tam);/*paso lista y el tipo de putnero a puntero y el tamanio*/
int findSpot(int* indice,ePersona** vec,int tam);
int showPerson(ePersona* persona);
int showPeople(ePersona** vec,int tam);

/*-----------FUNCION CONSTRUCTORA-----------*/

ePersona* new_Person();
ePersona* new_PersonWithInfo(int id,char* name,char sexo,float peso);

#endif // PERSONA_H_INCLUDED
