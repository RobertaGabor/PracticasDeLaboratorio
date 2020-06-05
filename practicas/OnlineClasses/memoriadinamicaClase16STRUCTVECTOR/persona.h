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



/*--------------GETTER Y SETTER---------------*/
int person_GetID(int* id,ePersona* person);
int person_GetPeso(float* peso,ePersona* person);
int person_GetNombre(char* nombre,ePersona* person);
int person_GetSexo(char* sexo,ePersona* person);

int person_SetID(ePersona* person,int id);
int person_SetPeso(ePersona* person,float peso);
int person_SetNombre(ePersona* person,char* nombre);
int person_SetSexo(ePersona* person,char sexo);

#endif // PERSONA_H_INCLUDED
