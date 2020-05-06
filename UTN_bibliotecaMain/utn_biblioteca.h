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
/** \brief pide al usuario un numero entre un rango de dos numeros y lo devuelve. Si hubo un error notifica. permite elegir la cantidad de repeticiones.
 *
 * \param resultado float* numero validado correctamente
 * \param mensaje char* mensaje que pide el numero
 * \param mensajeError char* mensaje que notifica si el numero no es valido
 * \param minimo int minimo deseado
 * \param maximo int maximo deseado
 * \param reintentos int cantidad de reintentos posibles
 * \return int devuelve si la funcion se ejecutó correctamente 0 si se puedo 1 si no.
 *
 */
int utn_getNumeroFloat(float* resultado,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos);

/** \brief Pide un entero y o devuelve
 *
 * \param Mensaje de peticion
 * \return entero
 *
 */
int utn_getInt (int numero[]);
/** \brief pide un foat, lo valida, y lo devuelve
 *
 * \param numero por referencia
 * \return 0 si se pudo convertir a nunmero, 1 si no es numero
 *
 */
int utn_getFloat (float numero[]);
/** \brief Pide un char y o devuelve
 *
 * \param Mensaje de peticion
 * \return char
 *
 */
char utn_getLetra(char mensaje[]);
/** \brief Recibe un array y verifica si todos los elementos son numericos.
 *
 * \param Array a ser analizado
 * \return Devuelve 1 si es numerico o 0 si no lo es.
 *
 */
int utn_validarNumero (char vector[],int tam);
/** \brief Recibe un array y verifica si todos los elementos son letras.
 *
 * \param Array a ser analizado
 * \return Devuelve 1 si es todo letras o 0 si no lo es.
 *
 */
int utn_validarLetra (char vector[]);
/** \brief Recibe un array y verifica si todos los elementos son letras o numeros.
 *
 * \param Array a ser analizado
 * \return Devuelve 1 si es alfanumerico o 0 si tiene caracteres especiales.
 *
 */
int utn_validarAlfanumerico (char vector[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int utn_validarTelefono (char vector[]);
/** \brief Pide al usuario una cadena que no superes cierta cantidad de caracteres
 *
 * \param vector cadena de lo ingresado
 * \param tamaño de vector
 * \return void
 *
 */
int utn_scanGetInt (char ingreso[],int tam);
/** \brief Pide al usuario que inrgese un numero y valida si ingreso correctamente
 *
 * \param mensaje[] mensaje que pide el ingreso
 * \param ingreso[] vector que guarda el ingreso si se valido correctamente
 * \return int 1 si se pudo validar correctamente, 0 si ingreso mal
 *
 */
int utn_getStringNumeros(char mensaje[],char ingreso[]);
/** \brief Pide al usuario que inrgese una letra y valida si ingreso correctamente
 *
 * \param mensaje[] mensaje que pide el ingreso
 * \param ingreso[] vector que guarda el ingreso si se valido correctamente
 * \return int 1 si se pudo validar correctamente, 0 si ingreso mal
 *
 */
int utn_getStringLetras(char mensaje[],char ingreso[]);
/** \brief Pide al usuario que ingrese un array
 *
 * \param mensaje que pide el array
 * \param vector donde guardar lo ingresado por el usuario
 * \return void
 *
 */
void utn_getString (char mensaje[],char ingreso[]);
/** \brief Busca la posicion donde se encuentre el numero entero buscado
 *
 * \param tanaño del array
 * \param entero que se desea buscar
 * \return devuelve -1 si no lo encontro, sino devuelve el indice donde se encuentra
 *
 */
int utn_buscadorEspacio(int vector[],int tam,int buscado);
/** \brief Inicializa todos los indices del vectoe con un entero
 *
 * \param vector que se va a inicializar
 * \param tamañode vector
 * \entero que sera el valor de inicio
 * \return el vector ya inicializado
 *
 */
void utn_inicializadorString (int vector[],int tam,int inicio);
/** \brief Pide al usuario 2 numeros, valida que sean correctamente numeros y busca el mayor de los dos
 *
 * \param x int primer entero ingresado
 * \param y int segundo entero ingresado
 * \param mayor int* por referencia devuelve el mayor de los dos
 * \return devuelve 0 si son iguales, o 1 si uno de los dos es mayor que el otro
 *
 */
int utn_numeroMayor(int x, int y,int* mayor);
/** \brief Valida si un numero flotante esta bien inrgesado
 *
 * \param vector array de lo inrgesado
 * \return devuelve 0 si se valido correctamente, sino 1
 *
 */
int utn_validarNumeroFloat (char vector[]);
/** \brief Inicializa todo un array de floats con un numero
 *
 * \param vector de tipo float
 * \param tamaño del vector
 * \param numero inicializador
 * \return 0 si se logro inicializar -1 si no.
 *
 */
int utn_inicializadorFloat (float vector[],int tam,float inicio);
#endif // UTN_BIBLIOTECA_H_INCLUDED
