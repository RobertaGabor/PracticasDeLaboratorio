#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "obraSocial.h"
#define TAM 5
#define TAMSEC 5
#define TAMCOM 5
#define TAMAL 30
#define TAMOBR 3

int main()
{
    char seguir='s';
    eEmpleado lista[TAM];
    int opcionMenu;
    int proximoId=1000;
    int proximoAlmuerzoID=20000;
    eSector sectores[TAMSEC]={{1,"Sistemas"},{2,"RRHH"},{3,"Ventas"},{4,"Compras"},{5,"Contable"}};
    eComida comidas[TAMCOM]={{100,"Milanesa",120},{101,"Pasta",120},{102,"Chowfan",150},{103,"Ensalada",90},{104,"Agua",60}};
    eAlmuerzo almuerzos[TAMAL];
    eObraSocial obraSocial[TAMOBR]={{800,"Omint"},{801,"Osde"},{802,"Das"}};

    inicializarAlmuerzos(almuerzos,TAMAL);
    inicializarEmpleados(lista,TAM);

    harcodeo(lista,4);
    mostrarEmpleados(lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR);
    proximoId+=4;//xq harcodeamos ya 4, asi que el proximo va a ser el que les sigue
    system("pause");
    do
    {
        opcionMenu=menu();
        switch(opcionMenu)
        {
        case 1:
            if(altaEmpleado(proximoId,lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR))
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR);
            break;
        case 3:
            bajaEmpleado(lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR);
            break;
        case 4:
            ordenarEmpleado(lista,TAM);
            break;
        case 5:
            mostrarEmpleados(lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR);
            break;
        case 6:
            informar(lista,TAM,sectores,TAMSEC,obraSocial,TAMOBR);
            break;
        case 7:
            /*alta almuerzo*/
            altaAlmuerzo(almuerzos,proximoAlmuerzoID,TAMAL,lista,TAM,sectores,TAMSEC,comidas,TAMCOM,obraSocial,TAMOBR);
            break;
        case 8:
            listarAlmuerzos(almuerzos,TAMAL,comidas,TAMCOM,lista,TAM);
            break;
        case 10:
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

    system("pause");
    }while(seguir=='s');

    return 0;
}


