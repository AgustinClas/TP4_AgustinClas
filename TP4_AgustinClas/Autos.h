#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct{

    int id;
    char marca[25];
    char modelo[25];
    int anio;
    float precio;

}eAuto;

#include "LinkedList.h"

#endif // AUTOS_H_INCLUDED

/** \brief crea una estructura tipo eAuto y le asigna los valores pasados por parametros a sus campos
 *
 * \param id (tipo char*)
 * \param marca (tipo char*)
 * \param modelo (tipo char*)
 * \param anio (tipo char*)
 * \param precio (tipo char*)

 * \return estructura eAuto con los datos asignados a sus campos o NULL(en caso de que los datos pasados sean erroneos)
 *
 */
eAuto* auto_newParametrosStr(char* id, char* marca,char* modelo, char* anio, char* precio);

/** \brief crea una estructura tipo eAuto y le asigna los valores pasados por parametros a sus campos
 *
 * \param id (tipo int)
 * \param marca (tipo char*)
 * \param modelo (tipo char*)
 * \param anio (tipo int)
 * \param precio (tipo float)

 * \return estructura eAuto con los datos asignados a sus campos o NULL(en caso de que los datos pasados sean erroneos)
 *
 */
eAuto* auto_newParametros(int id, char* marca,char* modelo, int anio, float precio);

/** \brief asigna a la estructura eAuto el valor pasado por parametro en el campo correspondiente
 *
 * \param estructura eAuto
 * \param valor a guardar en el campo id
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_setId(eAuto* this,int id);

/** \brief toma el valor del campo id de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 * \param direccion de memoria donde se guardara los datos obtenidos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_getId(eAuto* this,int* id);

/** \brief asigna a la estructura eAuto el valor pasado por parametro en el campo correspondiente
 *
 * \param estructura eAuto
 * \param valor a guardar en el campo marca
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_setMarca(eAuto* this,char* marca);

/** \brief toma el valor del campo marca de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 * \param direccion de memoria donde se guardara los datos obtenidos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_getMarca(eAuto* this,char* marca);

/** \brief toma el valor del campo precio de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 * \param direccion de memoria donde se guardara los datos obtenidos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_getPrecio(eAuto* this,float* precio);

/** \brief asigna a la estructura eAuto el valor pasado por parametro en el campo correspondiente
 *
 * \param estructura eAuto
 * \param valor a guardar en el campo precio
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_setPrecio(eAuto* this,float precio);

/** \brief toma el valor del campo anio de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 * \param direccion de memoria donde se guardara los datos obtenidos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_getAnio(eAuto* this,int* anio);

/** \brief asigna a la estructura eAuto el valor pasado por parametro en el campo correspondiente
 *
 * \param estructura eAuto
 * \param valor a guardar en el campo anio
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_setAnio(eAuto* this,int anio);

/** \brief toma el valor del campo modelo de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 * \param direccion de memoria donde se guardara los datos obtenidos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_getModelo(eAuto* this,char* modelo);

/** \brief asigna a la estructura eAuto el valor pasado por parametro en el campo correspondiente
 *
 * \param estructura eAuto
 * \param valor a guardar en el campo modelo
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int auto_setModelo(eAuto* this,char* modelo);

/** \brief crea una estructura eAuto y le pido al usuario el contenido de los campos a completar (excepto el id)
 *
 * \param id de la nueva estructura
 * \return estrutura eAuto o NULL (en caso de no haberse generado correctamente);
 *
 */
eAuto* auto_Add(int id);

/** \brief muestra los autos cargados en el linkedlist de manera encolumnada
 *
 * \param linkedlist que contiene los datos a mostrar
 *
 */
void listarAutos(LinkedList* this);

/** \brief muestra los datos de la estructura eAuto pasada por parametro
 *
 * \param estructura eAuto
 *
 */

void listarAuto(eAuto* auxAuto);
