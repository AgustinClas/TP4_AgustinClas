#ifndef PARSERAUTOS_H_INCLUDED
#define PARSERAUTOS_H_INCLUDED

#include "LinkedList.h"

#endif // PARSERAUTOS_H_INCLUDED

/** \brief Parsea los datos de los autos desde el archivo data.csv (modo texto).
 *
 * \param archivo de donde leera los datos
 * \param Linkedlist donde se almacenan losdatos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int parser_autosFromText(FILE* pFile , LinkedList* this);
