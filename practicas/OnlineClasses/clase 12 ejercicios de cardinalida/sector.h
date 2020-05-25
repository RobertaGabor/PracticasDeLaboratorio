#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED


typedef struct{//puede ir donde quiera porque en la estrctura de empleado va a ser un valor de tipo numerico

    int id;//PK...
    char descripcion[20];

}eSector;//no importa que vaya despues

void mostrarSectores (eSector sectores[],int tam);


#endif // SECTOR_H_INCLUDED


