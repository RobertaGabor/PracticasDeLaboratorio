#ifndef UTN_BIBLIOTECA_H_INCLUDED
#define UTN_BIBLIOTECA_H_INCLUDED

/** \brief pide al usuario un numero entre un rango de dos numeros y lo devuelve. Si hubo un error notifica. permite elegir la cantidad de repeticiones.
 *
 * \param pResultado int* numero validado correctamente
 * \param mensaje char* mensaje que pide el numero
 * \param mensajeError char* mensaje que notifica si el numero no es valido
 * \param minimo int minimo deseado
 * \param maximo int maximo deseado
 * \param reintentos int cantidad de reintentos posibles
 * \return int devuelve si la funcion se ejecutó correctamente
 *
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif // UTN_BIBLIOTECA_H_INCLUDED
