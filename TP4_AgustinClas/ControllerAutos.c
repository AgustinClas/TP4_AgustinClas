#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ControllerAutos.h"
#include "parserAutos.h"
#include "Autos.h"
#include "LinkedList.h"
#include "UTN.h"

int controller_loadFromText(char* path , LinkedList* this)
{
    int retorno = 0;
    FILE* pFile;

    system("cls");

    if(this != NULL){
        pFile = fopen("dataAutos.csv", "r");

        if(pFile != NULL){
                //Si se pudo abrir el archivo llamamos a parser para que cargue los archivos desde el texto
                if(parser_autosFromText(pFile, this)){
                    retorno = 1;
                }
            }
        }
        fclose(pFile);

    return retorno;
}

int controller_addAuto(LinkedList* this)
{
    eAuto* auxAuto;
    char id[6];
    FILE* fileId;

    int retorno = 0;

    system("cls");
    printf("*****ANIADIR AUTO*****\n\n");

    if(this != NULL){

        fileId = fopen("UltimoId.csv", "r");
        if(fileId != NULL){
            if(fscanf(fileId, "%[^\n]", id)){ //cargamos el ultimo id desde un archivo
                fclose(fileId);
                fileId = NULL;
                fileId = fopen("UltimoId.csv", "w"); //abrimos el archivo nuevamente pero para escritura
                if(fileId != NULL){
                    fprintf(fileId,"%d\n", atoi(id) + 1); //actualizamos el valor del id
                    fclose(fileId);
                    auxAuto = auto_Add(atoi(id));

                    if(auxAuto != NULL){
                        ll_add(this, (void*) auxAuto);
                        retorno=1;
                    }
                }
            }
        }

    }
    return retorno;
}

void controller_listAutos(LinkedList* this){

    if(this != NULL){
        listarAutos(this);
    }

}

int findIndex(LinkedList* this, int id){

    eAuto* auxAuto;
    int auxId;
    int indice = -1;


    if(this != NULL){
        for(int i=0; i < ll_len(this); i++){
            auxAuto = ll_get(this, i);
            if(auxAuto != NULL){
                auto_getId(auxAuto, &auxId);
            }

            if(id == auxId){
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int controller_removeAuto(LinkedList* this)
{
    int retorno = 0;
    int index = -1;
    int id;
    char marca[25];
    char modelo[25];
    int anio;
    float precio;
    char respuesta;
    eAuto* auxAuto;

    system("cls");
    printf("*****Baja auto*****\n\n");
    if(this != NULL){
        controller_listAutos(this);
        if(!utn_getNumeroEntero(&id, "Ingrese el id del empleado que desea dar de baja: ", " Error.", 0,9999, 5)){
            index = findIndex(this, id);
        }


        if(index > -1){
            auxAuto = ll_get(this, index);
            if(auxAuto != NULL){
                auto_getMarca(auxAuto, marca);
                auto_getModelo(auxAuto, modelo);
                auto_getAnio(auxAuto, &anio);
                auto_getPrecio(auxAuto, &precio);

                printf("Id: %d\n", id);
                printf("Marca: %s\n", marca);
                printf("Modelo: %s\n", modelo);
                printf("Anio: %d\n", anio);
                printf("Precio: %.2f\n", precio);

                utn_getCharacter(&respuesta, "Seguro que desea dar de baja este empleado? s/n: ", "Error. ",'s', 'n', 5);
                if(respuesta == 's'){
                    if(ll_remove(this, index) == 0){
                        retorno = 1;
                    }
                }
            }
        }

    }

    return retorno;
}

int controller_editAutos(LinkedList* this)
{
    int index;
    int id;
    char marca[25];
    char modelo[25];
    int anio;
    float precio;
    int opcion;
    int retorno = 0;
    eAuto* autoElegido;
    eAuto* auxAuto;

    system("cls");
    printf("*****Modificar auto*****\n\n");


    if(this != NULL){
        controller_listAutos(this);
        if(!utn_getNumeroEntero(&id, "Ingrese el id del auto que desea modificar: ", " Error.", 0,9999, 5)){
            index = findIndex(this, id);
        }


        if(index > -1){
            autoElegido = ll_get(this, index);

            if(autoElegido != NULL){
                auxAuto = autoElegido;
                auto_getMarca(auxAuto, marca);
                auto_getModelo(auxAuto, modelo);
                auto_getAnio(auxAuto, &anio);
                auto_getPrecio(auxAuto, &precio);

                printf("1. Marca: %s\n", marca); //le preguntamos al usuario que campo de la estructura quiere cambiar
                printf("2. Modelo: %s\n", modelo);
                printf("3. Anio: %d\n", anio);
                printf("4. Precio: %.2f\n", precio);

                if(utn_getNumeroEntero(&opcion, "Elija una opcion: ","Error. ", 1, 4, 10) == 0){
                    switch(opcion){
                        case 1:
                            if(utn_getString(marca, "Ingrese la nueva marca: ", "Error. ", 5)==0){
                                auto_setMarca(auxAuto, marca);
                                retorno = 1;
                            }
                            break;
                        case 2:
                            if(utn_getString(modelo, "Ingrese el nuevo modelo: ", "Error. ", 5)==0){
                                auto_setModelo(auxAuto, modelo);
                                retorno = 1;
                            }
                            break;
                        case 3:
                            if(utn_getNumeroEntero(&anio, "Ingrese el nuevo anio: ", "Error. ",1930,2020, 5)==0){
                                auto_setAnio(auxAuto, anio);
                                retorno = 1;
                            }
                            break;
                        case 4:
                            if(utn_getNumeroFlotante(&precio, "Ingrese el nuevo precio: ", "Error. ",10000,1000000, 5)==0){
                                auto_setPrecio(auxAuto, precio);
                                retorno = 1;
                            }
                            break;
                    }
                }
            }
        }
    }

    if(retorno){
        ll_set(this, index, auxAuto);
    }

    return retorno;
}

int controller_recargarAutos(LinkedList* this, char* archivo){

    int retorno = 0;
    char respuesta;

    system("cls");

    if(this != NULL){

        printf("Si cometió un error al aniadir, modificar o dar de baja un empleado, puede volver a recargar los datos\n");

        utn_getCharacter(&respuesta, "Seguro que desea recargar los datos? s/n: ", "Error. ",'s', 'n', 5);
            if(respuesta == 's'){
                if(ll_clear(this) == 0 && controller_loadFromText(archivo, this)){ //usamos la funcion ll_clear para borrar los datos del linkedlist y los volvemos a cargar desde el archivo
                    retorno = 1;
                }
            }
    }

    return retorno;
}

int menuTop(){

    int opcion;

    printf("1. Crear top\n");
    printf("2. Mostrar top\n");
    printf("3. Buscar auto en el top\n");
    printf("4. Salir\n");

    utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 4, 10);

    return opcion;

}

int sortPrecio(void* auto1, void* auto2){

    int retorno;
    float precio1;
    float precio2;

    if(auto_getPrecio(auto1, &precio1) && auto_getPrecio(auto2, &precio2)){
        if(precio1 > precio2){
            retorno = 1;
        }else if(precio1 < precio2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int sortAnio(void* auto1, void* auto2){

    int retorno;
    int anio1;
    int anio2;

    if(auto_getAnio(auto1, &anio1) && auto_getAnio(auto2, &anio2)){
        if(anio1 > anio2){
            retorno = 1;
        }else if(anio1 < anio2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int sortId(void* auto1, void* auto2){

    int retorno;
    int id1;
    int id2;

    if(auto_getId(auto1, &id1) && auto_getId(auto2, &id2)){
        if(id1 > id2){
            retorno = 1;
        }else if(id1 < id2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

void controller_topAutos(LinkedList* this){

    int opcion;
    int index;
    int id;
    int indexSublist;
    LinkedList* listaTop = NULL;
    eAuto* auxAuto;

    system("cls");
    printf("*****TOP AUTOS*****\n\n");

    if(this != NULL){
        do{
            opcion = menuTop();

            switch(opcion){
                case 1:
                    listaTop = controller_crearTop(this);
                    if(listaTop != NULL ){
                        printf("Top creado correctamente\n\n");
                    }else{
                       printf("No se pudo crear el top\n\n");
                    }
                    break;
                case 2:
                    controller_listAutos(listaTop);
                    break;
                case 3:
                    if(!ll_isEmpty(listaTop)){
                        controller_listAutos(this);
                        utn_getNumeroEntero(&id, "Ingrese el id: ", " Error.", 0,9999, 5);
                        index = findIndex(this, id);
                        auxAuto = (eAuto*) ll_get(this, index);
                        system("cls");

                        if(ll_contains(listaTop, auxAuto)){ //si el archivo esta dentro del top le informamos al usuario diciendole su posicion
                            indexSublist = ll_indexOf(listaTop, auxAuto);
                            printf("Este auto forma parte del top en la posicion: %d \n", (indexSublist + 1));
                        }else{
                            printf("Este auto no forma parte del top\n");
                        }
                    }else{
                        printf("\nPrimero debe crear el top\n");
                    }
                    break;
            }
        }while(opcion != 4);
    }

    ll_deleteLinkedList(listaTop);
}

LinkedList* controller_crearTop(LinkedList* this){

    int opcion;
    int to = -1;
    LinkedList* listaTop = NULL;

    if(this != NULL){
        printf("***Crea top****\n\n");

        printf("1. Mas antiguos\n");
        printf("2. Mas caros\n");

        utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 3, 10);
        printf("Elija la cantidad de autos que quiere incluir en el top (maximo: %d)\n", ll_len(this));
        utn_getNumeroEntero(&to, "Ingrese: ", "Error. ", 1, ll_len(this), 10);

        if(opcion == 1){
            ll_sort(this, sortAnio, 1 ); //Al ser por antiguedad ordenamos de manera ascendente
            listaTop = ll_subList(this, 0, to );
        }else if(opcion == 2){
            ll_sort(this, sortPrecio, 0); //Al ser por precio ordenamos de manera descendente
            listaTop = ll_subList(this, 0, to );
        }

            ll_sort(this, sortId, 1);
    }

    return listaTop;
}

int controller_manipularLista(LinkedList* this){

    eAuto* auxAuto;
    int id;
    int index;
    int nuevoIndex;
    int retorno = 0;

    system("cls");
    if(this != NULL){
        controller_listAutos(this); //mostramos los autos para que el usuario elija cual quiere mover

        utn_getNumeroEntero(&id, "Ingrese el id: ", " Error.", 0,9999, 5);
        index = findIndex(this, id);

        auxAuto = ll_pop(this,index);
        if(auxAuto != NULL){
            utn_getNumeroEntero(&nuevoIndex, "Ingrese el nuevo lugar donde desea ingresar este auto: ", " Error.", 0,9999, 5);
            if(!ll_push(this, nuevoIndex - 1, auxAuto)){
                retorno = 1;
            }
        }
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* this)
{
    FILE* file;
    eAuto* auxAuto;
    int id;
    char marca[25];
    char modelo[25];
    int anio;
    float precio;
    int retorno = 0;


    if(this != NULL){
        file = fopen(path, "w");
        if(file != NULL){
                fprintf(file,"id,marca,modelo,anio,precio\n");
            for(int i = 0; i< ll_len(this); i++){
                auxAuto = ll_get(this, i);

                auto_getId(auxAuto, &id);
                auto_getMarca(auxAuto, marca);
                auto_getModelo(auxAuto, modelo);
                auto_getAnio(auxAuto, &anio);
                auto_getPrecio(auxAuto, &precio);

                fprintf(file,"%d,%s,%s%d,%f\n", id, marca, modelo, anio, precio);
            }
            retorno = 1;
        }
        fclose(file);
    }
    return retorno;
}
