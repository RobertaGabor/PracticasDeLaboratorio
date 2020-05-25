#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{

int id;
char nombre[30] ;
char apellido[30] ;
long double cuit;
int isEmpty;

}eClientes;


void inicializarClientes(eClientes clientes[],int tamCli);
int menu(void);
int altaCliente(int id,eClientes clientes[],int tamStruct1);
int buscarLibre(eClientes clientes[],int tamCli);
int modificarDatos(eClientes cliente[],int tamCli);
void mostrarCliente (eClientes cliente[],int indice);
int menuModificar(void);
int buscarIdCliente(int id,eClientes clientes[],int tamCli);
void bajaCliente(eClientes clientes[],int tamCli);

#endif // CLIENTES_H_INCLUDED
