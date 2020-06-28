#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parserAutos.h"
#include "Autos.h"
#include "UTN.h"

int parser_autosFromText(FILE* pFile , LinkedList* this)
{
    int retorno = 0;
    int cant;
    char buffer[5][128];
    eAuto* auxAuto;
    char respuesta;

    if(this != NULL){

        if(!ll_isEmpty(this)){
            utn_getCharacter(&respuesta, "Desea sobreescribir los datos cargados en el sistema? s/n: ", "Error. ", 's', 'n', 5);}

        if(respuesta == 's' || ll_isEmpty(this)){
            ll_clear(this);
            //salteamos la primer linea del archivo (titulo de las columnas, los cual ya conocemos)
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            while(!feof(pFile)){
                cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                if (cant == 5){
                    auxAuto = auto_newParametrosStr(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
                    if(auxAuto != NULL){
                        ll_add(this, auxAuto);
                        retorno = 1;
                    }
                }else{
                    retorno = 0;
                    break;
                }
            }
        }

    }
    return retorno;
}
