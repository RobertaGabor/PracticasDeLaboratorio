#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILA 200
#define COLUMNA 25
/*1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido*/
int buscadorEspacio(int vector[],int tam,int buscado);
void inicializadorString (int vector[],int tam,int inicio);
int utn_validarNumero (char vector[]);
int utn_validarLetra (char vector[]);
int getStringNumeros(char mensaje[],char ingreso[]);
int getStringLetras(char mensaje[],char ingreso[]);
void getString (char mensaje[],char ingreso[]);
int menuOpciones(void);
int main()
{

    char nombreAuxiliar[COLUMNA];
    char apellidoAuxiliar[COLUMNA];
    char legajoAuxiliar[COLUMNA];
    int legajoValidado;
    char vectorNombre[FILA][COLUMNA];
    char vectorApellido[FILA][COLUMNA];
    int vectorLegajo[FILA];//enterono necesita cantidad de caracteres
    int opcionMenu;
    int indiceEncontrado;
    int band=0;

    inicializadorString(vectorLegajo,FILA,-1);
     do
    {
        opcionMenu=menuOpciones();
        switch(opcionMenu)
        {
        case 1:
            indiceEncontrado=buscadorEspacio(vectorLegajo,FILA,-1);
            if(indiceEncontrado==-1)
            {
                printf("No hay espacio disponible\n");
                break;
            }
            else
            {
               if(getStringLetras("Ingrese un nombre:\n",nombreAuxiliar)!=1)
               {
                   printf("Ingrese un nombre valido, sin numeros o caracteres especiales\n");
                   break;
               }//antes de asignarlo el otro en i, verifico que lo otro este correcto, y el legajo sin ocupar.
               /*primero ingreso todo en auxiliar, y verifico que este validado*/
               if(getStringLetras("Ingrese un apellido:\n",apellidoAuxiliar)!=1)
               {
                   printf("Ingrese un apellido valido, sin numeros o caracteres especiales\n");
                   break;
               }
               if(getStringNumeros("Ingrese el numero de legajo:\n",legajoAuxiliar)!=1)
               {
                   printf("Ingrese un legajo valido, sin letras o caracteres especiales\n");
                   break;//si esta mal sale a menu para volver a ingresar
               }
               /*si se pudo ingresar el legajo sin salir con break, lo convertirmo a int*/
               legajoValidado=atoi(legajoAuxiliar);

               if(buscadorEspacio(vectorLegajo,FILA,legajoValidado)!=-1)
               {
                   printf("El legajo ya esta en uso\n");
                   break;
               }

               vectorLegajo[indiceEncontrado]=legajoValidado;//un vector si se comparar con un int
               strcpy(vectorNombre[indiceEncontrado],nombreAuxiliar);//strcpy es para dos vectores nada mas
               strcpy(vectorApellido[indiceEncontrado],apellidoAuxiliar);
            }
            break;
        case 2:
            if(!getStringNumeros("Ingrese legajo a dar de baja:\n",legajoAuxiliar))
            {
                printf("Ingrese un legajo valido, sin letras o caracteres especiales\n");
                break;
            }
            legajoValidado=atoi(legajoAuxiliar);

            indiceEncontrado=buscadorEspacio(vectorLegajo,FILA,legajoValidado);
            if(indiceEncontrado==-1)
            {
                printf("Legajo no encontrado\n");
                break;
            }
            else
            {
                vectorLegajo[indiceEncontrado]=-1;
                break;
            }

            break;
        case 3:
            if(!getStringNumeros("Ingrese el legajo de la persona que desea modificar los datos:\n",legajoAuxiliar))
            {
                printf("Ingrese un legajo valido, sin letras o caracteres especiales\n");
                break;
            }

            legajoValidado=atoi(legajoAuxiliar);
            indiceEncontrado=buscadorEspacio(vectorLegajo,FILA,legajoValidado);//devuelve el indice en que esta posicionado
            if(indiceEncontrado==-1)
            {
                printf("Legajo no encontrado\n");
                break;
            }
            else
            {
                if(!getStringLetras("Ingrese un nuevo nombre:\n",nombreAuxiliar))
               {
                   printf("Ingrese un nombre valido, sin numeros o caracteres especiales\n");
                   break;
               }

               if(!getStringLetras("Ingrese un nuevo apellido:\n",apellidoAuxiliar))
               {
                   printf("Ingrese un apellido valido, sin numeros o caracteres especiales\n");
                   break;
               }
            }

            strcpy(vectorApellido[indiceEncontrado],apellidoAuxiliar);
            strcpy(vectorNombre[indiceEncontrado],nombreAuxiliar);

            break;
        case 4:
            for(int i=0;i<FILA;i++)
            {
                if(vectorLegajo[i]!=-1)
                {
                    band=1;
                    break;
                }
            }
            if(band==0)
            {
                printf("Vector aun sin cargar\n");
                break;
            }
            else
            {
                for(int i=0; i<FILA; i++)
                {
                    if(vectorLegajo[i]!=-1)
                    {
                        printf("%s |  %s | %d\n",vectorApellido[i],vectorNombre[i],vectorLegajo[i]);//siempre mostrar en i para mostrar lo de la posicion
                    }
                }
                band=0;
            }

            break;
        case 5:
            for(int i=0;i<FILA;i++)
            {
                if(vectorLegajo[i]!=-1)
                {
                    band=1;
                    break;
                }
            }
            if(band==0)
            {
                printf("Vector aun sin cargar\n");
                break;
            }
            else
            {
                for(int i=0;i<FILA-1;i++)
                {
                    for(int j=i+1;j<FILA;j++)
                    {
                        if((strcmp(vectorApellido[i],vectorApellido[j]))&&vectorLegajo[j]!=-1)
                        {
                            strcpy(nombreAuxiliar,vectorNombre[i]);//siempre que queres asignar un vector con otro usar strcpy
                            strcpy(vectorNombre[i],vectorNombre[j]);
                            strcpy(vectorNombre[j],nombreAuxiliar);

                            strcpy(apellidoAuxiliar,vectorApellido[i]);
                            strcpy(vectorApellido[i],vectorApellido[j]);
                            strcpy(vectorApellido[j],apellidoAuxiliar);

                            legajoValidado=vectorLegajo[i];
                            vectorLegajo[i]=vectorLegajo[j];
                            vectorLegajo[j]=legajoValidado;

                        }
                    }
                }
            }

            band=0;
            break;
        case 6:
        default:
            printf("Ingrese una opcion valida\n");
            break;

        }
    }while(opcionMenu!=6);

    return 0;
}

int menuOpciones(void)
{
    int opcion;
    printf("___Menu de opciones___\n");
    printf("1-Alta de una persona\n");
    printf("2-Baja de una persona\n");
    printf("3-Modificar datos de una persona\n");
    printf("4-Mostrar lista\n");
    printf("5-Ordenar lista\n");
    printf("6-Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

void getString (char mensaje[],char ingreso[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",ingreso);
}

/** \brief pide una cadena y la devuelve
 *
 * \param mensaje[] char mensaje a mostrar
 * \param ingreso[] char validacion de lo ingresado
 * \return int 1 si la cadena contiene solo texto
 *
 */
int getStringLetras(char mensaje[],char ingreso[])
{
    int retorno=0;
    char auxiliar[1000];
    getString(mensaje,auxiliar);
    if(utn_validarLetra(auxiliar)==1)
    {
        strcpy(ingreso,auxiliar);
        retorno=1;
    }
    return retorno ;
}

int utn_validarLetra (char vector[])
{
    int retorno=1;

    for(int i=0;vector[i]!='\0';i++)
    {
        if(vector[i]!=' '&&(vector[i]<'a'||vector[i]>'z')&&(vector[i]<'A'||vector[i]>'Z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief Verifica si un array esta compuesto por solo numeros
 *
 * \param mensaje[] char Mensaje que pide el ingreso
 * \param ingreso[] char array que guarda lo ingresado en caso de que sea solo numeros
 * \return int devuelve 0 si no es un numero, 1 si es solo de numeros.
 *
 */
int getStringNumeros(char mensaje[],char ingreso[])
{
    int retorno=0;
    char auxiliar[1000];
    getString(mensaje,auxiliar);
    if(utn_validarNumero(auxiliar)==1)
    {
        strcpy(ingreso,auxiliar);
        retorno=1;
    }
    return retorno ;
}
int utn_validarNumero (char vector[])
{
    int retorno=1;
    int i=0;
    if(vector[0]=='-')
    {
        i=1;
    }

    for(;vector[i]!='\0';i++)
    {
        if(vector[i]<'0'||vector[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief Inicializa un string en todas las posiciones
 *
 * \param Vector a inicializar
 * \param tamaño del vector
 * \param numero a ser incializado
 * \return void
 *
 */
void inicializadorString (int vector[],int tam,int inicio)
{
    for(int i=0;i<tam;i++)
    {
        vector[i]=inicio;
    }
}

int buscadorEspacio(int vector[],int tam,int buscado)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==buscado)
        {
            retorno=i;//Para despues saber la posicion en la que esta lo buscado
            break;
        }
    }

    return retorno;
}
