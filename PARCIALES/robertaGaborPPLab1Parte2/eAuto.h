#ifndef EAUTO_H_INCLUDED
#define EAUTO_H_INCLUDED
#include "eColor.h"
#include "eMarca.h"
#include "eCliente.h"

typedef struct{

int idAuto;
char patente[20];
int idMarca;
int idColor;
int modelo;
int idCliente;
int isEmpty;

}eAuto;

/** \brief Carga un vector de tipo estructura eAuto en un indice
*
* \param vector de tipo eAuto
* \param tama�o vector de autos
* \param vector de tipo eColor
* \param tama�o vector de colores
* \param vector de tipo eMarcas
* \param tama�o vector de marcas
* \return 1 si se pudo dar de alta sino 0
 *
 */
int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
/** \brief Se elige si modificar color o modelo en un indice del vector de tipo eAuto (de un auto en particular)
 *
 * \param autos[] eAuto vector que se modifica
 * \param tamAu int tama�o del vector autos
 * \param colores[] eColor vector de colores
 * \param tamCol int tama�o vector de colores
 * \param marcas[] eMarca vector de marcas
 * \param tamMar int tama�o vector de marcas
 * \return int devuelve 1 si se pudo modificar sino 0
 *
 */
int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
/** \brief Busca el ID de auto en un vector y si lo encuentra devuelve el indice
 *
 * \param id int Id buscado
 * \param autos[] eAuto vector de autos a recorrer en la celda ID
 * \param tamAu int tama�o de vector autos
 * \return int devuelve -1 si no lo encontro sino devuelve el indice
 *
 */
int buscarAutoId(int id,eAuto autos[],int tamAu);
/** \brief muestra los datos de un indice unicamente de un vector de tipo eAuto
 *
 * \param autos eAuto variable de tipo eAuto
 * \param colores[] eColor vector de colores
 * \param tamCol int tama�o del vector colores
 * \param marcas[] eMarca vector de marcas
 * \param tamMar int tama�o dvoid mostrarAutoConFecha(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,eTrabajo trabajo[],int tamTra)
e vector marcas
 * \return void
 *
 */
void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
/** \brief Baja logica de un auto, pide patente y si la encuentra convierte la celda isEmpty en 1
 *
 * \param autos[] eAuto vector autos
 * \param tamAu int tama�o de vector autos
 * \param colores[] eColor vector de colores
 * \param tamCol int tama�o de vector colores
 * \param marcas[] eMarca vector marcas
 * \param tamMar int taa�o vector marcas
 * \return void
 *
 */
void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
/** \brief Muestra los datos de todos los autos disponibles con isEmpty en 0
 *
 * \param vector tipo eAuto de autos
 * \param tama�o de vector autos
 * \param vector tipo eColor de colores
 * \param tama�o de vector colores
 * \param vector tipo eMarca de marcas
 * \param tama�o de vector marcas
 * \return void
 *
 */
void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
/** \brief ordena el vector autos por marca y por patente
 *
 * \param vector autos de estructura eAuto
 * \param tama�o de vector autos
 * \param vector de marcas tipo estructura eMarcas
 * \param tama�o de vector marcas
 * \return void
 *
 */
void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar);
/** \brief Menu del case modificarDatosAuto
 *
 * \param void
 * \return int devuelve el case elegido
 *
 */
int menuDeCambiosAuto(void);
/** \brief pide una patente, busca si se encuentra en el vector de tipo eAuto, si la encuentra devuelve el indice
 *
 * \param patente[] char cadena patente buscada
 * \param autos[] eAuto vector tipo eAuto a analizar
 * \param tamAu int tama�o de vector auto
 * \return int devuelve -1 si no lo encontro sino el indice
 *
 */
int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu);
/** \brief busca un espacio libre en el array de autos en la celda isEmpty=1
 *
 * \param autos[] eAuto vector autos a analizar
 * \param tamAu int tama�o de vector autos
 * \return int devuelve el indice si encuentra libre, sino -1
 *
 */
int buscarLibre(eAuto autos[],int tamAu);
/** \brief inicializa un array de tipo eAuto en la celda isEmpty en 1
 *
 * \param autos[] eAuto vector a inicializar
 * \param tamAu int tama�o del vector
 * \return void
 *
 */
void inicializarAutos(eAuto autos[],int tamAu);
/** \brief Busca que en el vector de tipo eAuto haya almenos uno cargado
 *
 * \param autos[] eAuto vector de autos
 * \param tamAu int tama�o de vector de autos
 * \return int devuelve 1 si encontro al menos uno sino 0
 *
 */
int buscarUnaCarga(eAuto autos[],int tamAu);
#endif // EAUTO_H_INCLUDED
