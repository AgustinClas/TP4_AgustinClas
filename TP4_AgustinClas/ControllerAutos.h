#ifndef CONTROLLERAUTOS_H_INCLUDED
#define CONTROLLERAUTOS_H_INCLUDED

#include "LinkedList.h"

#endif // CONTROLLERAUTOS_H_INCLUDED

/** \brief Parsea los datos de los autos desde el archivo data.csv (modo texto).
 *
 * \param nombre del archivo de donde leera los datos
 * \param Linkedlist donde se almacenan los datos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_loadFromText(char* path , LinkedList* this);

/** \brief agrega un elemento al linkedlist
 *
 * \param Linkedlist donde se agrega el nuevo elemento
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int controller_addAuto(LinkedList* this);

/** \brief muestra los elementos (autos) del linkedlist en forma encolumnada
 *
 * \param linkedlist que contiene los elementos a mostrar
 */

void controller_listAutos(LinkedList* this);

/** \brief elimina un elemento (auto) del linkedlist
 *
 * \param linkedlist, el cual contiene los elementos
 * \return 1 en caso de exito y 0 en caso de error
 */
int controller_removeAuto(LinkedList* this);

/** \brief permite modificar un elemento del linkedlist
 *
 * \param linkedlist de donde se seleccionara y modificara el elemento
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_editAutos(LinkedList* this);

/** \brief borra los elementos del sistema y los carga nuevamente desde el archivo
 *
 * \param nombre del archivo de donde leera los datos
 * \param Linkedlist donde se almacenan los datos a borrar
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_recargarAutos(LinkedList* this, char* archivo);

/** \brief sub-menu que permite crear una sublist del linkedlist principal con distintos criterios
 *
 * \param linkedlist principal
 *
 */
void controller_topAutos(LinkedList* this);

/** \brief crea una sublist de los autos mas antiguos o mas caros del linkedlist principal
 *
 * \param linkedList principal
 * \return sublist creada
 *
 */
LinkedList* controller_crearTop(LinkedList* this);

/** \brief funcion auxiliar para ordenar autos segun anio
 *
 * \param puntero a auto
 * \param puntero a auto
 * \return 1 si el primer precio es mayor, 0 si son iguales y -1 si el segundo es mayor
 *
 */
int sortAnio(void* auto1, void* auto2);

/** \brief funcion auxiliar para ordenar autos segun precio
 *
 * \param puntero a auto
 * \param puntero a auto
 * \return 1 si el primer precio es mayor, 0 si son iguales y -1 si el segundo es mayor
 *
 */
int sortPrecio(void* auto1, void* auto2);

/** \brief funcion auxiliar para ordenar autos segun id
 *
 * \param puntero a auto
 * \param puntero a auto
 * \return 1 si el primer id es mayor, 0 si son iguales y -1 si el segundo es mayor
 *
 */
int sortId(void* auto1, void* auto2);

/** \brief submenu utilizado para elegir entre las funciones de controller_topAutos()
 *
 * \return opcion elegida por el usuario
 *
 */

int menuTop();

/** \brief permite mover objetos de la lista, quitandolos de su posicion y asignandolos donde quiera el usuario
 *
 * \param linkedlist que contiene los elementos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int controller_manipularLista(LinkedList* this);

/** \brief guarda la linkedlist en el archivo (modo texto)
 *
 * \param nombre del archivo
 * \param linkedlist que contiene los datos que seran guardados
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int controller_saveAsText(char* path , LinkedList* this);
