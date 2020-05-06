#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
/*ordenar por x razon y que sea secuencial*/
/*hacer una funcion que hardcodee para chequer mejor*/
typedef struct{

    int dia;
    int mes;
    int anio;//no usar ñ

}eFecha;

typedef struct{

int id;//4 bytes
char nombre[20];//20 bytes-->corta el ancho de palabra. cada 4 bytes,tiene que ser multiplo
int edad;//4 bytes
char sexo;//1 bytes-->asigna 36 directo en vez de 32(si eliminas sexo da 32). cuando agrego este byte extra cambia los multiplos de 4. por eso corta en 36
float sueldo;//8 bytes
eFecha fechaIngreso;
int isEmpty;
} eEmpleado;

int menu(void);
void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado (eEmpleado x);
void mostrarEmpleados (eEmpleado vec[],int tam);
void ordenarEmpleado (eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleadoId(int id,eEmpleado vec[],int tam);
void altaEmpleado(eEmpleado vec[],int tam);
void bajaEmpleado(eEmpleado vec[],int tam);
void modificarEmpleado(eEmpleado vec[],int tam);
int main()
{
    char seguir='s';
    eEmpleado lista[TAM];
    int opcionMenu;

    inicializarEmpleados(lista,TAM);

    do
    {
        opcionMenu=menu();
        switch(opcionMenu)
        {
        case 1:
            altaEmpleado(lista,TAM);
            break;
        case 2:
            break;
        case 3:
            bajaEmpleado(lista,TAM);
            break;
        case 4:
            break;
        case 5:
            mostrarEmpleados(lista,TAM);
            break;
        case 6:
            break;
        case 7:
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

void mostrarEmpleado(eEmpleado x)
{
    printf("%d %10s    %c   %11.2f     %d   %02d/%02d/%02d\n", x.id,x.nombre,x.sexo,x.sueldo,x.edad,x.fechaIngreso.dia,x.fechaIngreso.mes,x.fechaIngreso.anio);

}

void mostrarEmpleados (eEmpleado vec[],int tam)
{
    int flag=0;
    printf("__Listado de empleados facheros__\n");
    printf(" ID     NOMBRE   SEXO   SUELDO       EDAD  FECHA DE INGRESO    \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i]);
            flag=1;
        }
        else
        {
            /*flag asi no muestra 100 veces lo mismo*/
        }
    }
    if(flag==0)
    {
        printf("No hay empleados\n");
    }
}

void ordenarEmpleado (eEmpleado vec[],int tam)
{
    eEmpleado auxiliarEmpleado;//porque queres swaear TODOS los datos de un empleado a otro, no solo id, ese es el criterio
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(vec[i].sexo>vec[j].sexo)
            {
                auxiliarEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxiliarEmpleado;
            }
            else
            {
                 if(vec[i].sexo==vec[j].sexo&&vec[i].sueldo>vec[j].sueldo)//como es numerico con signos, si es caracter strcmp
                {/*if(strcmp (vec[i].nombre,vec[j].nombre)>0)*/
                    auxiliarEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxiliarEmpleado;

                }
            }
        }
    }
}

void inicializarEmpleados(eEmpleado vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
      vec[i].isEmpty=1;  //usas una parte de la estructura para decir si esta vacio o no
    }//va vec porque es el nombre, lo otro es el tipo
}

int menu(void)
{
    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");
    printf("1-Alta de un empleados\n");
    printf("2-Modificar datos de un empleados\n");
    printf("3-Baja de un empleados\n");
    printf("4-Ordenar lista\n");
    printf("5-Imprimir lista\n");
    printf("6-Informes\n");
    printf("7-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[],int tam)
{
    int encontrado=-1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==1)//redundancia but wev
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

int buscarEmpleadoId(int id,eEmpleado vec[],int tam)
{
    int indice=-1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].id==id&&vec[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[],int tam)
{
    int indice=buscarLibre(vec,tam);
    int id;
    int existe;
    eEmpleado auxEmpleado;
    system("cls");
    printf("*****Alta de empleado*****\n");
    if(indice==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d",&id);
        existe=buscarEmpleadoId(id,vec,tam);

        if(existe!=-1)
        {
            printf("El id ya existe\n");
        }
        else
        {
            auxEmpleado.id=id;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);

            printf("Ingrese sexo: ");
            scanf("%c",&auxEmpleado.sexo);

            printf("Ingrese edad: ");
            scanf("%d",&auxEmpleado.edad);

            printf("Ingrese sueldo: ");
            scanf("%f",&auxEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaa: ");
            scanf("%d/%d/%d",&auxEmpleado.fechaIngreso.dia,&auxEmpleado.fechaIngreso.mes,&auxEmpleado.fechaIngreso.anio);

            auxEmpleado.isEmpty=0;

            vec[indice]=auxEmpleado;//las estructuras se copian asi nomas

        }
    }

}

void bajaEmpleado(eEmpleado vec[],int tam)
{
    int id;
    int indiceID;
    char confirmacion='s';
    system("cls");
    printf("******Baja de empleado********\n");
    printf("Ingrese un ID a dar de baja: ");
    scanf("%d",&id);

    indiceID=buscarEmpleadoId(id,vec,tam);
    if(indiceID==-1)
    {
        printf("No se encontro el ID\n");
    }
    else
    {
        mostrarEmpleado(vec[indiceID]);
        printf("Desea comfirmar baja?: \n");
        printf("s - para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            vec[indiceID].isEmpty=1;
        }
    }
}

void modificarEmpleado(eEmpleado vec[],int tam)
{
    int id;
    int indiceID;
    char confirmacion='s';
    float nuevoSueldo;


    system("cls");
    printf("******Modificar empleado********\n");
    printf("Ingrese un ID de empleado: ");
    scanf("%d",&id);

    indiceID=buscarEmpleadoId(id,vec,tam);
    if(indiceID==-1)
    {
        printf("No se encontro el ID\n");
    }
    else
    {
        mostrarEmpleado(vec[indiceID]);
        /*submenu de case sobre que modificar*/



        printf("Modificar sueldo?: ");
        fflush(stdin);
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f",&nuevoSueldo);
            vec[indiceID].sueldo=nuevoSueldo;
            printf("Se ha actualizado la informacion con exito\n");
        }
    }
}
