#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 200
/*1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales
se toman los siguientes datos (utilizar una estructura para representar a la persona.):
Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.
b- Mostrar un listado ordenado por Apellido*/
typedef struct{

    char nombre[20];
    char apellido[20];
    int legajo;
    int isEmpty;

}eAgenda;
int validarArray (char y[],int tam);
int validarNumber (char y[],int tam);

int getArray (char y[],int tam);
int getNumber (int* y);

int getString(char y[],int tam);

int buscadorEspacio (eAgenda x[],int tam);
void inicializar(eAgenda x[],int tam);

int alta(eAgenda x[],int tam);
int baja(eAgenda x[],int tam);
void mostrarPersona(eAgenda x);
void mostrarPersonas(eAgenda x[],int tam);
int menu(void);/*alta,baja,modificacion,imprimir,salir*/

int buscarLegajo (eAgenda x[],int tam,int legajo);

int main()
{
    eAgenda personas[TAM];
    int opcionMenu;
    inicializar(personas,TAM);
    do
    {
        opcionMenu=menu();
        switch(opcionMenu)
        {
        case 1:
           alta(personas,TAM);
            break;
        case 2:
            baja(personas,TAM);
            break;
        case 3:
            /*modificar el dato elegido del legajo elegido*/
            /*si desea seguir modificando*/
            break;
        case 4:
            mostrarPersonas(personas,TAM);
            break;
        case 5:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcionMenu!=5);

    return 0;
}

int menu(void)
{
    int retorno;
    printf("******Menu opciones******\n");
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Modificar\n");
    printf("4-Imprimir\n");
    printf("5-Salir\n");

    printf("\nQue opcion desea?: ");
    fflush(stdin);
    scanf("%d",&retorno);

    return retorno;
}

void inicializar(eAgenda x[],int tam)
{
    if(x!=NULL&&tam>0)
    {

        for(int i=0;i<tam;i++)
        {
            x[i].isEmpty=1;//en legajo queremos inicializar-->un criterio.
        }

    }

}

int alta(eAgenda x[],int tam)
{
    eAgenda auxiliar;
    int retorno=0;
    int legajo;
    char nombre[20];
    char apellido[20];
    int valida;
    int valida2;
    int indice;

    if(x!=NULL&&tam>0)
    {
        indice=buscadorEspacio(x,tam);
        if(indice==-1)
        {
            printf("No hay espacio disponible\n");
        }
        else
        {

            printf("Escriba el numero de legajo que desea agregar: ");

            if(!getNumber(&legajo))
            {
                printf("Error,ingrese un numero de legajo valido\n");
            }
            else
            {
                if(buscarLegajo(x,tam,legajo)!=-1)
                {
                    printf("Ese legajo ya esta en uso\n");
                }
                else
                {
                    printf("\nIngrese el nombre: ");
                    valida=getArray(nombre,sizeof(nombre));

                    printf("\nIngrese el apellido: ");
                    valida2=getArray(apellido,sizeof(nombre));

                    if(!valida2||!valida)
                    {
                        printf("\nIngrese el nombres o apellidos de solo letras\n");
                    }
                    else
                    {
                        strcpy(auxiliar.apellido,apellido);
                        strcpy(auxiliar.nombre,nombre);
                        auxiliar.legajo=legajo;
                        auxiliar.isEmpty=0;

                        x[indice]=auxiliar;//acordarse de si tiene iteraciones indicar en el indice de espacio encontrado
                        retorno=1;
                    }


                }
            }

        }

    }

    return retorno;
}

int buscadorEspacio (eAgenda x[],int tam)
{
    int retorno=-1;
    if(x!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(x[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int getString(char y[],int tam)
{
    char auxiliar[3000];
    int retorno=0;
    if(y!=NULL&&tam>0)
    {
        fflush(stdin);
        if(fgets(auxiliar,sizeof(auxiliar),stdin)!=NULL)
        {
            if(auxiliar[strlen(auxiliar)-1]=='\n')
            {
               auxiliar[strlen(auxiliar)-1]='\0';
            }
            if(strlen(auxiliar)<tam)
            {
                strncpy(y,auxiliar,tam);
                retorno=1;
            }
        }
    }
   return retorno;
}

int validarArray (char y[],int tam)
{
   int retorno=1;
  if(y!=NULL&&tam>0)
  {
     for(int i=0;i<tam&&y[i]!='\0';i++)
    {
        if((y[i]<'a'||y[i]>'z')&&(y[i]<'A'||y[i]>'Z'))
        {
            retorno=0;
            break;
        }
    }
  }

    return retorno;
}
int validarNumber (char y[],int tam)
{
  int retorno=1;
  if(y!=NULL&&tam>0)
  {
     for(int i=0;i<tam&&y[i]!='\0';i++)
    {
        if(y[i]>'9'||y[i]<'0')
        {
            retorno=0;
            break;
        }
    }
  }

    return retorno;
}
int getArray (char y[],int tam)
{
    int retorno=0;
    char auxiliar[tam];

    if(y!=NULL&&tam>0)
    {
        if(getString((auxiliar),tam)&&validarArray(auxiliar,tam))
        {
            strncpy(y,auxiliar,tam);
            retorno=1;
        }
    }

    return retorno;
}
int getNumber (int* y)
{
    int retorno=0;
    char auxiliarLegajo[11];


    if(y!=NULL)
    {
        if(getString(auxiliarLegajo,sizeof(auxiliarLegajo))&&validarNumber(auxiliarLegajo,sizeof(auxiliarLegajo)))
        {
                *y=atoi(auxiliarLegajo);
                retorno=1;
        }

    }

    return retorno;
}
int buscarLegajo (eAgenda x[],int tam,int legajo)
{
    int retorno=-1;
    if(x!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(x[i].legajo==legajo)
            {
                retorno=i;
                break;
            }

        }
    }

    return retorno;
}

void mostrarPersona(eAgenda x)
{
    printf("  %6d  %10s %10s\n",x.legajo,x.apellido,x.nombre);
}
void mostrarPersonas(eAgenda x[],int tam)
{
    printf("  Legajo    Apellido     Nombre\n");
    for(int i=0;i<tam;i++)
    {
        if(x[i].isEmpty==0)
        {
            mostrarPersona(x[i]);
        }
    }
}

int baja(eAgenda x[],int tam)
{
    int retorno=0;
    int legajo;
    int indice;
    char baja='s';

    printf("Ingrese legajo a dar de baja: ");

    if(!getNumber(&legajo))
    {
        printf("Ingrese un numero de legajo valido\n");
    }
    else
    {
        indice=buscarLegajo(x,tam,legajo);
        if(indice==-1)
        {
            printf("Lo siento, no se encuentra ese numero de legajo\n");
        }
        else
        {
            mostrarPersona(x[indice]);
            printf("Seguro desea dar de baja a esta persona?\n");
            printf("conteste s si desea darlo de baja\n");
            scanf("%c",&baja);
            if(baja=='s')
            {
                x[indice].isEmpty=1;
            }

        }
    }


    return retorno;
}
